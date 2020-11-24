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

#define INPUT_NUM
#define OUTPUT_NUM
#define HIDDEN_LAYER_NUM

enum LAYER_TYPE
{
		INPUT_LAYER,
		OUTPUT_LAYER,
		HIDDEN_LAYER
};

struct Hidden_layer_config
{
		int id,
			nerve_num;
};

