#include <stdio.h>

int main(){
    const char names[4][30] = {
        "Dickson",
        "Wilson",
        "Thomas",
        "Heigen"
    };

    int tickets[5][4];
    int sums[4] = {0};
    int sum = 0;
    double averages[4];
    int i, j;

    FILE *fp = fopen("Q2.txt", "r");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++){
            fscanf(fp, "%d", &tickets[i][j]);
            sums[j] += tickets[i][j];
            sum += tickets[i][j];
        }
    }

    for(i = 0; i < 4; i++)
        averages[i] = (double)sums[i] / sum;
    
    for(i = 0; i < 4; i++)
        printf("%s\t", names[i]);
    printf("\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 4; j++)
            printf("%d\t", tickets[i][j]);
        printf("\n");
    }
    printf("\n");

    for(i = 0; i < 4; i++)
        printf("%d\t", sums[i]);
    printf("\n");

    for(i = 0; i < 4; i++)
        printf("%.4lf\t", averages[i]);
    printf("\n");

    
    int check = -1;
    for(i = 0; i < 4; i++){
        if(averages[i] >= 0.5){
            check = i;
        }
    }

    if(check == -1){
        double max = 0.0;
        int check1 = -1, check2 = -1;
        for(i = 0; i < 4; i++){
            if(averages[i] >= max){
                check1 = i;
                max = averages[i];
            }
        }

        averages[check1] = 0.0;
        max = 0.0;

        for(i = 0; i < 4; i++){
            if(averages[i] >= max){
                check2 = i;
                max = averages[i];
            }
        }

        printf("%s\t%s\n", names[check1], names[check2]);
    }
    else {
        printf("%s\n", names[check]);
    }


    return 0;
}