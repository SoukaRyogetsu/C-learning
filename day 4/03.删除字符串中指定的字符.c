//给人一种删除了的错觉
#include <stdio.h>
#include <string.h>
int main() {
	char a[]="abcdaefaghiagkl";
	char lk='a';
	int len=strlen(a),j=0;
	for(int i=0;i<len;){
        if(a[i]==lk){
            i++;
            continue;
        }
        a[j++]=a[i++];
	}
	a[j]='\0';
    printf("%s",a);
	return 0;
}
