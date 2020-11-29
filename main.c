
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    struct node *right;
    struct node *left;
};

struct node *createNode(char *word) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->word = word;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node *insert(struct node *root, char *word) {
    if (root == NULL)
        return createNode(word);
    if (strcmp(word, root->word) < 0)
        root->left = insert(root->left, word);
    else if (strcmp(word, root->word) > 0)
        root->right = insert(root->right, word);
    return root;
}

struct node *search(struct node *root, char *word) {
    if (root == NULL || root->word == word)
        return root;
    else if (strcmp(word, root->word) < 0) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

void inOrder(struct node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%s \n", root->word);
        inOrder(root->right);
    }
}


int main() {


    struct node *root = NULL;
    root = insert(root, "zeynep");
    inOrder(root);

    char *words[4] = {"ali", "beyza", "ceyda", "deniz"};


    double P[4] = {0.1, 0.2, 0.4, 0.3};
    int const n = 4;

    double C[n][n];
    int R[n][n];








    for(int i = 0; i < n ; i++){
        for (int j = 0; j <n ; j++) {
            C[i][j] = 0;
            R[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        C[i][i] = P[i];
        R[i][i] = i;
    }


    for (int d = 1; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            double min_val = 9999999999999;
            int k_min = 0;
            for (int k = i; k <= j; k++) {
                double val = 0;
                if (k - 1 >= 0 && k + 1 < n) {
                    val = C[i][k - 1] + C[k + 1][j];
                } else{
                    continue;
                }

                if (val < min_val) {
                    min_val = val;
                    k_min = k;
                }
            }
            double sum = 0;
            for (int s = i; s <= j; s++) {
                sum += P[s];

            }
            R[i][j] = k_min;
            C[i][j] = min_val + sum;
        }
    }
}
