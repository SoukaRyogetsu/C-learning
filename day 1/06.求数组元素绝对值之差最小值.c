//先排序，就当练习手写快排了
#include <stdio.h>
#define n 10
#define INT_MAX 999999999
int ran() {
	return rand() % 100;
}
void qs(int a[], int l, int r) {
	if (l >= r) return;
	int i = l, j = r, p = a[l];
	while (i<j) {
		while (i<j&&a[j] >= p) j--;
		if (j>i) a[i] = a[j];
		while (i<j&&a[i] <= p) i++;
		if (i<j) a[j] = a[i];
	}
	a[i] = p;
	qs(a, l, i - 1);
	qs(a, i + 1, r);
}
int main() {
	srand((unsigned)time(NULL));
	int a[n], min = INT_MAX;
	for (int i = 0; i<n; i++) {
		a[i] = ran();
		printf("%d ", a[i]);
	}
	printf("\n");
	qs(a, 0, n - 1);
	for (int i = 0; i<n; i++) 
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i<n; i++)
		min = (a[i] - a[i - 1]<min) ? (a[i] - a[i - 1]) : min;
	printf("%d", min);
	return 0;
}
