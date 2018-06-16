//输入一行字符串（单词和若干空格），输出该行单词（每个单词一行）
//与02一样
#include<stdio.h>
#include<stdlib.h>
void wordPrint(char* s) {
	int cnt=0, f = 0;
	while (*s != '\0') {
		if (f == 0 && *s != ' ') {
			f = 1;
			printf("%c", *s);
		}
		else if (f == 1 && *s != ' ') printf("%c", *s);
		else if (f == 1 && *s == ' ') {
			f = 0;
			printf("\n");
		}
		s ++ ;
	}
}
int main() {
	char a[67];
	gets_s(a);
	wordPrint(a);
	return 0;
}
