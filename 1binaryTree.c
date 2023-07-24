#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// AVL Tree Node
struct Node {
    int data;
    struct Node* L;
    struct Node* R;
    int height;
};

// Function to find the height of a node
int heighttree(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Function to create a new node
struct Node* create(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->L = NULL;
    node->R = NULL;
    node->height = 1;
    return node;
}

// Function for right rotation
struct Node* rightrotate(struct Node* y) {
    struct Node* x = y->L;
    struct Node* temp = x->R;

    x->R = y;
    y->L = temp;

    y->height = max(heighttree(y->L), heighttree(y->R)) + 1;
    x->height = max(heighttree(x->L), heighttree(x->R)) + 1;

    return x;
}

// Function for left rotation
struct Node* leftrotate(struct Node* x) {
    struct Node* y = x->R;
    struct Node* temp = y->L;

    y->L = x;
    x->R = temp;

    x->height = max(heighttree(x->L), heighttree(x->R)) + 1;
    y->height = max(heighttree(y->L), heighttree(y->R)) + 1;

    return y;
}

// Function to check the balance factor
int check_balance(struct Node* node) {
    if (node == NULL)
        return 0;

    return heighttree(node->L) - heighttree(node->R);
}

// Function for inserting nodes
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) {
        return create(data);
    }
    if (data < node->data) {
        node->L = insertNode(node->L, data);
    } else if (data > node->data) {
        node->R = insertNode(node->R, data);
    } else {
        return node;
    }

    node->height = 1 + max(heighttree(node->L), heighttree(node->R));

    int balance = check_balance(node);

    // LL Case
    if (balance > 1 && data < node->L->data)
        return rightrotate(node);

    // RR Case
    if (balance < -1 && data > node->R->data)
        return leftrotate(node);

    // LR Case
    if (balance > 1 && data > node->L->data) {
        node->L = leftrotate(node->L);
        return rightrotate(node);
    }

    // RL Case
    if (balance < -1 && data < node->R->data) {
        node->R = rightrotate(node->R);
        return leftrotate(node);
    }

    return node;
}

// Function to store the AVL tree nodes in an inorder traversal
void storeInorder(struct Node* node, FILE* file) {
    if (node == NULL)
        return;

    storeInorder(node->L, file);
    fprintf(file, "%d ", node->data);
    storeInorder(node->R, file);
}

// Function to generate random numbers and store them in a file
void generateRandomNumbers(FILE* file, int n) {
    srand(time(NULL));
    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++)
        {
        int num = rand();
        fprintf(file, "%d\t", num);
    }
}

int main() {
    FILE* fptr, *fp1;
    int n,data;

    fptr = fopen("0random.txt", "w");
    if (fptr == NULL) {
        printf("Error opening random.txt file\n");
        exit(1);
    }

    printf("Enter the value of n: ");
    scanf("%d", &n);
    generateRandomNumbers(fptr, n);
    fclose(fptr);

    fp1 = fopen("1answer.txt", "w");

    struct Node* root = NULL;
    fptr = fopen("0random.txt", "r");
    if (fptr == NULL) {
        printf("Error opening 0random.txt file\n");
        exit(1);
    }

    fscanf(fptr, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(fptr, "%d", &data);
        root = insertNode(root, data);
    }

    fprintf(fp1, "Inorder traversal: ");
    storeInorder(root, fp1);
    fprintf(fp1, "\n");
    fclose(fp1);
    fclose(fptr);

    return 0;
}
