//
// Created by Natnail on 4/6/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "semantics.h"
#include "TreeNode.h"

const int max_size_table = 20;
char* table_array[max_size_table];
int table_index = 0;
bool  string_check = false;

//steps
// 1. lets first just travers it all ----------------- DONE.
// 2. store in the array -----------------------
// 3. use boolean to check if it already exists

void pre_order_traversal(node_t* root, int depth){
    if (root == NULL) {return;}

    if (root->Label == ' '){
//        printf("%*c %s, %s\n", depth * 3, ' ', root->token_id, root->token_instance);

        // we need to see if we encounter t1 and t2 toknes in the tree

        if(root->token_ID == 1){
            input_into_memory(root);
            printf("found a token %s, %s\n",  root->token_id, root->token_instance);

        }
        else if (root->token_ID == 2){
            input_into_memory(root);
            printf("found a token %s, %s\n", root->token_id, root->token_instance);

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


void input_into_memory(node_t* identifier){
    printf("entered the input_into_memory function \n");

    if(table_index < max_size_table){
        printf("entered the if statement in the input_into_memory\n");
//        char* strcpy(char* destination, const char* source);
//        strcpy(table_array[table_index], identifier->token_instance);
//        char *strdup(const char *s);

        table_array[table_index] = strdup(identifier->token_instance);
        table_index++;
    }
    memory_check_print(); //calling it to print.

}

void memory_check_print() {
    printf("memory filled with\n");
    for (int i = 0; i < table_index; i++) {
        printf("%s\n", table_array[i]);
    }
}
