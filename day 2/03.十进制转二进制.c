//固定输出32位，适用于负数
#include<stdio.h>
int main(){
	int x, i;
	scanf("%d", &x);
	for (i = 31; i >= 0; i--) printf("%d", x >> i & 1);  //1不动，x右移去求与，确保每次循环结果非1即0
                                                       //不能拿1去左移，输入6会输出00...420(4+2=6)
	system("pause");
}
