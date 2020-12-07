/** @file mlp.h
 *  @brief Header of MLP skeleton.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include "mat.h"

#define INPUT_NUM
#define OUTPUT_NUM
#define HIDDEN_LAYER_NUM

enum LAYER_TYPE
{
		INPUT_LAYER,
		OUTPUT_LAYER,
		HIDDEN_LAYER
};

enum FUNCTION_TYPE
{
		Sigmoid,
		Tanh,
		ReLU
};

struct Hidden_layer_config
{					
		const int id,
				  nerve_num,
				  fun_type;
		double u;
};

struct Hidden_layer
{
		const int id,
				  nerve_num,
				  fun_type;
		double u;
		Ptr_mat Ptr_Weight,
				Ptr_Sigma,
				Ptr_Output,
				Ptr_Error;
};

typedef struct Hidden_layer_config *Ptr_layer_cfg;
typedef struct Hidden_layer *Ptr_layer;

Ptr_layer creat_layer(Ptr_layer_cfg layer_cfg);
int construct_network(Ptr_layer *layer);
int layer_forward(Ptr_layer *layer);