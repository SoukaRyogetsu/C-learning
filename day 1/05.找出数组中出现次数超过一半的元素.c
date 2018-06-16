//给定一个n个整型元素的数组a，其中有一个元素出现次数超过n / 2，求这个元素。
#include <stdio.h>
int main() {
	int a[] = { 5,1,5,5,5,6,5,7,9 };
	int len = sizeof(a) / sizeof(int);
	int mce = a[0], cnt = 1;
	for (int i = 1; i < len; i++) {
		if (a[i] == mce) cnt++;
		else {
			if (cnt == 1)
				mce = a[i];
			else cnt--;
		}
	}
	printf("%d", mce);
	return 0;
}
