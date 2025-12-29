#include <stdio.h>
#include <string.h>

// 定义候选人结构体
struct Candidate {
    char name[20];  // 候选人姓名
    int votes;      // 得票数
};

int main() {
    // 初始化三个候选人
    struct Candidate candidates[3] = {
        {"Li", 0},
        {"Zhang", 0},
        {"Sun", 0}
    };
    
    int voterCount;
    char vote[20];
    
    // 获取选民人数
    printf("Please enter the numebr of voters:");
    scanf("%d", &voterCount);
    
    // 统计投票12222222222222222222222
    for (int i = 0; i < voterCount; i++) {
        printf("VOTER%d,VOTE(Li/Zhang/Sun):", i + 1);
        scanf("%s", vote);
        
        // 检查投票并计数
        if (strcmp(vote, "Li") == 0) {
            candidates[0].votes++;
        } else if (strcmp(vote, "Zhang") == 0) {
            candidates[1].votes++;
        } else if (strcmp(vote, "Sun") == 0) {
            candidates[2].votes++;
        } else {
            printf("Not a voting!\n");
            i--;  // 重新投票
        }
    }
    
    // 输出投票结果
    printf("\nResult:\n");
    printf("-------------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d:\n", candidates[i].name, candidates[i].votes);
    }
    
    // 找出获胜者
    int maxVotes = 0;
    int winnerIndex = -1;
    
    for (int i = 0; i < 3; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }
    
    // 检查是否有平局
    int tieCount = 0;
    for (int i = 0; i < 3; i++) {
        if (candidates[i].votes == maxVotes) {
            tieCount++;
        }
    }
    
    printf("-------------------\n");
    if (tieCount > 1) {
        printf("The following people get the same\n");
        for (int i = 0; i < 3; i++) {
            if (candidates[i].votes == maxVotes) {
                printf("%s ", candidates[i].name);
            }
        }
        printf("\n");
    } else {
        printf("Winner:%s,gets %d voting\n", candidates[winnerIndex].name, maxVotes);
    }
    
    return 0;
}