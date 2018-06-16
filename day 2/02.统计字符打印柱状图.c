//从键盘上输入字符，（1）分别统计一下其中字母，数字，其他字符的个数， （2）将统计的字母，数字，其他字符的个数以柱状图的形式打印。
//  5
//*****
//*****     3
//*****   *****     2
//*****   *****   *****
//*****   *****   *****
// alp     num     oth
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void process(int para, int i) {
	if (para<i) printf("     ");
	else if (para == i)
		printf("  %-02d ", para);
	else printf("*****");
	printf("   ");
}
int main() {
	char s[101];
	gets(s);
	int len = strlen(s), alp = 0, num = 0, oth = 0;
	for (int i = 0; i<len; i++) {
		if (s[i] >= 'A'&&s[i] <= 'Z' || s[i] >= 'a'&&s[i] <= 'z')
			alp++;
		else if (s[i] >= '0'&&s[i] <= '9')
			num++;
		else oth++;
	}
	int max = alp>num ? (alp>oth ? alp : oth) : (num>oth ? num : oth);
	for (int i = max; i >= 0; i--) {
		process(alp, i);
		process(num, i);
		process(oth, i);
		printf("\n");
	}
	printf(" alp     num     oth\n");
	return 0;
}
