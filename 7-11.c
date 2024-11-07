#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

struct Node* findMax(struct Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (!root) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (!root->left) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* search(struct Node* root, int data) {
    if (!root || root->data == data) return root;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Find Minimum\n5. Find Maximum\n6. Inorder Traversal\n7. Count Nodes\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deleted %d\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                struct Node* found = search(root, value);
                printf("Search for %d: %s\n", value, found ? "Found" : "Not Found");
                break;

            case 4: {
                struct Node* min = findMin(root);
                printf("Minimum value: %d\n", min ? min->data : -1);
                break;
            }

            case 5: {
                struct Node* max = findMax(root);
                printf("Maximum value: %d\n", max ? max->data : -1);
                break;
            }

            case 6:
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Total number of nodes: %d\n", countNodes(root));
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
