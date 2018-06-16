#include <stdio.h>
int main(){
    int b=1;
    for(int i=1;i<=9;i++){
        int a=1;
        for(int j=1;j<=i;j++){
            printf("%d*%d=%-3d",a,b,a*b);
            a++;
        }
        b++;
        printf("\n");
    }
    return 0;
}
