//思路：先计算替换后数组会变多大，倒着插值
#include <stdio.h>
#include <string.h>
int main() {
	char a[111]=" hello how world ";
	int spcnt=0,len1=strlen(a);
	for(int i=0;i<len1;i++)
        if(a[i]==' ') spcnt++;
    int len2=len1+3*spcnt;
    a[len2]='\0';
    for(int i=len2-1,j=len1-1;i>=0;){
        if(a[j]==' '){
            a[i--]='0';
            a[i--]='2';
            a[i--]='0';
            a[i--]='%';
            j--;
        }
        else{
            a[i--]=a[j--];
        }
    }
    printf("%s",a);
	return 0;
}
