//2.	输入一行字符串（单词和若干空格），输出该行单词个数。
#include<stdio.h>
#include<stdlib.h>
int wordCount(char* s) {
	int cnt = 0, f = 0;
	while (*s != '\0') {
		if (f == 0 && *s != ' ') {  //如果标记f为0且当前字符不为空格
			cnt++; f = 1;   //单词量+1，f置为1
		}
		else if (f == 1 && *s == ' ') f = 0;  //遇到空格，意味着当前单词结束，f置0，等下个单词到来
		s++;
	}
	return cnt;
}
int main() {
	char a[67];
	gets(a);
	int cnta = wordCount(a);
	printf("%d\n", cnta);
	return 0;
}
