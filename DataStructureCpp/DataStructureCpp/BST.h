#pragma once

#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

template<typename Key, typename Value>
class BST
{
private:
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;

		Node(Key key, Value value)
		{
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};

	Node* root;
	int count;

#pragma region methods

	// Insert the new Node(key, value) into the binary search tree whose root is the node.
	// Return the root of the updated binary search tree
	Node* insert(Node* node, Key key, Value value)
	{
		if (node == NULL)
		{
			this->count++;
			return new Node(key, value);
		}

		if (key == node->key)
			node->value = value;
		else if (key < node->key)
			node->left = insert(node->left, key, value);
		else // key > node->key
			node->right = insert(node->right, key, value);

		return node;
	}

	// Find out whether the specified key is in the node-rooted binary search tree.
	bool contains(Node* node, Key key)
	{
		if (node == NULL)
			return false;

		if (node->key == key)
			return true;
		else if (key < node->key)
			return contains(node->left, key);
		else
			return contains(node->right, key);
	}

	// Find out the value of the specified key in the node-rooted binary search tree.
	Value* search(Node* node, Key key)
	{
		if (node == NULL)
			return NULL;

		if (node->key == key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

	void preOrder(Node* node)
	{
		if (node == NULL)
			return;

		cout << node->key << " ";
		preOrder(node->left);
		preOrder(node->right);
	}

	void inOrder(Node* node)
	{
		if (node == NULL)
			return;

		inOrder(node->left);
		cout << node->key << " ";
		inOrder(node->right);
	}

	void postOrder(Node* node)
	{
		if (node == NULL)
			return;

		postOrder(node->left);
		postOrder(node->right);
		cout << node->key << " ";
	}

	void levelOrder(Node* node)
	{
		if (node == NULL)
			return;
		queue<Node*> q;
		q.push(node);

		while (!q.empty())
		{
			Node* node = q.front();

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);

			cout << node->key << " ";
			q.pop();
		}

	}

	void destroy(Node* node)
	{
		if (node != NULL)
		{
			destroy(node->left);
			destroy(node->right);

			delete node;
			count--;
		}
	}

	Node* maximum(Node* node)
	{
		if (node == NULL)
			return NULL;

		/*
		if (node.right == NULL)
			return node;
		return minimum(node->right);
		*/
		Node* temp = node;
		while (temp->right != NULL)
			temp = temp->right;
		return temp;
	}

	Node* minimum(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->left == NULL)
			return node;
		return minimum(node->left);

		/*
		Node* temp = node;
		while (temp->left != NULL)
			temp = temp->left;
		return temp;
		*/
	}

	Node* removeMax(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->right == NULL)
		{
			Node* leftNode = node->left;
			this->count--;
			delete node;
			return leftNode;
		}
		node->right = removeMax(node->right);
		return node;
	}

	Node* removeMin(Node* node)
	{
		if (node == NULL)
			return NULL;
		/*
		if (node->left == NULL)
		{
			Node* rightNode = node->right;
			this->count--;
			delete node;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
		*/

		if (node->left == NULL)
		{
			Node* rightNode = node->right;
			delete node;
			this->count--;
			return rightNode;
		}

		Node* temp = node;
		Node* tempRoot = NULL;
		while (temp->left)
		{
			tempRoot = temp;
			temp = temp->left;
		}
		tempRoot->left = temp->right;
		delete temp;
		this->count--;
		return node;
	}

#pragma endregion methods

public:

#pragma region construction and deconstruction

	BST()
	{
		root = NULL;
		count = 0;
	}
	~BST()
	{
		destroy(this->root);
	}

#pragma endregion construction and deconstruction

#pragma region public methods

	int size()
	{
		return this->count;
	}

	bool isEmpty()
	{
		return this->count == 0;
	}

	void insert(Key key, Value value)
	{
		this->root = insert(this->root, key, value);
	}

	bool contains(Key key)
	{
		return contains(this->root, key);
	}

	Value* search(Key key)
	{
		return search(this->root, key);
	}

	void preOrder()
	{
		preOrder(this->root);
	}

	void inOrder()
	{
		inOrder(this->root);
	}

	void postOrder()
	{
		postOrder(this->root);
	}

	void levelOrder()
	{
		levelOrder(this->root);
	}

	// return the key of the minimum node
	Key minimun()
	{
		assert(this->count > 0);
		Node* minNode = minimum(this->root);
		return minNode->key;
	}

	// return the key of the maximum node
	Key maximun()
	{
		assert(this->count > 0);
		Node* maxNode = maximum(this->root);
		return maxNode->key;
	}

	// Remove the largest node from the binary search tree
	void removeMax()
	{
		if (this->root)
			removeMax(this->root);
	}

	// Remove the smallest node from the binary search tree
	void removeMin()
	{
		if (this->root)
			removeMin(this->root);
	}

#pragma endregion public methods

};
