/** @file mlp.c
 *  @brief Matrix operators
 *  
 */

#include "mat.h"

Ptr_mat create_mat(int id, const int row_num, const int column_num)
{
		int i;

		Ptr_mat mat = NULL;
		mat = (Ptr_mat)malloc(sizeof(struct Matrix));

		mat->mat = NULL;
		mat->mat = (double **)malloc(row_num * sizeof(double *));
		for(i = 0; i < row_num; i++)
		{
				mat->mat[i] = (double *)malloc(column_num * sizeof(double));
		}

		mat->id = id;
		mat->row_num = row_num;
		mat->column_num = column_num;

		return mat;
}

void init_mat(Ptr_mat mat)
{
		int i,j;

		for(i = 0; i < mat->row_num; i++)
		{
				for(j = 0; j < mat->column_num; j++)
				{
						mat->mat[i][j] = 0;
				}
		}

		return;
}

 void seed_with_random_values(Ptr_mat mat, double lower_bound, double upper_bound)
{
		int i,j;

		for(i = 0; i < mat->row_num; i++)
		{
				for(j = 0; j < mat->column_num; j++)
				{
						mat->mat[i][j] = lower_bound + ((double)rand() / RAND_MAX) * (upper_bound - lower_bound);
				}
		}
}

void free_mat(Ptr_mat mat)
{
		int i;

		for(i = 0; i < mat->row_num; i++)
		{
				free(mat->mat[i]);
				mat->mat[i] = NULL;
		}
		free(mat->mat);
		mat->mat = NULL;
		free(mat);
		mat = NULL;
}

Ptr_mat mult_mat(Ptr_mat A, Ptr_mat B, int id)
{
		int i,j,k;

		Ptr_mat mat = NULL;

		if(A->column_num != B->row_num)
		{
				return mat;
		}
		else
		{
				mat = create_mat(id, A->row_num, B->column_num);
				init_mat(mat);
				for(i = 0; i < mat->row_num; i++)
				{
						for(j = 0; j < mat->column_num; j++)
						{
								for(k = 0; k < A->column_num; k++)
								{
										mat->mat[i][j] += A->mat[i][k] * B->mat[k][j];
								}
						}
				}
				return mat;
		}
}
