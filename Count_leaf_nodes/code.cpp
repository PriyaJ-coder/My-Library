#include <bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

Node* newNode(int data){
	Node *new_node = new Node();
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

int getLeafCount(Node* root){
	queue<Node*> q;
	q.push(root);
	int count = 0;
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(temp->left == NULL && temp->right == NULL)
			count++;
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
	}
	return count;
}

int main(){
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	cout << "Leaf count of the tree is : "<< getLeafCount(root) << endl;
	return 0;
}