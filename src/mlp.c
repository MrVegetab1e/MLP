#include "mlp.h"

Ptr_layer creat_layer(Ptr_layer_cfg layer_cfg, Ptr_layer upper_layer)
{
        Ptr_layer new_layer = NULL;
        new_layer = (Ptr_layer)malloc(sizeof(struct Hidden_layer));

        new_layer->id = layer_cfg->id;
        new_layer->nerve_num = layer_cfg->nerve_num;
        new_layer->fun_type = layer_cfg->fun_type;
        new_layer->u = layer_cfg->u;
        new_layer->Ptr_Weight = NULL;
        new_layer->Ptr_Weight = create_mat(0, new_layer->nerve_num, upper_layer->nerve_num);
        init_mat(new_layer->Ptr_Weight);
}