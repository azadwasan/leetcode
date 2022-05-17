#pragma once
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

template <class T>
struct TreeNode {
	TreeNode(T v, TreeNode<T>* l=nullptr, TreeNode<T>* r=nullptr) : val(v), left(l), right(r){}
	void addNode(T v) {
		if (v < val) {
			if (left) left->addNode(v);
			else {
				left = new TreeNode<T>{ v };
			}
		}
		else {
			if (right) right->addNode(v);
			else {
				right = new TreeNode<T>{ v };
			}
		}
	}

	static void InOrderParse(TreeNode<T>* root) {
		if (root->left) {
			InOrderParse(root->left);
		}
		std::cout << root->val << ", ";
		if (root->right) {
			InOrderParse(root->right);
		}
	}

	static void PreOrderParse(TreeNode<T>* root) {
		std::cout << root->val << ", ";
		if (root->left) {
			PreOrderParse(root->left);
		}
		if (root->right) {
			PreOrderParse(root->right);
		}
	}
	
	static void PostOrderParse(TreeNode<T>* root) {
		if (root->left) {
			PostOrderParse(root->left);
		}
		if (root->right) {
			PostOrderParse(root->right);
		}
		std::cout << root->val << ", ";
	}

	static void DepthFirstTraversal(TreeNode<T>* root) {
		std::stack<TreeNode<T>*> stack{};
		stack.push(root);
		while (!stack.empty()) {
			TreeNode<T>* node = stack.top();
			stack.pop();
			std::cout << node->val << ", ";
			if (node->left) {
				stack.push(node->left);
			}
			if (node->right) {
				stack.push(node->right);
			}
		}
	}

	static void BreathFirstTraversal(TreeNode<T>* root) {
		std::queue<TreeNode<T>*> queue;
		queue.push(root);
		while (!queue.empty()) {
			TreeNode<T>* node = queue.front();
			queue.pop();
			std::cout << node->val << ", ";
			if (node->left) queue.push(node->left);
			if (node->right) queue.push(node->right);
		}
	}

	T val;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

class BinaryTree {
public:
	static TreeNode<int>* CreateTree(const std::vector<int>& treeNums) {
		TreeNode<int>* root = new TreeNode<int>{ treeNums[0] };
		for (int i = 1; i < std::size(treeNums); i++) {
			root->addNode(treeNums[i]);
		}
		return root;
	}

	static void InOrderTraverse(TreeNode<int>* root) {
		std::cout << "****** InOrderTraverse *******" << std::endl;
		if (root) TreeNode<int>::InOrderParse(root);
		std::cout << std::endl<< "******************************" << std::endl;
	}

	static void PreOrderTraverse(TreeNode<int>* root) {
		std::cout << "****** PreOrderTraverse *******" << std::endl;
		if (root) TreeNode<int>::PreOrderParse(root);
		std::cout << std::endl << "******************************" << std::endl;
	}

	static void PostOrderTraverse(TreeNode<int>* root) {
		std::cout << "****** PostOrderTraverse *******" << std::endl;
		if (root) TreeNode<int>::PostOrderParse(root);
		std::cout << std::endl << "******************************" << std::endl;
	}

	static void BreathFirstTraverse(TreeNode<int>* root) {
		std::cout << "****** BreathFirstTraverse *******" << std::endl;
		if (root) TreeNode<int>::BreathFirstTraversal(root);
		std::cout << std::endl << "******************************" << std::endl;
	}

	static void DepthFirstTraverse(TreeNode<int>* root) {
		std::cout << "****** DepthFirstTraverse *******" << std::endl;
		if (root) TreeNode<int>::DepthFirstTraversal(root);
		std::cout << std::endl << "******************************" << std::endl;
	}

};