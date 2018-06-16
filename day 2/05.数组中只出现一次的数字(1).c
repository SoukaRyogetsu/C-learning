//异或三连
//有101个整数，其中有50个数出现了两次，1个数出现了一次，找出出现了一次的那个数。
#include<stdio.h>
int main(){
	int a[101],ans=0;
	for(int i=0;i<100;i++)
        a[i]=i;
    a[100]=66;
    for(int i=0;i<101;i++)
        ans^=a[i];
    printf("%d",ans);
	return 0;
}
