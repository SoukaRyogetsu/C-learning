//有一个学生结构体，其数据成员有：学号，姓名，3 门课程。从键盘上输入5 个学生
//的信息。要求输出：
//(1) 按照学号递增输出全部学生信息，每个学生的信息一行。（格式：学号姓名分数1 分数2 分数3 总分）
//(2) 输出每门课程最高分的学生的信息
//(3) 输出每门课程的平均分
//(4) 按照总分输出学生排名
/*
测试数据：
11001 cao 66 77 88
11035 ren 60 60 60
11022 li 95 98 100
11010 cui 85 90 95
11014 yuan 62 99 81
*/
//题目不难，C语言与C++在结构体定义上不太一样，一开始怎么定义都不对，通过这题学到了。
//学习了qsort，还不太熟，体感没有C++里sort好用
#include<stdio.h>
#include<stdlib.h>

const int N = 5;
typedef struct {
	int num;
	char name[20];
	int score[3];
	int sum;
}Stu;
Stu a[5];
void init() {
	for (int i = 0; i < N; i++) {
		scanf("%d%s%d%d%d", &a[i].num, a[i].name, &a[i].score[0], &a[i].score[1], &a[i].score[2]);
		a[i].sum = a[i].score[0] + a[i].score[1] + a[i].score[2];
	}
}
int cmp(const void *a, const void *b) {
	return ((*(Stu*)a).num - (*(Stu*)b).num);
}
int cmp2(const void *a, const void *b) {
	return ((*(Stu*)b).sum - (*(Stu*)a).sum);
}
void highSocre(Stu *a, int index) {
	Stu t;
	int hs = 0;
	for (int i = 0; i < N; i++) {
		if ((a + i)->score[index] > hs) {
			hs = (a + i)->score[index];
			t = *(a + i);
		}
	}
	printf("第%d门课程成绩最高的学生信息：%d %s %d %d %d %d\n", index + 1, t.num, t.name, t.score[0], t.score[1], t.score[2], t.sum);
}
void avgScore(Stu* a, int index) {
	double avg = 0.0;
	for (int i = 0; i < N; i++)
		avg += (a + i)->score[index];
	printf("第%d门课程成绩全部学生的平均分为：%.2lf\n", index + 1, avg / N);
}
void scrank(Stu* a) {
	printf("按照总分降序排序：\n");
	qsort(a, N, sizeof(a[0]), cmp2);
	for (int i = 0; i < N; i++)
		printf("%d %s %d %d %d %d\n", a[i].num, a[i].name, a[i].score[0], a[i].score[1], a[i].score[2], a[i].sum);

}
void numrank(Stu *a) {
	printf("按照学号升序排序：\n");
	qsort(a, N, sizeof(a[0]), cmp);
	for (int i = 0; i < N; i++)
		printf("%d %s %d %d %d %d\n", a[i].num, a[i].name, a[i].score[0], a[i].score[1], a[i].score[2], a[i].sum);
}
int main()
{
	init();
	printf("\n");
	numrank(a);
	printf("\n");
	for (int i = 0; i < 3; i++)	highSocre(a, i);
	printf("\n");
	for (int i = 0; i < 3; i++)	avgScore(a, i);
	printf("\n");
	scrank(a);
	return 0;
}
