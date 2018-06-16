#include<stdio.h>
#include<stdlib.h>
int mystrcmp(char *s1, char *s2) {
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 < *s2) return -1;
		else if (*s1 > *s2) return 1;
		s1++; s2++;
	}
	if (*s1 == '\0' && *s2 == '\0') return 0;
	else if (*s1 != '\0') return 1;
	else return -1;
}
int mystrlen(char* s) {
	int cnt = 0;
	while (*s != '\0') {
		s++; cnt++;
	}
	return cnt;
}
void mystrcpy(char *des, char *sou)
{
	while (*sou != '\0')	*des++ = *sou++;
	*des = '\0';
}
void mystrcat(char *des, char *sou) {
	while (*des != '\0') 	des++;
	while (*sou != '\0') 	*des++ = *sou++;
	*des = '\0';
}
int main() {
	char a[66] = "hello world";
	char b[66] = "anyway666666";
	char c[66] = "keep ";
	char d[66] = "simple";
	printf("%d %d %d %d\n", mystrlen(a), mystrlen(b), mystrlen(c), mystrlen(d));
	mystrcpy(a, b);
	puts(a);
	int cmp1 = mystrcmp(c, b), cmp2 = mystrcmp(c, d);
	printf("%d %d\n", cmp1, cmp2);
	mystrcat(c, d);
	puts(c);
	return 0;
}
