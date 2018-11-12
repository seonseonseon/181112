//행과 열의 수가 같은 matrix 정방행렬

#include <stdio.h>

void save_at_first(int *mat_in_1, int *mat_in_2);
void index_add_mat(int *mat_in_1, int *mat_in_2, int *mat_in_3);
void ptr_prod_mat(int *mat_in_1, int *mat_in_2, int *mat_in_3);

int main(void)
{
	int matA[3][3], matB[3][3], matC[3][3];
	printf("3 * 3 matrixA를 입력하세요.\n");

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("matrix[%d][%d] = ", i, j);
			scanf_s("%d", &matA[i][j]);
		}
	}

	printf("입력된 matrixA를 출력합니다.\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matA[i][j]);
		}
		printf("\n");
	}

	save_at_first(matB, matA);
	save_at_first(matC, matA);

	index_add_mat(matA, matA, matB);

	printf("matrixA + matrixA = matrixB\nmatrixB를 출력합니다.\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matB[i][j]);
		}
		printf("\n");
	}

	ptr_prod_mat(matA, matB, matC);
	printf("matrixA * matrixB = matrixC\nmatrixC를 출력합니다.\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", matC[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}

void save_at_first(int *mat_in_1, int *mat_in_2)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			*(mat_in_1 + 3 * i + j) = *(mat_in_2 + 3 * i + j);
		}
	}
	return;
}

void index_add_mat(int *mat_in_1, int *mat_in_2, int *mat_in_3)
{
	int mat_result[3][3];
	int mat_tmp_1[3][3];
	int mat_tmp_2[3][3];

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat_tmp_1[i][j] = *(mat_in_1 + 3 * i + j);
			mat_tmp_2[i][j] = *(mat_in_2 + 3 * i + j);
		}
	}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mat_result[i][j] = mat_tmp_1[i][j] + mat_tmp_2[i][j];
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				*(mat_in_3 + 3 * i + j) = mat_result[i][j];
		}
		return;
	
}


	
void ptr_prod_mat(int *mat_in_1, int *mat_in_2, int *mat_in_3)
{
	int sum;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum += (*(mat_in_1 + 3 * i + k)) * (*(mat_in_2 + 3 * k + j));
			}
			*(mat_in_3 + 3 * i + j) = sum;
		}
	}
}




