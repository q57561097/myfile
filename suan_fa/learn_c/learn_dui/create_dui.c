#include<stdio.h>
void Sift(int *R, int i, int h)
{
	int j;
	int x = R[i];
        printf("%d|\n", i);
	j = 2 * i;
	while (j <= h) {
		if (j < h && R[j] < R[j + 1])
			j++;
		if (x >= R[j]) break;
		R[i] = R[j];
		i = j; j = 2 * i;

	}
	R[i] = x;
	//printf("%d|%d\n", i,x);
}
void main()
      {
	int list[10];
	int i, n=10;
	for (i = 0; i < 10; i++) {
		list[i] = i;
	}
	for (i = n / 2+1; i >= 0; i--) {
		Sift(list, i, n);
	}
	for (i = 0; i < 10; i++) {
		printf("%d\n", list[i]);
	}
      }
   

