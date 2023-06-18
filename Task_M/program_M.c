#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int getHeight(struct Node* node) {
	if (node == NULL)
		return 0;
	return 1 + max(getHeight(node->left), getHeight(node->right));
}

int isBalanced(struct Node* node) {
	if (node == NULL)
		return 1;
	int leftHeight = getHeight(node->left);
	int rightHeight = getHeight(node->right);
	if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right))
		return 1;
	return 0;
}

void insertNode(struct Node** root, int value) {
	if (*root == NULL) {
		*root = createNode(value);
		return;
	}
	if (value < (*root)->value)
		insertNode(&(*root)->left, value);
	else
		insertNode(&(*root)->right, value);
}

int main() {
	struct Node* root = NULL;
	int value;
	scanf("%d", &value);
	while (value != 0) {
		insertNode(&root, value);
		scanf("%d", &value);
	}
	if (isBalanced(root))
		printf("YES");
	else
		printf("NO");
	return 0;
}