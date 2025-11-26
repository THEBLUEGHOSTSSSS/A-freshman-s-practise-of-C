#include <stdio.h>
#include <string.h>

#define NUM_CANDIDATES 3

// 定义候选人结构体
struct Candidate {
    char name[20]; // 存储候选人姓名
    int votes;     // 存储得票数
};

// 函数：根据选票名字查找候选人并增加得票数
void addVote(struct Candidate candidates[], int numCandidates, const char *votedName) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        // 使用 strcmp 比较字符串，返回 0 表示相等
        if (strcmp(candidates[i].name, votedName) == 0) {
            candidates[i].votes++;
            return; // 找到并投票后立即退出函数
        }
    }
    // 如果循环结束仍未找到匹配的候选人，则视为无效票
}

int main() {
    // 定义并初始化三个候选人
    struct Candidate candidates[NUM_CANDIDATES] = {
        {"Li", 0},
        {"Zhang", 0},
        {"Sun", 0}
    };

    int totalVotes;
    char voteName[20]; // 用于存储每次投票输入的候选人姓名
    int i;

    // BEGIN
    if (scanf("%d", &totalVotes) != 1) {
        return 1; 
    }

    for (i = 0; i < totalVotes; i++) {
        if (scanf("%s", voteName) != 1) {
            break; 
        }
        
        addVote(candidates, NUM_CANDIDATES, voteName);
    }
    // END

    // 输出结果
    printf("Li: %d\n", candidates[0].votes);
    printf("Zhang: %d\n", candidates[1].votes);
    printf("Sun: %d\n", candidates[2].votes);

    return 0;
}
