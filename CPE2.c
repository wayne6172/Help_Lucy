#include <stdio.h>

int datas[14][10] = {
    {0,1,1,0,0,0,0,0,0,0}, // a
    {0,1,0,0,0,0,0,0,0,0}, // b
    {0,1,1,1,0,0,1,1,1,1}, // c
    {0,1,1,1,0,0,1,1,1,0}, // d
    {0,1,1,1,0,0,1,1,0,0}, // e
    {0,1,1,1,0,0,1,0,0,0}, // f
    {0,1,1,1,0,0,0,0,0,0}, // g
    {1,1,1,0,0,0,0,0,0,0}, // A
    {1,1,0,0,0,0,0,0,0,0}, // B
    {0,0,1,0,0,0,0,0,0,0}, // C
    {1,1,1,1,0,0,1,1,1,0}, // D
    {1,1,1,1,0,0,1,1,0,0}, // E
    {1,1,1,1,0,0,1,0,0,0}, // F
    {1,1,1,1,0,0,0,0,0,0}, // G
};

void f(int now[10], int next[10], int sum[10]){
    int i;
    for(i = 0; i < 10; i++){
        if(now[i] == 0 && next[i] == 1)
            sum[i]++;

        now[i] = next[i];
    }
}

int main(int argc, char const *argv[])
{
    int T, i;

    char input[1000];
    scanf("%d", &T);

    while(T--){
        int mask[10] = {0};
        int sum[10] = {0};

        scanf("%s", input);

        for(i = 0; input[i] != '\0'; i++){
            if('Z' >= input[i] && input[i] >= 'A'){
                f(mask, datas[input[i] - 'A' + 7], sum);
            }
            else {
                f(mask, datas[input[i] - 'a'], sum);
            }   
        }
        for(i = 0; i < 10; i++)
            printf("%d ", sum[i]);
        printf("\n");
    }

    return 0;
}
