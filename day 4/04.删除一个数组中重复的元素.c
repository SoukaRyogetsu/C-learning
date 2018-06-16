//假删除，真输出
#include <stdio.h>
#include <stdlib.h>
int main() {
	int a[]={1,2,2,2,3,3,3,4,4,5,5,5,6,6,6};
	int book[111]={0};
	int len=sizeof(a)/sizeof(int);
	for(int i=0;i<len;i++)
        if(book[a[i]]==0) book[a[i]]=1;
	for(int i=0;i<len;i++){
        if(book[a[i]]==1){
            book[a[i]]=0;
            printf("%d ",a[i]);
        }
	}
	return 0;
}
