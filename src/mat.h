/** @file mat.h
 *  @brief Header of mat operators
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Matrix
{
		int id;
		double **mat;
		int row_num,
			column_num;
};

typedef struct Matrix *Ptr_mat;

Ptr_mat create_mat(int id, const int row_num, const int column_num);
void init_mat(Ptr_mat mat);
void seed_with_random_values(Ptr_mat mat, double lower_bound, double upper_bound);
void free_mat(Ptr_mat mat);
Ptr_mat mult_mat(Ptr_mat A, Ptr_mat B);