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
	Node* traversepoint(Node &node, string input);

	void makeatree(Node &root, istream &input, map<char, string> &encodemap);
	void decode(Node node, string input);
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

//makes nodes to form binary tree from the traversal of the morse code elements.  traverse left if element = "."
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
	string current, word;
	
	cout << "Decoding the morse code " << input << " is: \n";
	try {
		while (morse_code >> current)
		{
			Node* ptr = &node;
			for (int i = 0; i < current.size(); i++)
			{
				if (ptr == nullptr) { throw current; }
				if (current[i] == '.') { ptr = ptr->left; }//go to left branch
				else { ptr = ptr->right; }//go to right branch
			}
			word+= ptr->getdata();
		}
		cout <<"'"<< word << "'"<<endl << endl;
	}//throw error if ptr is null(invalid morse code)
	catch (string e) { cout << "An invalid morse code at "+e+"\n\n"; }
}

//encodes word into morsecode
void treetraversal::encode(Node node, string input, map<char, string> &encodemap)
{
	//gets rid of any spaces before or after the word to encode
	istringstream letters(input);
	char current;

	cout << "The morse code for the word '" << input << "' is: ";
	while (letters >> current)
	{
		auto search = encodemap.find(current);//get map key
		if (search != encodemap.end()) {cout << search->second << " ";}//do if map key found
		else { cout << endl << current << " is not a valid character to encode, please use alphabet characters only."; break; }
	}
	cout << endl << endl;
}
