#include <stdio.h>
#include <string.h>
int main() {
	char a[] = "   hello   world how   are   you   ";
	int lscnt = 0, len = strlen(a), i = 0, j = 1, flag = 0;
	while (a[i] == ' ') {	//处理前置位空格
		i++;
		lscnt++;
	}
	while (i<len) {
		if (a[i] != ' ') {	//不为空格，写入字母
			flag = 0;
			a[i - lscnt] = a[i];	//原地处理
			i++;
		}
		else {
			if (flag == 0) {  //字母写着写着来了个空格
				flag = 1;	//把门，只准写进来一个空格
				a[i - lscnt] = a[i];  //这个空格要写
				i++;
			}
			else {	//非第一个空格，i和空格数均+1
				lscnt++;
				i++;
			}
		}
	}//while
	a[len - lscnt] == '\0';
	while (a[len - lscnt - j] == ' ') { //处理后置位空格
		j++;
	}
	a[len - lscnt - j + 1] = '\0';  //补上结束符
	printf("%s", a);
	return 0;
}
