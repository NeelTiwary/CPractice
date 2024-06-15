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

// Build a KD tree from a set of points
kd_node *build_tree(double **points, int n, int depth) {
    if (n <= 0) {
        return NULL;
    }
    int axis = depth % K;
    qsort(points, n, sizeof(double *), cmp);
    int mid = n / 2;
    kd_node *node = new_node(points[mid]);
    node->left = build_tree(points, mid, depth + 1);
    node->right = build_tree(points + mid + 1, n - mid - 1, depth + 1);
    return node;
}

// Create a KD tree from a set of points
kd_tree *create_tree(double **points, int n) {
    kd_tree *tree = (kd_tree *)malloc(sizeof(kd_tree));
    tree->root = build_tree(points, n, 0);
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
    return 0;
}
