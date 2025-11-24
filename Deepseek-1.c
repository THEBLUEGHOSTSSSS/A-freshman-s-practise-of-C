#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define WIDTH 60
#define HEIGHT 20

typedef struct {
    int x, y;
    bool active;
} Player;

typedef struct {
    int x, y;
    bool active;
} Bullet;

typedef struct {
    int x, y;
    bool active;
} Enemy;

Player player;
Bullet bullets[10];
Enemy enemies[10];
int score = 0;
bool gameover = false;

// 非阻塞输入函数
int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void initGame() {
    player.x = WIDTH / 2;
    player.y = HEIGHT - 2;
    player.active = true;

    for(int i = 0; i < 10; i++) {
        bullets[i].active = false;
        enemies[i].active = false;
    }

    score = 0;
    gameover = false;
    srand(time(NULL));
}

void drawGame() {
    // 清屏
    system("clear");

    // 绘制游戏区域边框
    for(int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for(int y = 0; y < HEIGHT; y++) {
        printf("#");
        for(int x = 0; x < WIDTH; x++) {
            bool drawn = false;

            // 绘制玩家
            if(player.active && x == player.x && y == player.y) {
                printf("A");
                drawn = true;
            }

            // 绘制子弹
            if(!drawn) {
                for(int i = 0; i < 10; i++) {
                    if(bullets[i].active && x == bullets[i].x && y == bullets[i].y) {
                        printf("|");
                        drawn = true;
                        break;
                    }
                }
            }

            // 绘制敌机
            if(!drawn) {
                for(int i = 0; i < 10; i++) {
                    if(enemies[i].active && x == enemies[i].x && y == enemies[i].y) {
                        printf("V");
                        drawn = true;
                        break;
                    }
                }
            }

            if(!drawn) printf(" ");
        }
        printf("#\n");
    }

    for(int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    printf("Score: %d\n", score);
    if(gameover) {
        printf("GAME OVER! Press 'r' to restart or 'q' to quit\n");
    } else {
        printf("Controls: A/D to move, Space to shoot, Q to quit\n");
    }
}

void fireBullet() {
    for(int i = 0; i < 10; i++) {
        if(!bullets[i].active) {
            bullets[i].x = player.x;
            bullets[i].y = player.y - 1;
            bullets[i].active = true;
            break;
        }
    }
}

void createEnemy() {
    for(int i = 0; i < 10; i++) {
        if(!enemies[i].active) {
            enemies[i].x = rand() % WIDTH;
            enemies[i].y = 1;
            enemies[i].active = true;
            break;
        }
    }
}

void updateGame() {
    if(gameover) return;

    // 更新子弹
    for(int i = 0; i < 10; i++) {
        if(bullets[i].active) {
            bullets[i].y--;
            if(bullets[i].y < 0) {
                bullets[i].active = false;
            }
        }
    }

    // 更新敌机
    for(int i = 0; i < 10; i++) {
        if(enemies[i].active) {
            enemies[i].y++;
            if(enemies[i].y >= HEIGHT) {
                enemies[i].active = false;
            }
        }
    }

    // 碰撞检测：子弹 vs 敌机
    for(int i = 0; i < 10; i++) {
        if(bullets[i].active) {
            for(int j = 0; j < 10; j++) {
                if(enemies[j].active) {
                    if(bullets[i].x == enemies[j].x && bullets[i].y == enemies[j].y) {
                        bullets[i].active = false;
                        enemies[j].active = false;
                        score += 10;
                    }
                }
            }
        }
    }

    // 碰撞检测：玩家 vs 敌机
    if(player.active) {
        for(int i = 0; i < 10; i++) {
            if(enemies[i].active) {
                if(player.x == enemies[i].x && player.y == enemies[i].y) {
                    player.active = false;
                    gameover = true;
                }
            }
        }
    }

    // 随机生成敌机
    if(rand() % 100 < 10) { // 10%几率生成敌机
        createEnemy();
    }
}

int main() {
    initGame();

    printf("雷霆战机 - 控制台版本\n");
    printf("控制说明:\n");
    printf("  A/D  - 左右移动\n");
    printf("  空格 - 发射子弹\n");
    printf("  R    - 重新开始游戏\n");
    printf("  Q    - 退出游戏\n");
    printf("按任意键开始游戏...");
    getchar();

    while(1) {
        drawGame();
        updateGame();

        // 非阻塞输入检测
        if(kbhit()) {
            char ch = getchar();
            switch(ch) {
                case 'a':
                case 'A':
                    if(player.x > 0) player.x--;
                    break;
                case 'd':
                case 'D':
                    if(player.x < WIDTH - 1) player.x++;
                    break;
                case ' ':
                    fireBullet();
                    break;
                case 'r':
                case 'R':
                    if(gameover) initGame();
                    break;
                case 'q':
                case 'Q':
                    printf("游戏结束！最终得分: %d\n", score);
                    return 0;
            }
        }

        // 控制游戏速度
        usleep(100000); // 100ms
    }

    return 0;
}