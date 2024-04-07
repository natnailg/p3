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
// 2. store in the array -----------------------  DONE.
// 3. use boolean to check if it already exists ---- verify.

void pre_order_traversal(node_t* root, int depth){
    if (root == NULL) {return;}

    if (root->Label == ' '){
//        printf("%*c %s, %s\n", depth * 3, ' ', root->token_id, root->token_instance);

        // we need to see if we encounter t1 and t2 toknes in the tree

        if(root->token_ID == 1){
            printf("%*c %s, %s\n", depth * 3, ' ', root->token_id, root->token_instance);

        }
        else if (root->token_ID == 2){
            Table_check(root);
            if(!string_check) {
                input_into_memory(root);
            }
        }else{
            printf("Instances found %s\n", root->token_instance);
        }

    }
//    else{
//        printf("lables: %c\n", root->Label);
//    }

    // Recursively traverse left, center, right, far_right subtree
    pre_order_traversal(root->left, depth + 1);

    pre_order_traversal(root->center, depth + 1);
    // Recursively traverse right subtree
    pre_order_traversal(root->right, depth + 1);

    pre_order_traversal(root->far_right, depth + 1);
}


void input_into_memory(node_t* identifier){

    if(table_index < max_size_table){
//        char *strdup(const char *s);
        table_array[table_index] = strdup(identifier->token_instance);
        table_index++;
    }


}
/// function to check if it is already in the symbols table or not
bool Table_check(node_t* identifier){
    int result;
    for (int i = 0; i < table_index; i++) {
        //strcmp(first_str, second_str );
        result = strcmp(table_array[i], identifier->token_instance);  // this means that it found it in the table
        if (result == 0) { // if in the table
            printf("inserted into the table %s\n", table_array[i]);
            string_check = true;
            return string_check;
        }else{ // if not in the table
            printf("It is not declared in the table %s\n", identifier->token_instance);
//            string_check = false;
        }
    }

    return string_check;
}



//memory print
void Symbol_Table_print() {
    printf("Symbol Table\n");
    for (int i = 0; i < table_index; i++) {
        printf("%d\t%s\n", i, table_array[i]);
    }
}




//https://www.geeksforgeeks.org/strcpy-in-c/
//https://www.geeksforgeeks.org/strdup-strdndup-functions-c/
//https://www.geeksforgeeks.org/strcmp-in-c/    0 = str is identical >0 not matching