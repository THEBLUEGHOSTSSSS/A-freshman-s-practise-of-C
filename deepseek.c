#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// 游戏窗口尺寸
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// 玩家飞机结构
typedef struct {
    int x, y;       // 位置
    int width, height;
    int speed;      // 移动速度
    BOOL active;    // 是否存活
} Player;

// 子弹结构
typedef struct {
    int x, y;
    int speed;
    BOOL active;
} Bullet;

// 敌机结构
typedef struct {
    int x, y;
    int speed;
    int type;       // 敌机类型
    BOOL active;
} Enemy;

// 全局变量
Player player;
Bullet bullets[50];     // 子弹数组
Enemy enemies[30];      // 敌机数组
int score = 0;          // 得分
BOOL gameover = FALSE;  // 游戏结束标志

// 初始化游戏
void InitGame() {
    // 初始化玩家
    player.x = WIN_WIDTH / 2;
    player.y = WIN_HEIGHT - 50;
    player.width = 40;
    player.height = 40;
    player.speed = 8;
    player.active = TRUE;

    // 初始化子弹
    int i;
    for (i = 0; i < 50; i++) {
        bullets[i].active = FALSE;
    }

    // 初始化敌机
    for (i = 0; i < 30; i++) {
        enemies[i].active = FALSE;
    }

    score = 0;
    gameover = FALSE;
    
    srand((unsigned)time(NULL));  // 随机数种子
}

// 绘制游戏
void DrawGame(HDC hdc) {
    HBRUSH hBrush, hOldBrush;
    HPEN hPen, hOldPen;
    int i;
    
    // 绘制背景
    hBrush = CreateSolidBrush(RGB(0, 0, 64));
    hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);

    // 绘制玩家飞机
    if (player.active) {
        hBrush = CreateSolidBrush(RGB(0, 255, 0));
        hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
        hPen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
        hOldPen = (HPEN)SelectObject(hdc, hPen);
        
        // 简单的三角形飞机
        POINT plane[3];
        plane[0].x = player.x;
        plane[0].y = player.y - player.height/2;
        plane[1].x = player.x - player.width/2;
        plane[1].y = player.y + player.height/2;
        plane[2].x = player.x + player.width/2;
        plane[2].y = player.y + player.height/2;
        Polygon(hdc, plane, 3);
        
        SelectObject(hdc, hOldBrush);
        SelectObject(hdc, hOldPen);
        DeleteObject(hBrush);
        DeleteObject(hPen);
    }

    // 绘制子弹
    hBrush = CreateSolidBrush(RGB(255, 255, 0));
    hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    for (i = 0; i < 50; i++) {
        if (bullets[i].active) {
            Ellipse(hdc, bullets[i].x - 3, bullets[i].y - 8, 
                    bullets[i].x + 3, bullets[i].y + 8);
        }
    }
    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);

    // 绘制敌机
    for (i = 0; i < 30; i++) {
        if (enemies[i].active) {
            hBrush = CreateSolidBrush(RGB(255, 0, 0));
            hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
            Rectangle(hdc, enemies[i].x - 15, enemies[i].y - 10, 
                     enemies[i].x + 15, enemies[i].y + 10);
            SelectObject(hdc, hOldBrush);
            DeleteObject(hBrush);
        }
    }

    // 绘制分数
    char scoreText[50];
    sprintf(scoreText, "Score: %d", score);
    SetTextColor(hdc, RGB(255, 255, 255));
    SetBkMode(hdc, TRANSPARENT);
    TextOut(hdc, 10, 10, scoreText, strlen(scoreText));

    // 游戏结束提示
    if (gameover) {
        char gameOverText[] = "GAME OVER! Press R to restart";
        SetTextColor(hdc, RGB(255, 0, 0));
        TextOut(hdc, WIN_WIDTH/2 - 100, WIN_HEIGHT/2, gameOverText, strlen(gameOverText));
    }
}

// 发射子弹
void FireBullet() {
    int i;
    for (i = 0; i < 50; i++) {
        if (!bullets[i].active) {
            bullets[i].x = player.x;
            bullets[i].y = player.y - player.height/2;
            bullets[i].speed = 12;
            bullets[i].active = TRUE;
            break;
        }
    }
}

// 生成敌机
void GenerateEnemy() {
    int i;
    for (i = 0; i < 30; i++) {
        if (!enemies[i].active) {
            enemies[i].x = rand() % (WIN_WIDTH - 30) + 15;
            enemies[i].y = -20;
            enemies[i].speed = rand() % 3 + 2;
            enemies[i].type = 1;
            enemies[i].active = TRUE;
            break;
        }
    }
}

// 更新游戏逻辑
void UpdateGame() {
    int i, j;
    
    if (gameover) return;

    // 更新子弹位置
    for (i = 0; i < 50; i++) {
        if (bullets[i].active) {
            bullets[i].y -= bullets[i].speed;
            if (bullets[i].y < 0) {
                bullets[i].active = FALSE;
            }
        }
    }

    // 更新敌机位置
    for (i = 0; i < 30; i++) {
        if (enemies[i].active) {
            enemies[i].y += enemies[i].speed;
            if (enemies[i].y > WIN_HEIGHT) {
                enemies[i].active = FALSE;
            }
        }
    }

    // 碰撞检测：子弹 vs 敌机
    for (i = 0; i < 50; i++) {
        if (bullets[i].active) {
            for (j = 0; j < 30; j++) {
                if (enemies[j].active) {
                    if (abs(bullets[i].x - enemies[j].x) < 20 && 
                        abs(bullets[i].y - enemies[j].y) < 15) {
                        bullets[i].active = FALSE;
                        enemies[j].active = FALSE;
                        score += 10;
                    }
                }
            }
        }
    }

    // 碰撞检测：玩家 vs 敌机
    if (player.active) {
        for (i = 0; i < 30; i++) {
            if (enemies[i].active) {
                if (abs(player.x - enemies[i].x) < 25 && 
                    abs(player.y - enemies[i].y) < 25) {
                    player.active = FALSE;
                    gameover = TRUE;
                }
            }
        }
    }

    // 随机生成敌机
    if (rand() % 100 < 3) {  // 3%的几率每帧生成敌机
        GenerateEnemy();
    }
}

// 窗口过程函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            InitGame();
            SetTimer(hwnd, 1, 16, NULL);  // 约60FPS
            break;
            
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            DrawGame(hdc);
            EndPaint(hwnd, &ps);
            break;
        }
            
        case WM_TIMER:
            UpdateGame();
            InvalidateRect(hwnd, NULL, FALSE);
            break;
            
        case WM_KEYDOWN:
            switch (wParam) {
                case VK_LEFT:
                    if (player.x > player.width/2) 
                        player.x -= player.speed;
                    break;
                case VK_RIGHT:
                    if (player.x < WIN_WIDTH - player.width/2) 
                        player.x += player.speed;
                    break;
                case VK_UP:
                    if (player.y > player.height/2) 
                        player.y -= player.speed;
                    break;
                case VK_DOWN:
                    if (player.y < WIN_HEIGHT - player.height/2) 
                        player.y += player.speed;
                    break;
                case VK_SPACE:
                    FireBullet();
                    break;
                case 'R':
                case 'r':
                    if (gameover) InitGame();
                    break;
                case VK_ESCAPE:
                    PostQuitMessage(0);
                    break;
            }
            InvalidateRect(hwnd, NULL, FALSE);
            break;
            
        case WM_DESTROY:
            KillTimer(hwnd, 1);
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 主函数 - 修正未使用参数警告
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 使用UNREFERENCED_PARAMETER宏消除未使用参数的警告
    (void)hPrevInstance;  // 或者使用 UNREFERENCED_PARAMETER(hPrevInstance);
    (void)lpCmdLine;      // 同样处理lpCmdLine参数
    
    const char CLASS_NAME[] = "ThunderFighter";
    
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClass(&wc);
    
    // 计算窗口大小（包含边框和标题栏）
    RECT rect = {0, 0, WIN_WIDTH, WIN_HEIGHT};
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, FALSE);
    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;
    
    // 创建窗口
    HWND hwnd = CreateWindow(
        CLASS_NAME,
        "雷霆战机",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        windowWidth, windowHeight,
        NULL, NULL, hInstance, NULL
    );
    
    if (hwnd == NULL) {
        return 0;
    }
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // 消息循环
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}
