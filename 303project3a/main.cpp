#include <iostream>
#include <fstream>
#include "Node.h"
#include "treetraversal.h"

using namespace std;
 
void main(){

	map<char, string> code;
	treetraversal morsecode;
	Node tree;

	ifstream input("morse.txt");//check if file exist
	if (!input) { cout << "File does not exist\n"; system("pause"); exit(1); }
	morsecode.makeatree(tree, input, code);

	//morse decode function
	morsecode.decode(tree, " .... ...... ._.. ._.. ___ ");
	morsecode.decode(tree, ".__ ___ ._. ._.. _..");
	//morse encode function
	morsecode.encode(tree, "horse manure", code);
	morsecode.encode(tree, "horse5 manure", code);
	
	system("pause");
}