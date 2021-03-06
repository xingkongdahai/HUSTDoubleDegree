#include<iostream>
#include"node.h"

NODE::NODE(char* data)
{
	this->data = data;
	left = nullptr;
	right = nullptr;
}
NODE::NODE(char* data, NODE* left, NODE* right)
{
	this->data = data;
	this->left = left;
	this->right = right;
}
NODE::~NODE()
{
	delete data;
	delete left;
	delete right;
}