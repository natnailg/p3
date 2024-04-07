//
// Created by natnail on 4/6/2024.
//

#ifndef P3_SEMANTICS_H
#define P3_SEMANTICS_H
#include "TreeNode.h"

void pre_order_traversal(node_t* root, int );
void input_into_memory(node_t* root);
void Symbol_Table_print(); //printing the table.
bool Table_check(node_t* identifier); // boolean check if it is already in memory
#endif //P3_SEMANTICS_H
