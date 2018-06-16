#include <stdio.h>
#define INT_MIN -99999
int main() {
	int a[]={ 1,2,3,4,5,6,7,8,9 };
	int max = INT_MIN, secmax = INT_MIN;
	int len = sizeof(a) / sizeof(int);
	for (int i = 0; i<len; i++) {
		if (a[i]>max) {
			secmax = max;
			max = a[i];
		}
	}
	printf("%d %d", max, secmax);
	return 0;
}
