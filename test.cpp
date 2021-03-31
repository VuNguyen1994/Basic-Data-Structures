#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

// Add int max of four here
int max_of_four(int a, int b, int c, int d){
	int max = 0;
	if (a > max) max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int main(){
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int ans = max_of_four(a, b, c, d);
	printf("%d\n", ans);
	const char * h = "abcd?";
	printf("%d\n", *h);
	int len = 0;
	while (h[len] != NULL){
		len++;
	}
	printf("len: %d\n", len);
	printf("strlen: %ld\n", strlen(h));

	int A[5][5] = {0};
	// for (int i = 0; i<5; i++){
	// 	for (int j = 0; j<5; j++)
	// 		A[i][j] = j;
	// }
	for (int i = 0; i<5; i++){
		for (int j = 0; j<5; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	return 0;
}
