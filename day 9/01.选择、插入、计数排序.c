#include <stdio.h>
#include <time.h>
#define N 100
#define swap(x,y) {int t=x;x=y;y=t;}
void sort_count(int *a) {
	int book[N] = { 0 };
	int i, j, k = 0;
	for (i = 0; i < N; i++)
		book[a[i]]++;
	for (i = 0; i < N; i++) 
		for (j = 0; j < book[i]; j++)
			a[k++] = i;
}
void sort_insert(int *a) {
	int i, j, k,t;
	for (i = 1; i < N; i++) 
		for (j = 0; j < i; j++)
			if (a[j] > a[i]) {
				t = a[i];
				for (k = i; k >j; k--)
					a[k] = a[k-1];
				a[k] = t;
			}
}
void sort_select(int*a) {
	int index, i, j;
	for (i = 0; i < N - 1; i++) {
		index = 0;
		for (j = 1; j < N - i; j++) 
			if (a[j] > a[index]) 
				index = j;					
		swap(a[index], a[j-1]);
	}
}
void print(int *a) {
	int i,j=0;
	for (i = 0; i < N; i++) {
		printf("%-3d ", a[i]);
		if (++j == 10) {
			printf("\n");
			j = 0;
		}
	}
	printf("\n");
}
int main(){
	int *a = (int*)calloc(N, sizeof(int)),i;
	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++) {
		a[i] = rand() % 100;
	}
	time_t start, end;
	start = time(NULL);
//	sort_select(a);  //选择排序
//	sort_insert(a);  //插入排序
//	sort_count(a);  //计数排序
	end = time(NULL);
	print(a);
	printf("use time:%d s\n", end - start);
	return 0;
}
