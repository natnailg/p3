//
// Created by Natnail on 4/6/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semantics.h"
#include "TreeNode.h"

const int max_size_table = 20;
char table_array[max_size_table];
bool  string_check = false;

struct Token tokens;
//steps
// 1. lets first just travers it all
// 2. store in the array
// 3. use boolean to check if it already exists

void pre_order_traversal(node_t* root, int depth){
    if (root == NULL) {return;}

    if (root->Label == ' '){
//        printf("%*c %s, %s\n", depth * 3, ' ', root->token_id, root->token_instance);

        // we need to see if we encounter t1 and t2 toknes in the tree
        if(root->token_id == "T1 token"){
            printf("%%s, %s\n",  root->token_id, root->token_instance);
        }

        else if (root->token_id == "T2 token"){
            printf("%s, %s\n", root->token_id, root->token_instance);

        }

    }
    else{
        printf("lables: %c\n", root->Label);
    }

    // Recursively traverse left, center, right, far_right subtree
    pre_order_traversal(root->left, depth + 1);

    pre_order_traversal(root->center, depth + 1);
    // Recursively traverse right subtree
    pre_order_traversal(root->right, depth + 1);

    pre_order_traversal(root->far_right, depth + 1);
}