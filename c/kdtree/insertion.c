#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 2

typedef struct kd_node_t {
    double x[K];
    struct kd_node_t *left, *right;
} kd_node;

typedef struct {
    kd_node *root;
} kd_tree;

// Calculate distance between two points
double dist(double *a, double *b) {
    double res = 0;
    for (int i = 0; i < K; i++) {
        double diff = a[i] - b[i];
        res += diff * diff;
    }
    return sqrt(res);
}

// Sort points along a specific axis
int cmp(const void *a, const void *b) {
    return ((double *)a)[0] > ((double *)b)[0] ? 1 : -1;
}

// Create a new node with given coordinates
kd_node *new_node(double *x) {
    kd_node *node = (kd_node *)malloc(sizeof(kd_node));
    for (int i = 0; i < K; i++) {
        node->x[i] = x[i];
    }
    node->left = node->right = NULL;
    return node;
}

// Insert a new node into the KD tree
kd_node *insert(kd_node *node, double *x, int depth) {
    if (node == NULL) {
        return new_node(x);
    }
    int axis = depth % K;
    if (x[axis] < node->x[axis]) {
        node->left = insert(node->left, x, depth + 1);
    } else {
        node->right = insert(node->right, x, depth + 1);
    }
    return node;
}

// Create a KD tree from a set of points
kd_tree *create_tree(double **points, int n) {
    kd_tree *tree = (kd_tree *)malloc(sizeof(kd_tree));
    tree->root = NULL;
    for (int i = 0; i < n; i++) {
        tree->root = insert(tree->root, points[i], 0);
    }
    return tree;
}

int main() {
    double points[][K] = {{2,3}, {5,4}, {9,6}, {4,7}, {8,1}, {7,2}};
    int n = sizeof(points) / sizeof(points[0]);
    double **point_ptrs = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        point_ptrs[i] = points[i];
    }
    kd_tree *tree = create_tree(point_ptrs, n);
    // Search for the nearest neighbor of the query point (6, 2)
    double query_point[] = {6, 2};
    // search(tree, query_point, 2);
    tree->root = insert(tree->root, new_node->x, 0);
    return 0;
}

