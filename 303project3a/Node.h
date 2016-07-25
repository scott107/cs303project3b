#pragma once 
#include <string>
#include <iostream>
#include <sstream>

class Node
{
public:
	
	Node(char dat = ' ') { data = dat; Node* left = nullptr; Node* right = nullptr; }
	char getdata(){ return data; }
	void adddata(char dat) { data = dat; }
	bool isleftnull() { if (left == nullptr) return true; return false; }
	bool isrightnull() { if (right == nullptr) return true; return false; }

	char data;
	Node* left;
	Node* right;
};

