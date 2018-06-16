//将包含字符数字的字符串分开,使得分开后的字符串前一部分是数字后一部分是字母。
#include <stdio.h>
#include <string.h>
void divide(char *a, char num[], char alp[]) {
	int len = strlen(a), nnum = 0, nalp = 0;
	for (int i = 0; i<len; i++) {
		if (a[i] >= '0'&&a[i] <= '9') num[nnum++] = a[i];
		else alp[nalp++] = a[i];
	}
}
int main() {
	char a[] = "h1ell2o3";
	char num[66] = "", alp[66] = "";
	divide(a, num, alp);
	printf("%s", strcat(num, alp));
	return 0;
}
