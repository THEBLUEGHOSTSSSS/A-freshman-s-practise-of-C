#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"
#define BROWN   "\033[38;5;130m"
#define RESET   "\033[0m"

int main() {
    int height, i, j, k;
    
    srand(time(NULL));
    
    printf("type the height of ur tree:");
    scanf("%d", &height);
    
    printf("\n");
        for (j = 1; j <= height; j++) {
        printf(" ");
    }
    printf(YELLOW " * \n" RESET);
    

    for (i = 1; i <= height; i++) {
    
        for (j = 1; j <= height - i; j++) {
            printf(" ");
        }
        
        
        for (k = 1; k <= (2 * i - 1); k++) {
        
            int decor_chance = rand() % 10; 
            
            if (decor_chance == 0 && i > height/4) {
               
                int color = rand() % 6;
                switch(color) {
                    case 0: printf(RED "O" RESET); break;
                    case 1: printf(BLUE "O" RESET); break;
                    case 2: printf(YELLOW "O" RESET); break;
                    case 3: printf(MAGENTA "O" RESET); break;
                    case 4: printf(CYAN "O" RESET); break;
                    default: printf(WHITE "O" RESET);
                }
            } else {
                
                if (i <= height/3) {
                    printf(GREEN "*" RESET);
                } else if (i <= height*2/3) {
                    printf("\033[0;32m#" RESET);  
                } else {
                    printf("\033[1;32m*" RESET);
                }
            }
        }
        printf("\n");
    }
    
    
    int trunk_height = height / 3;
    if (trunk_height < 1) trunk_height = 1;
    
    int trunk_width = 3; 
    
    for (i = 1; i <= trunk_height; i++) {
        
        for (j = 1; j <= height - trunk_width/2; j++) {
            printf(" ");
        }
        
        for (k = 1; k <= trunk_width; k++) {
            printf(BROWN "|" RESET);
        }
        printf("\n");
    }
    
    
    printf("\n");
    for (j = 1; j <= height - 2; j++) {
        printf(" ");
    }
    printf(RED "[---]" RESET BLUE "[---]\n" RESET);
    
    for (j = 1; j <= height - 2; j++) {
        printf(" ");
    }
    printf(BLUE "[---]" RESET RED "[---]\n" RESET);
    
   
    printf("\n");
    printf(RED "    *" RESET);
    printf(GREEN "Merry Chrismas JI BA HOU" RESET);
    printf(RED "*\n" RESET);
    
    return 0;
}             