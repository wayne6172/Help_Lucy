#include <stdio.h>

int main(){
    int x, y, z, T;
    int emptySum, fullSum;
    int sum = 0;

    scanf("%d", &T);

    while(T--){
        scanf("%d %d %d", &x, &y, &z);
        emptySum = x + y;
        sum = 0;

        while(1){
            fullSum = emptySum / z;

            if(fullSum == 0)
                break;

            emptySum = emptySum % z;

            sum += fullSum;
            emptySum += fullSum;
        }
        printf("%d\n", sum);
    }
    return 0;
}