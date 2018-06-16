#include<stdio.h>
#include<string.h>
int flag = 1;
int ctn(char c) {
	if (c == '0' || c == '1')
		return c - '0';
	else flag = 0;
}
int btd(char s[]) {
	int len = strlen(s), sum = 0;
	for (int i = 0; i<len; i++) {
		sum += ctn(s[i])*pow(2, len - 1 - i);
	}
	return sum;
}
int main() {
	char s[33];
	while (scanf("%s", s) != EOF) {
		int ans = btd(s);
		if (flag)
			printf("%d\n", ans);
		else printf("输入格式错误\n");
	}
	return 0;
}
