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
	void makeatree(Node &root, istream &input, map<char, string> &encodemap);
	Node* traversepoint(Node &node, string input);

	void decode(Node node,string input);
	void encode(Node node, string input, map<char, string> &encodemap);
};

//makes a 4 height binary tree, also map alphabet char to morsecode string  
void treetraversal::makeatree(Node &root, istream &input, map<char, string> &encodemap)
{
	char morsechar;
	string morsecode;
	Node *current;
	while (input.good())
	{
		input >> morsechar;
		input >> morsecode;
		encodemap[morsechar] = morsecode;
		current = traversepoint(root, morsecode);
		current->adddata(morsechar);
	}

}

//makes nodes from the traversal of the morse code elements.  traverse left if element = "."
//traverse right if element = "_"
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

//decodes morse code into word string
void treetraversal::decode(Node node,string input)
{
	//takes care of the space delimiter
	istringstream morse_code(input);
	string current;
	
	while(morse_code >> current)
	{
		Node* ptr = &node;
		for(int i =0; i<current.size();i++)
		{
			if(current[i]=='.') {ptr = ptr->left;}
			else {ptr = ptr->right;}
		}

		cout<<ptr->getdata();
	}

	cout << endl;
}


void treetraversal::encode(Node node, string input, map<char, string> &encodemap)
{
	istringstream letters(input);
	string current;
	char code;

	while (letters >> current)
	{
		for (int i = 0; i<current.size(); i++)
		{
			auto search = encodemap.find(current[i]);
			if (search != encodemap.end())
			{
				cout << search->second << " ";
			}
		}
	}
}
