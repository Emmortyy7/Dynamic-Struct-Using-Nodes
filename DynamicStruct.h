#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 *
 * Some funcs returns null evaluate them like malloc
 * Once you finish the project make code look better
 *
 * should i change current node after adding arr !!!!!!!!!!!!!!!!!!1
 *
 * */


#pragma once


typedef enum DTYPES {
    INT8_T              = 1,
    UINT8_T             = 2,
    INT16_T             = 3,
    UINT16_T            = 4,
    INT32_T             = 5,
    UINT32_T            = 6,
    INT64_T             = 7,
    UINT64_T            = 8,
    SIGNED_CHAR         = 9,
    UNSIGNED_CHAR       = 10,
    SIGNED_INT          = 11,
    UNSIGNED_INT        = 12,
    SIGNED_SHORT        = 13,
    UNSIGNED_SHORT      = 14,
    SIGNED_LONG         = 15,
    UNSIGNED_LONG       = 16,
    SIGNED_LONG_LONG    = 17,
    UNSIGNED_LONG_LONG  = 18,
    CHAR                = 19,
    INT                 = 20,
    FLOAT               = 21,
    DOUBLE              = 22,
    SHORT               = 23,
    LONG                = 24,
    LONG_LONG           = 25,

    INT8_T_ARR            = 26,
    UINT8_T_ARR           = 27,
    INT16_T_ARR           = 28,
    UINT16_T_ARR          = 29,
    INT32_T_ARR           = 30,
    UINT32_T_ARR          = 31,
    INT64_T_ARR           = 32,
    UINT64_T_ARR          = 33,
    SIGNED_CHAR_ARR     = 34,
    UNSIGNED_CHAR_ARR   = 35,
    SIGNED_INT_ARR      = 36,
    UNSIGNED_INT_ARR    = 37,
    SIGNED_SHORT_ARR    = 38,
    UNSIGNED_SHORT_ARR  = 39,
    SIGNED_LONG_ARR     = 40,
    UNSIGNED_LONG_ARR   = 41,
    SIGNED_LONG_LONG_ARR = 42,
    UNSIGNED_LONG_LONG_ARR = 43,
    CHAR_ARR            = 44,
    INT_ARR             = 45,
    FLOAT_ARR           = 46,
    DOUBLE_ARR          = 47,
    SHORT_ARR           = 48,
    LONG_ARR            = 49,
    LONG_LONG_ARR       = 50,
    STRING              = 51
} DTYPES;

typedef struct Metadata { 
    char *name;
    DTYPES dt;
    uint16_t vars;
} Metadata;
typedef struct DynamicNode {
    uint8_t *buf;
    Metadata *md;
    struct DynamicNode *next;
} DynamicNode;
typedef struct NodeHandler { 
    DynamicNode *StartNode;
    DynamicNode *CurrentNode;
} NodeHandler;

NodeHandler* InitDS() { 
    NodeHandler* nh = (NodeHandler*)calloc(1, sizeof(NodeHandler));
    if (nh == NULL) {
        fprintf(stderr, "NodeHandler INIT FAILED.\n");
        free(nh);
    }
    nh->StartNode = (DynamicNode*)malloc(sizeof(DynamicNode));
    nh->CurrentNode = nh->StartNode;
    return nh;
}

void KillNode(const char *varname, NodeHandler *nh) { 
    DynamicNode *nodeptr = nh->StartNode;

    if(strcmp(nodeptr->md->name, varname) == 0) { 
        if (nodeptr->buf) {free(nodeptr->buf);}
        if (nodeptr->md) {
            if (nodeptr->md->name) {free(nodeptr->md->name);}
            free(nodeptr->md);
        }
        free(nodeptr);
    }

    while(nodeptr != NULL) { 
        if(strcmp(nodeptr->next->md->name, varname) == 0) {
            if(nodeptr->next->buf) {free(nodeptr->next->buf);}
            if(nodeptr->next->md) {
                if(nodeptr->next->md->name) {free(nodeptr->next->md->name);}
                free(nodeptr->next->md);
            }
            DynamicNode *tmp = nodeptr->next;
            nodeptr->next = nodeptr->next->next;
            free(tmp);
        }
    }
}

void KillDS(NodeHandler *nh) { 
    DynamicNode *nodeptr = nh->StartNode;
    
    while (nodeptr != NULL) { 
        if (nodeptr->buf) {
            free(nodeptr->buf);
        }
        if (nodeptr->md) {
            if (nodeptr->md->name) {
                free(nodeptr->md->name);
            }
            free(nodeptr->md);
        }
        DynamicNode *nextNode = nodeptr->next;
        free(nodeptr);
        nodeptr = nextNode;
    }

    free(nh);
    fprintf(stdout, "Cleanup is succesful.\n");
}

Metadata* prep_md(const char* varname, DTYPES dt, NodeHandler *nh) { 
    if(varname == NULL) {
        fprintf(stderr, "Varname is null killing DS.\n");
        KillDS(nh);
    }
    Metadata *md = (Metadata*)malloc(sizeof(Metadata));
    if(md == NULL) { 
        fprintf(stderr, "MD PREP FAILED KILLING DS.\n");
        KillDS(nh);
    }
    md->name = (char*)malloc((size_t)strlen(varname) + 1);
    if(md->name == NULL) { 
        free(md);
        fprintf(stderr, "MD PREP FAILED KILLING DS.\n");
        KillDS(nh);
    }
    strcpy(md->name, varname);
    md->dt = dt;
    md->vars = 0;
    return md;
}

/*DynamicNode* GetNearestNodeForDT(DTYPES dt, NodeHandler *nh) {
    DynamicNode *nodeptr = nh->StartNode;
    while(nodeptr != NULL) { 
        if(nodeptr->md->dt == dt) {
            return nodeptr;
        }
        nodeptr = nodeptr->next;
    }
    return NULL;
}*/

uint32_t calculate_buffer_size(uint16_t variable_count_rn, DTYPES dt) { 
    if(dt == INT8_T || dt == SIGNED_CHAR || dt == CHAR || dt == UINT8_T || dt == UNSIGNED_CHAR) { 
        return (variable_count_rn + 1);
    }
    else if(dt == UINT16_T || dt == UNSIGNED_SHORT || dt == INT16_T || dt == SIGNED_SHORT || dt == SHORT) {
        return (variable_count_rn + 1)*2;
    }
    else if(dt == UINT32_T || dt == UNSIGNED_INT || dt == UNSIGNED_LONG || dt == INT32_T || dt == SIGNED_INT || dt == INT || dt == SIGNED_LONG || dt == LONG || dt == FLOAT) { 
        return (variable_count_rn + 1)*4;
    }
    else if(dt == UINT64_T || dt == UNSIGNED_LONG_LONG || dt == INT64_T || dt == SIGNED_LONG_LONG || dt == LONG_LONG || dt == DOUBLE) { 
        return (variable_count_rn + 1)*8;     
    }
    return 0;
}

uint16_t get_first_index(uint16_t variable_count_rn, DTYPES dt) { 
    if(dt == INT8_T || dt == SIGNED_CHAR || dt == CHAR || dt == UINT8_T || dt == UNSIGNED_CHAR) { 
        return variable_count_rn;
    }
    else if(dt == UINT16_T || dt == UNSIGNED_SHORT || dt == INT16_T || dt == SIGNED_SHORT || dt == SHORT) {
        return (variable_count_rn*2);
    }
    else if(dt == UINT32_T || dt == UNSIGNED_INT || dt == UNSIGNED_LONG || dt == INT32_T || dt == SIGNED_INT || dt == INT || dt == SIGNED_LONG || dt == LONG || dt == FLOAT) { 
        return (variable_count_rn*4);
    }
    else if(dt == UINT64_T || dt == UNSIGNED_LONG_LONG || dt == INT64_T || dt == SIGNED_LONG_LONG || dt == LONG_LONG || dt == DOUBLE) { 
        return (variable_count_rn*8);     
    }
    return 0;
}

void AddVar(void* var, const char *varname, DTYPES dt, NodeHandler *nh) { 
    if(nh->CurrentNode->md == NULL) { 
            nh->CurrentNode->md = prep_md(varname, dt, nh);
    }

    if(dt == INT8_T || dt == SIGNED_CHAR || dt == CHAR || dt == UINT8_T || dt == UNSIGNED_CHAR) {
        nh->CurrentNode->buf = (uint8_t*)realloc(nh->CurrentNode->buf, calculate_buffer_size(nh->CurrentNode->md->vars, dt));
        
        if(nh->CurrentNode->buf == NULL) { 
            fprintf(stderr, "Can't allocate buffer.\n");
        }

        nh->CurrentNode->buf[get_first_index(nh->CurrentNode->md->vars, dt)] = *(uint8_t*)var;
        nh->CurrentNode->md->vars += 1;

        if(nh->CurrentNode->next == NULL) {
             nh->CurrentNode->next = (DynamicNode*)malloc(sizeof(DynamicNode));
             nh->CurrentNode = nh->CurrentNode->next;
        }
	}
    else if(dt == UINT16_T || dt == UNSIGNED_SHORT || dt == INT16_T || dt == SIGNED_SHORT || dt == SHORT) {        
        nh->CurrentNode->buf = (uint8_t*)realloc(nh->CurrentNode->buf, calculate_buffer_size(nh->CurrentNode->md->vars, dt));

        if(nh->CurrentNode->buf == NULL) { 
            fprintf(stderr, "Can't allocate buffer.\n");
        }

        uint16_t f_index = get_first_index(nh->CurrentNode->md->vars, dt);
        nh->CurrentNode->buf[f_index] = (uint8_t)(((*(uint16_t*)var)) & 0xFF);        
        nh->CurrentNode->buf[f_index + 1] = (uint8_t)(((*(uint16_t*)var) >> 8) & 0xFF);
        nh->CurrentNode->md->vars += 1;
        
        if(nh->CurrentNode->next == NULL) {
             nh->CurrentNode->next = (DynamicNode*)malloc(sizeof(DynamicNode));
             nh->CurrentNode = nh->CurrentNode->next;
        }
    }
    else if(dt == UINT32_T || dt == UNSIGNED_INT || dt == UNSIGNED_LONG || dt == INT32_T || dt == SIGNED_INT || dt == INT || dt == SIGNED_LONG || dt == LONG) {      
        nh->CurrentNode->buf = (uint8_t*)realloc(nh->CurrentNode->buf, calculate_buffer_size(nh->CurrentNode->md->vars, dt));

        if(nh->CurrentNode->buf == NULL) { 
            fprintf(stderr, "Can't allocate buffer.\n");
        }

        uint16_t f_index = get_first_index(nh->CurrentNode->md->vars, dt);

        nh->CurrentNode->buf[f_index] = (uint8_t)(((*(uint32_t*)var)) & 0xFF);        
        nh->CurrentNode->buf[f_index + 1] = (uint8_t)(((*(uint32_t*)var) >> 8) & 0xFF);
        nh->CurrentNode->buf[f_index + 2] = (uint8_t)(((*(uint32_t*)var) >> 16) & 0xFF);
        nh->CurrentNode->buf[f_index + 3] = (uint8_t)(((*(uint32_t*)var) >> 24) & 0xFF);
        nh->CurrentNode->md->vars += 1;
        
        if(nh->CurrentNode->next == NULL) {
             nh->CurrentNode->next = (DynamicNode*)malloc(sizeof(DynamicNode));
             nh->CurrentNode = nh->CurrentNode->next;
        }
    }
    else if(dt == UINT64_T || dt == UNSIGNED_LONG_LONG || dt == INT64_T || dt == SIGNED_LONG_LONG || dt == LONG_LONG) {
        nh->CurrentNode->buf = (uint8_t*)realloc(nh->CurrentNode->buf, calculate_buffer_size(nh->CurrentNode->md->vars, dt));
        
        if(nh->CurrentNode->buf == NULL) { 
            fprintf(stderr, "Can't allocate buffer.\n");
        }

        uint16_t f_index = get_first_index(nh->CurrentNode->md->vars, dt);
        nh->CurrentNode->buf[f_index] = (uint8_t)(((*(uint64_t*)var)) & 0xFF);
        nh->CurrentNode->buf[f_index + 1] = (uint8_t)(((*(uint64_t*)var) >> 8) & 0xFF);
        nh->CurrentNode->buf[f_index + 2] = (uint8_t)(((*(uint64_t*)var) >> 16) & 0xFF);
        nh->CurrentNode->buf[f_index + 3] = (uint8_t)(((*(uint64_t*)var) >> 24) & 0xFF);
        nh->CurrentNode->buf[f_index + 4] = (uint8_t)(((*(uint64_t*)var) >> 32) & 0xFF);
        nh->CurrentNode->buf[f_index + 5] = (uint8_t)(((*(uint64_t*)var) >> 40) & 0xFF);
        nh->CurrentNode->buf[f_index + 6] = (uint8_t)(((*(uint64_t*)var) >> 48) & 0xFF);
        nh->CurrentNode->buf[f_index + 7] = (uint8_t)(((*(uint64_t*)var) >> 56) & 0xFF);
        nh->CurrentNode->md->vars += 1;
        
        if(nh->CurrentNode->next == NULL) {
             nh->CurrentNode->next = (DynamicNode*)malloc(sizeof(DynamicNode));
             nh->CurrentNode = nh->CurrentNode->next;
        }
    }
    else if(dt == DOUBLE) {
        nh->CurrentNode->buf = (uint8_t*)realloc(nh->CurrentNode->buf, calculate_buffer_size(nh->CurrentNode->md->vars, dt));
        
        if(nh->CurrentNode->buf == NULL) { 
            fprintf(stderr, "Can't allocate buffer.\n");
        }
	
        union { 	
			double d;
			unsigned long long bits;
	    } dbits;
        dbits.d = *(double*)var;

        uint16_t f_index = get_first_index(nh->CurrentNode->md->vars, dt);

        nh->CurrentNode->buf[f_index] = (uint8_t)((dbits.bits) & 0xFF);
        nh->CurrentNode->buf[f_index + 1] = (uint8_t)(((dbits.bits) >> 8) & 0xFF);
        nh->CurrentNode->buf[f_index + 2] = (uint8_t)(((dbits.bits) >> 16) & 0xFF);
        nh->CurrentNode->buf[f_index + 3] = (uint8_t)(((dbits.bits) >> 24) & 0xFF);
        nh->CurrentNode->buf[f_index + 4] = (uint8_t)(((dbits.bits) >> 32) & 0xFF);
        nh->CurrentNode->buf[f_index + 5] = (uint8_t)(((dbits.bits) >> 40) & 0xFF);
        nh->CurrentNode->buf[f_index + 6] = (uint8_t)(((dbits.bits) >> 48) & 0xFF);
        nh->CurrentNode->buf[f_index + 7] = (uint8_t)(((dbits.bits) >> 56) & 0xFF);
        nh->CurrentNode->md->vars += 1;
        
        if(nh->CurrentNode->next == NULL) {
             nh->CurrentNode->next = (DynamicNode*)malloc(sizeof(DynamicNode));
             nh->CurrentNode = nh->CurrentNode->next;
        }
    }

    else if(dt == FLOAT) {         
        nh->CurrentNode->buf = (uint8_t*)realloc(nh->CurrentNode->buf, calculate_buffer_size(nh->CurrentNode->md->vars, dt));
        
        if(nh->CurrentNode->buf == NULL) { 
            fprintf(stderr, "Can't allocate buffer.\n");
        }

        union { 	
            float f;
		    unsigned int bits;
		} fbits;
        fbits.f = *(float*)var;
    
        uint16_t f_index = get_first_index(nh->CurrentNode->md->vars, dt);

        nh->CurrentNode->buf[0] = (uint8_t)((fbits.bits) & 0xFF);        
        nh->CurrentNode->buf[1] = (uint8_t)(((fbits.bits) >> 8) & 0xFF);
        nh->CurrentNode->buf[2] = (uint8_t)(((fbits.bits) >> 16) & 0xFF);
        nh->CurrentNode->buf[3] = (uint8_t)(((fbits.bits) >> 24) & 0xFF);
        
        if(nh->CurrentNode->next == NULL) {
             nh->CurrentNode->next = (DynamicNode*)malloc(sizeof(DynamicNode));
             nh->CurrentNode = nh->CurrentNode->next;
        }
    }
    else {
       fprintf(stderr, "AddVar failed invalid dt.\n"); 
    }
}

uint16_t count_8bit(const uint8_t *arr_p) { 
    uint16_t counter = 0;
    if (arr_p == NULL) {
        return -1;
    }
    while (*(arr_p + counter) != '\0') {
        counter++;
    }
    
    uint16_t arr_size = (uint16_t)(sizeof(arr_p));

    printf("\nsizeof : % d\n", (int)arr_size);
    return counter;
}

uint16_t count_16bit(const uint16_t *arr_p) { 
    uint16_t counter = 0;
    if (arr_p == NULL) {
        return -1;
    }
    while (*(arr_p + counter) != '\0') {
        counter++;
    }
    return counter;
}

uint16_t count_32bit(const uint32_t *arr_p) { 
    uint16_t counter = 0;
    if (arr_p == NULL) {
        return -1;
    }
    while (*(arr_p + counter) != '\0') {
        counter++;
    }
    return counter;
}

uint16_t count_64bit(const uint64_t *arr_p) { 
    uint16_t counter = 0;
    if (arr_p == NULL) {
        return -1;
    }
    while (*(arr_p + counter) != '\0') {
        counter++;
    }
    return counter;
}

void AddArr(void *arr, const char *arr_name, DTYPES dt, NodeHandler *nh, size_t arr_siz) { 
    if(nh->CurrentNode->md == NULL) { 
        nh->CurrentNode->md = prep_md(arr_name, dt, nh);
    }

    DynamicNode *cur_node = nh->CurrentNode;

    if(cur_node == NULL) { 
        fprintf(stderr, "Current Node is NULL.\n");
    }

    if(dt == INT8_T_ARR || dt == SIGNED_CHAR_ARR || dt == CHAR_ARR || dt == UINT8_T_ARR || dt == UNSIGNED_CHAR_ARR || dt == STRING) {
        uint8_t *arr_p = (uint8_t*)arr;
        
        for(uint16_t i = 0; i < arr_siz; i++) { 
            if(i == 0) {
                AddVar(&arr_p[i], arr_name, UINT8_T, nh);
                nh->CurrentNode = cur_node;
                continue;
            }
            AddVar(&arr_p[i], NULL, UINT8_T, nh);
            nh->CurrentNode = cur_node;
        }
    }
    else if(dt == UINT16_T_ARR || dt == UNSIGNED_SHORT_ARR || dt == INT16_T_ARR || dt == SIGNED_SHORT_ARR || dt == SHORT_ARR) {
        uint16_t *arr_p = (uint16_t*)arr;

        for(uint16_t i = 0; i < arr_siz; i++) { 
            if(i == 0) {
                AddVar(&arr_p[i], arr_name, UINT16_T, nh);
                nh->CurrentNode = cur_node;
                continue;
            }
            AddVar(&arr_p[i], NULL, UINT16_T, nh);
            nh->CurrentNode = cur_node;        
        }
    }
    else if(dt == UINT32_T_ARR || dt == UNSIGNED_INT_ARR || dt == UNSIGNED_LONG_ARR || dt == INT32_T_ARR || dt == SIGNED_INT_ARR || dt == INT_ARR || dt == SIGNED_LONG_ARR || dt == LONG_ARR) { 
        uint32_t *arr_p = (uint32_t*)arr;

        for(uint16_t i = 0; i < arr_siz; i++) { 
            if(i == 0) {
                AddVar(&arr_p[i], arr_name, UINT32_T, nh);
                nh->CurrentNode = cur_node;
                continue;
            }
            AddVar(&arr_p[i], NULL, UINT32_T, nh);
            nh->CurrentNode = cur_node;
        }
    }
    else if(dt == UINT64_T_ARR || dt == UNSIGNED_LONG_LONG_ARR || dt == INT64_T_ARR || dt == SIGNED_LONG_LONG_ARR || dt == LONG_LONG_ARR) {
        uint64_t *arr_p = (uint64_t*)arr;
        
        for(uint16_t i = 0; i < arr_siz; i++) { 
            if(i == 0) {
                AddVar(&arr_p[i], arr_name, UINT64_T, nh);
                nh->CurrentNode = cur_node;
                continue;
            }
            AddVar(&arr_p[i], NULL, UINT64_T, nh);
            nh->CurrentNode = cur_node;        
        }
    }
    else if(dt == FLOAT_ARR) {
        float *arr_p = (float*)arr;

        for(uint16_t i = 0; i < arr_siz; i++) { 
            if(i == 0) {
                AddVar(&arr_p[i], arr_name, FLOAT, nh);
                nh->CurrentNode = cur_node;
                continue;
            }
            AddVar(&arr_p[i], NULL, FLOAT, nh);
            nh->CurrentNode = cur_node;        
        }    
    }
    else if(dt == DOUBLE_ARR) {
        double *arr_p = (double*)arr;

        for(uint16_t i = 0; i < arr_siz; i++) { 
            if(i == 0) {
                AddVar(&arr_p[i], arr_name, DOUBLE, nh);
                nh->CurrentNode = cur_node;
                continue;
            }
            AddVar(&arr_p[i], NULL, DOUBLE, nh);
            nh->CurrentNode = cur_node;        
        }
    }
    else {
        fprintf(stderr, "Invalid DT.\n");
    }
    
    nh->CurrentNode = cur_node->next;
}

DynamicNode* search(const char *name, NodeHandler *nh) { 
    DynamicNode *nodeptr = nh->StartNode;
    if (nodeptr == NULL) {return NULL;}
    
    char first_c = name[0];
    while (nodeptr != NULL) {   
       if (nodeptr->md->name[0] == first_c) {
            if (strcmp(nodeptr->md->name, name) == 0) {return nodeptr;}
       }
       nodeptr = nodeptr->next; 
    }
    return NULL;  
}

uint16_t buf_to_uint16_t(uint8_t *buf, const uint16_t start_index) {
    if(buf == NULL) {
        fprintf(stderr, "Buffer is empty can't continue.");
    }

    return (uint16_t)(((uint16_t)buf[start_index + 1] << 8) | (uint16_t)buf[start_index]);
}

int16_t buf_to_int16_t(uint8_t *buf, const uint16_t start_index) { 
    if(buf == NULL) {
        fprintf(stderr, "Buffer is empty can't continue.");
    }

    return (int16_t)(((int16_t)buf[start_index + 1] << 8) | (int16_t)buf[start_index]);
}

uint32_t buf_to_uint32_t(uint8_t *buf, const uint16_t start_index) {
    if(buf == NULL) {
        fprintf(stderr, "Buffer is empty can't continue.");
    }
    
    return (uint32_t)
                   (           
                    ((uint32_t)buf[start_index + 3] << 24) | ((uint32_t)buf[start_index + 2] << 16) |
                    ((uint32_t)buf[start_index + 1] << 8) | (uint32_t)buf[start_index]
                   );
}
int32_t buf_to_int32_t(uint8_t *buf, const uint16_t start_index) { 
    if(buf == NULL) {
        fprintf(stderr, "Buffer is empty can't continue.");
    }

    return (int32_t)
                   (           
                    ((int32_t)buf[start_index + 3] << 24) | ((int32_t)buf[start_index + 2] << 16) |
                    ((int32_t)buf[start_index + 1] << 8) | (int32_t)buf[start_index]
                   );
}

uint64_t buf_to_uint64_t(uint8_t *buf, const uint16_t start_index) { 
    if(buf == NULL) {
        fprintf(stderr, "Buffer is empty can't continue.");
    }
    
    return (uint64_t)
                    (           
                     ((uint64_t)buf[start_index + 6] << 48) | ((uint64_t)buf[start_index + 7] << 56) |
                     ((uint64_t)buf[start_index + 4] << 32) | ((uint64_t)buf[start_index + 5] << 40) |
                     ((uint64_t)buf[start_index + 3] << 24) | ((uint64_t)buf[start_index + 2] << 16) |
                     ((uint64_t)buf[start_index + 1] << 8) | (uint64_t)buf[start_index]
                    );
}

int64_t buf_to_int64_t(uint8_t *buf, const uint16_t start_index) { 
    if(buf == NULL) {
        fprintf(stderr, "Buffer is empty can't continue.");
    }
    
    return (int64_t)
                   (           
                    ((int64_t)buf[start_index + 6] << 48) | ((int64_t)buf[start_index + 7] << 56) |
                    ((int64_t)buf[start_index + 4] << 32) | ((int64_t)buf[start_index + 5] << 40) |
                    ((int64_t)buf[start_index + 3] << 24) | ((int64_t)buf[start_index + 2] << 16) |
                    ((int64_t)buf[start_index + 1] << 8) | (int64_t)buf[start_index]
                   );
}

float buf_to_float(uint8_t *buf, const uint16_t start_index) { 
    union {
        float f;
        unsigned int bits;
    } converter;
    
    converter.bits = 
                    (           
                    ((unsigned int)buf[start_index + 3] << 24) | ((unsigned int)buf[start_index + 2] << 16) |
                    ((unsigned int)buf[start_index + 1] << 8) | (unsigned int)buf[start_index]
                    );
    return converter.f;
}

double buf_to_double(uint8_t *buf, const uint16_t start_index) {
    union {
        double d;
        unsigned long long bits;
    } converter;

    converter.bits = 
                   (           
                    ((unsigned long long)buf[start_index + 6] << 48) | ((unsigned long long)buf[start_index + 7] << 56) |
                    ((unsigned long long)buf[start_index + 4] << 32) | ((unsigned long long)buf[start_index + 5] << 40) |
                    ((unsigned long long)buf[start_index + 3] << 24) | ((unsigned long long)buf[start_index + 2] << 16) |
                    ((unsigned long long)buf[start_index + 1] << 8) | (unsigned long long)buf[start_index + 0]
                   );
    return converter.d;
}

void* GetArr(const char *arr_name, NodeHandler *nh) {
    DynamicNode *node_s = search(arr_name, nh); 
    if(node_s == NULL) { 
        fprintf(stderr, "Variable name is wrong.\n");
        return NULL;
    }

    DTYPES dt = node_s->md->dt;

    if(dt == INT8_T_ARR || dt == SIGNED_CHAR_ARR || dt == CHAR_ARR || dt == STRING) {
        int8_t *arr = (int8_t*)malloc(node_s->md->vars);

        for(uint16_t i = 0; i < node_s->md->vars; i++) { 
            arr[i] = (int8_t)node_s->buf[i];
        }

        return (void*)arr;
    }
    else if(dt == UINT8_T_ARR || dt == UNSIGNED_CHAR_ARR) {
        uint8_t *arr = (uint8_t*)malloc(node_s->md->vars);

        for(uint16_t i = 0; i < node_s->md->vars; i++) { 
            arr[i] = node_s->buf[i];
        }

        return (void*)arr;
    }
    else if(dt == UINT16_T_ARR || dt == UNSIGNED_SHORT_ARR) {
        uint16_t *arr = (uint16_t*)malloc(node_s->md->vars*2);

        for(uint16_t i = 0; i < node_s->md->vars*2; i+=2) { 
            arr[i/2] = buf_to_uint16_t(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == SHORT_ARR || dt == SIGNED_SHORT_ARR || dt == INT16_T_ARR) {
        int16_t *arr = (int16_t*)malloc(node_s->md->vars*2);

        for(uint16_t i = 0; i < node_s->md->vars*2; i+=2) { 
            arr[i/2] = buf_to_int16_t(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == UINT32_T_ARR || dt == UNSIGNED_INT_ARR || dt == UNSIGNED_LONG_ARR) {
        uint32_t *arr = (uint32_t*)malloc(node_s->md->vars*4);
        
        for(uint16_t i = 0; i < node_s->md->vars*4; i+=4) { 
            arr[i/4] = buf_to_uint32_t(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == INT32_T_ARR || dt == SIGNED_INT_ARR || dt == INT_ARR || dt == SIGNED_LONG_ARR || dt == LONG_ARR) {
        int32_t *arr = (int32_t*)malloc(node_s->md->vars*4);

        for(uint16_t i = 0; i < node_s->md->vars*4; i+=4) { 
            arr[i/4] = buf_to_int32_t(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == UINT64_T_ARR || dt == UNSIGNED_LONG_LONG_ARR) {
        uint64_t *arr = (uint64_t*)malloc(node_s->md->vars*8);

        for(uint16_t i = 0; i < node_s->md->vars*8; i+=8) { 
            arr[i/8] = buf_to_uint64_t(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == INT64_T_ARR || dt == SIGNED_LONG_LONG_ARR || dt == LONG_LONG_ARR) {
        int64_t *arr = (int64_t*)malloc(node_s->md->vars*8);

        for(uint16_t i = 0; i < node_s->md->vars*8; i+=8) { 
            arr[i/8] = buf_to_int64_t(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == FLOAT_ARR){ 
        float *arr = (float*)malloc(node_s->md->vars*4);

        for(uint16_t i = 0; i < node_s->md->vars*4; i+=4) { 
            arr[i/4] = buf_to_float(node_s->buf, i);
        }

        return (void*)arr;
    }
    else if(dt == DOUBLE_ARR) { 
        double *arr = (double*)malloc(node_s->md->vars*8);

        for(uint16_t i = 0; i < node_s->md->vars*8; i+=8) { 
            arr[i/8] = buf_to_double(node_s->buf, i);
        }

        return (void*)arr;
    }
    else {
        fprintf(stderr, "Invalid DT try GetVar if you want to get variable.\n");
    }
    return NULL;
}

void* GetVar(const char *varname, NodeHandler *nh) { 
    DynamicNode *node_s = search(varname, nh); 
    if(node_s == NULL) { 
        fprintf(stderr, "Variable name is wrong.\n");
        return NULL;
    }

    DTYPES dt = node_s->md->dt;

    if(dt == INT8_T || dt == SIGNED_CHAR || dt == CHAR) {
        return (void*)((int8_t*)node_s->buf);
    }
    else if(dt == UINT8_T || dt == UNSIGNED_CHAR) {
        return (void*)node_s->buf;
    }
    else if(dt == UINT16_T || dt == UNSIGNED_SHORT) {        
        uint16_t *val = (uint16_t*)malloc(sizeof(uint16_t));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_uint16_t(node_s->buf, 0);
        return (void*)val;        
    }
    else if(dt == INT16_T || dt == SIGNED_SHORT || dt == SHORT) {        
        int16_t *val = (int16_t*)malloc(sizeof(int16_t));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_int16_t(node_s->buf, 0);
        return (void*)val;     
    }
    else if(dt == UINT32_T || dt == UNSIGNED_INT || dt == UNSIGNED_LONG) {
        uint32_t *val = (uint32_t*)malloc(sizeof(uint32_t));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_uint32_t(node_s->buf, 0);
        return (void*)val;       
    }
    else if(dt == INT32_T || dt == SIGNED_INT || dt == INT || dt == SIGNED_LONG || dt == LONG) {
        int32_t *val = (int32_t*)malloc(sizeof(int32_t));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_int32_t(node_s->buf, 0);
        return (void*)val;     
    }
    else if(dt == UINT64_T || dt == UNSIGNED_LONG_LONG) {
        uint64_t *val = (uint64_t*)malloc(sizeof(uint64_t));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_uint64_t(node_s->buf, 0);
        return (void*)val;      
    }
    else if(dt == INT64_T || dt == SIGNED_LONG_LONG || dt == LONG_LONG) {
        int64_t *val = (int64_t*)malloc(sizeof(int64_t));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_int64_t(node_s->buf, 0);
        return (void*)val; 
    }
    else if(dt == DOUBLE) {
        double *val = (double*)malloc(sizeof(double));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_double(node_s->buf, 0);
        return (void*)val; 
    }
    else if(dt == FLOAT) {
        float *val = (float*)malloc(sizeof(float));
        
        if (val == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return NULL;
        }

        *val = buf_to_float(node_s->buf, 0);
        return (void*)val; 
    }
    else {
       fprintf(stderr, "Invalid DT try GetArr if you want to get an array.\n"); 
    }
    return NULL;
}
