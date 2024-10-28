#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct _LINKLIST{
    char val;
    _LINKLIST * left;
    _LINKLIST * right;
} node;

void append(node * left , node * right){

    left->right = right;
    right->left = left;

}

#endif