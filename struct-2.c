#include <stdio.h>
#include <string.h>


struct Candidate {
    char name[20]; 
    int votes;     
};


void addVote(struct Candidate candidates[], int numCandidates, const char *votedName) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        
        if (strcmp(candidates[i].name, votedName) == 0) {
            candidates[i].votes++;
            return; 
        }
    }
    
}

#define NUM_CANDIDATES 3

int main() {
    
    struct Candidate candidates[NUM_CANDIDATES] = {
        {"Li", 0},
        {"Zhang", 0},
        {"Sun", 0}
    };

    int totalVotes;
    char voteName[20]; 
    int i;

    
    if (scanf("%d", &totalVotes) != 1) {
        return 1; 
    }

   
    for (i = 0; i < totalVotes; i++) {
        if (scanf("%s", voteName) != 1) {
            break; 
        }
        
        
        addVote(candidates, NUM_CANDIDATES, voteName);
    }

   
    printf("Li:%d\n", candidates[0].votes);
    printf("Zhang:%d\n", candidates[1].votes);
    printf("Sun:%d\n", candidates[2].votes);

    

    return 0;
}