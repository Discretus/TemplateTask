#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <functional>

template <typename T>
class binary_tree
{
private:
	typedef struct node {
		T value;
		node* left_child = nullptr;
		node* right_child = nullptr;
		node(T);
	} node;
	node* root_ = nullptr;
public:
	binary_tree();
	binary_tree(std::vector<T>);
	~binary_tree();
	
	void insert(T);
	void remove(T);
	
	std::vector<T> values();
	std::vector<T> leaves();
	
	bool search(T);

	operator std::string();
};

template <typename T>
binary_tree<T>::node::node(T value) : value(value) {};


template <typename T>
binary_tree<T>::binary_tree() {}

template <typename T>
binary_tree<T>::binary_tree(std::vector<T> values)
{
	for (auto value : values)
		insert(value);
}

template <typename T>
binary_tree<T>::~binary_tree()
{
	std::function<void(node*)> helper = [&helper](node* current) -> void
	{
		if (current->left_child != nullptr)
			helper(current->left_child);
		if (current->right_child != nullptr)
			helper(current->right_child);
		delete current;
	};
	helper(root_);
}

template <typename T>
void binary_tree<T>::insert(T value)
{
	std::function<void(node*, node*)> helper = [&helper](node* current, node* new_node) -> void
	{
		if (new_node->value >= current->value) {
			if (current->right_child != nullptr)
				helper(current->right_child, new_node);
			else
				current->right_child = new_node;
		}
		else
		{
			if (current->left_child != nullptr)
				helper(current->left_child, new_node);
			else
				current->left_child = new_node;
		}
	};
	node* new_node = new node(value);
	if (root_ == nullptr)
	{
		root_ = new_node;
		return;
	}
	helper(root_, new_node);
}

//template <typename T>
//void binary_tree<T>::remove(T)
//{
//	
//}

template <typename T>
std::vector<T> binary_tree<T>::values()
{
	std::list<T> result_list;
	std::function<void(node*)> helper = [&result_list, &helper](node* current) -> void
	{
		if (current->left_child != nullptr)
			helper(current->left_child);
		result_list.push_back(current->value);
		if (current->right_child != nullptr)
			helper(current->right_child);
	};
	helper(root_);
	std::vector<T> result_vector(std::begin(result_list), std::end(result_list));
	return result_vector;
}

template <typename T>
std::vector<T> binary_tree<T>::leaves()
{
	std::list<T> result_list;
	std::function<void(node*)> helper = [&result_list, &helper](node* current) -> void
	{
		if (current->left_child != nullptr)
			helper(current->left_child);
		if (current->right_child != nullptr)
			helper(current->right_child);
		if (current->left_child == nullptr && current->right_child == nullptr)
			result_list.push_back(current->value);
	};
	helper(root_);
	std::vector<T> result_vector(std::begin(result_list), std::end(result_list));
	return result_vector;
}
