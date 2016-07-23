#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <map>
#include "Node.h"


using namespace std; 

class treetraversal
{
public:
	treetraversal(){ ; }
	void makeatree(Node &root, istream &input, map<char, string> &encode);
	Node* traversepoint(Node &node, string input);
};

void treetraversal::makeatree(Node &root, istream &input, map<char, string> &encode)
{
	char morsechar;
	string morsecode;
	Node *current;
	while (input.good())
	{
		input >> morsechar;
		input >> morsecode;
		encode[morsechar] = morsecode;
		current = traversepoint(root, morsecode);
		current->adddata(morsechar);
	}

}

Node* treetraversal::traversepoint(Node &node, string input)
{
	Node* ptr = &node;
	char current;
	for (int i = 0; i < input.size(); i++)
	{
		current = input[i];
		if (current == '.')
		{
			if (ptr->isleftnull())
			{
				ptr->left = new Node();
				ptr = ptr->left;
			}
			else
				ptr = ptr->left;
		}
		else if (current == '_')
		{
			if (ptr->isrightnull())
			{
				ptr->right = new Node();
				ptr = ptr->right;
			}
			else
				ptr = ptr->right;
		}
	}
	return ptr;
}