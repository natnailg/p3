//
// Created by Natnail on 4/6/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#incude "semantics.h"

#include "TreeNode.h"

const int max_size_table = 20;
char table_array[max_size_table];
bool  string_check = false;
//steps
// 1. lets first just travers it all
// 2. use boolean when find same one
// 3. insert them into the table/array
void pre-order-traversal(node_t* root, int depth){
    if (root == NULL) {return;}

    if (root->Label == ' '){
        printf("%*c %s, %s\n", depth * 3, ' ', root->token_id, root->token_instance);

    }
    else{
        printf("lables: %c\n", root->Label);
    }


}