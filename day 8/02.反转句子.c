//输入一个英文句子，翻转句子中单词的顺序，但句子中字符的顺序不变。
//例如 I am a student翻转成student a am I。
//做过了，再写一遍，复习
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rev(char *s,int len) {
	int i;
	for (i = 0; i < len / 2; i++) {
		char t = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = t;
	}
}
int main() {
	char s[111];
	int p1, p2, f = 0, i = 0;
	gets(s);
	rev(s, strlen(s));
	char *p = s;
	while (p[i]) {
		if (f==0 && p[i] != ' ') {
			p1 = i;
			f = 1;
		}
		else if(f== 1 && p[i]==' ') {
			p2 = i;
			f = 0;
			rev(&p[p1], p2-p1);
		}
		i++;
	}
	printf("%s\n", s);
  return 0;
}
