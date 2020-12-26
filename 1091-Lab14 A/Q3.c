#include<stdio.h>

int getScore(char answer[11], char test[11]){
    int i;
    int sum = 0;
    for(i = 0; i < 10; i++)
        if(answer[i] == test[i])
            sum++;

    return sum;
}

char getLevel(int score){
    if(score == 10 || score == 9)
        return 'A';
    else if(score == 7 || score == 8)
        return 'C';
    else return 'F';
}

int main(){
    char answer[11] = "TFFFTFTFTT";
    char name[100], testAnswer[11];
    FILE *fp = fopen("Q3.txt", "r");

    while(fscanf(fp, "%s %s", name, testAnswer) != EOF){
        int score = getScore(answer, testAnswer);
        printf("%s\t%s\t%d\t%c\n", name, testAnswer, score, getLevel(score));
    }
    

    return 0;
}