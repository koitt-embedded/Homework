#include <stdio.h>

int main(int argc, char** argv) {
	int i, j, k;
	int matrix1[3][3] =
	{
		{1, 5, 3},
		{5, 6, 1},
		{6, 4, 1}
	};

	int matrix2[3][3] =
	{
		{4, 8, 1},
		{2, 6, 8},
		{3, 3, 1}
	};

	int matrix3[3][3] = {0};

	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			for(k=0; k<3; k++)
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];

	for(i=0; i<3; i++) {
		for(j=0; j<3; j++) printf("%d ", matrix3[i][j]);
		putchar('\n');
	}

	return 0;
}