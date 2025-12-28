#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note: Keeping the typedef, but using 'struct Node' in function headers 
// for maximum compatibility with strict environments.
typedef struct Node {
    int data;
    struct Node *l, *r;
} Node;

// Changed return type and parameter type to struct Node*
struct Node* newNode(int v) {
    // Also changed variable declaration inside the function
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = v;
    t->l = t->r = NULL;
    return t;
}

// Changed return type and parameter type to struct Node*
struct Node* insertBST(struct Node* root, int v) {
    if (root == NULL) return newNode(v);
    if (v < root->data) root->l = insertBST(root->l, v);
    else if (v > root->data) root->r = insertBST(root->r, v);
    return root;
}

// Changed parameter type to struct Node*
void inorder(struct Node* t) {
    if (!t) return;
    inorder(t->l);
    printf("%d ", t->data);
    inorder(t->r);
}

// Changed parameter type to struct Node*
void preorder(struct Node* t) {
    if (!t) return;
    printf("%d ", t->data);
    preorder(t->l);
    preorder(t->r);
}

// Changed parameter type to struct Node*
void postorder(struct Node* t) {
    if (!t) return;
    postorder(t->l);
    postorder(t->r);
    printf("%d ", t->data);
}

// Changed return type and parameter type to struct Node*
struct Node* searchBST(struct Node* root, int k) {
    if (!root) return NULL;
    if (k == root->data) return root;
    if (k < root->data) return searchBST(root->l, k);
    return searchBST(root->r, k);
}

int main() {
    int Q;
    if (scanf("%d", &Q) != 1) return 0;
    getchar();

    // Changed declaration to struct Node*
    struct Node* root = NULL;

    while (Q--) {
        int op;
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            int N;
            scanf("%d", &N);
            getchar();

            char line[4096];
            if (fgets(line, sizeof(line), stdin)) {
                char* p = line;
                int count = 0;
                while (count < N) {
                    int val, used;
                    if (sscanf(p, " %d%n", &val, &used) == 1) {
                        root = insertBST(root, val);
                        p += used;
                        count++;
                    } else break;
                }
            }
        }
        else if (op == 2) {
            if (!root) {
                printf("Tree is empty.\n");
            } else {
                printf("The Inorder display: ");
                inorder(root);
                printf("\n");
                printf("The Preorder display: ");
                preorder(root);
                printf("\n");
                printf("The Postorder display: ");
                postorder(root);
                printf("\n");
            }
        }
        else if (op == 3) {
            int K;
            scanf("%d", &K);
            getchar();
            // Changed declaration to struct Node*
            struct Node* r = searchBST(root, K);
            if (r) printf("The element %d is present.\n", K);
            else printf("The key %d is not present in the BST.\n", K);
        }
        else if (op == 4) break;
    }

    return 0;
}