#include <stdio.h>
#include <stdlib.h>

#define k 2  

typedef struct node_t {
    int data[k];
    struct node_t* left;
    struct node_t* right;
} node;


node* new_node(int data[k]) {
    node* new_node = (node*)malloc(sizeof(node));
    for (int i = 0; i < k; i++) {
        new_node->data[i] = data[i];
    }
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// recursive function to insert a new node into the KD tree
node* insert_node(node* root, int data[k], int depth) {
    if (root == NULL) {
        return new_node(data);
    }
    int split_dim = depth % k;
    if (data[split_dim] < root->data[split_dim]) {
        root->left = insert_node(root->left, data, depth + 1);
    } else {
        root->right = insert_node(root->right, data, depth + 1);
    }
    return root;
}

// main function to create a KD tree from an array of data points
node* create_kd_tree(int data_points[][k], int num_points) {
    node* root = NULL;
    for (int i = 0; i < num_points; i++) {
        root = insert_node(root, data_points[i], 0);
    }
    return root;
}

// Insert a new point into a KD tree
void insert_node(kd_tree *tree, double *x) {
    kd_node *node = new_node(x);
    kd_node **p = &tree->root;
    int depth = 0;
    while (*p) {
        int axis = depth % K;
        if (x[axis] < (*p)->x[axis]) {
            p = &(*p)->left;
        } else {
            p = &(*p)->right;
        }
        depth++;
    }
    *p = node;
}
int main() {
    int data_points[][k] = {{2, 3}, {5, 4}, {9, 6}, {4, 7}, {8, 1}, {7, 2}};
    int num_points = sizeof(data_points) / sizeof(data_points[0]);
    node* root = create_kd_tree(data_points, num_points);
    return 0;
}
