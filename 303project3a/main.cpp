#include <string>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include "Node.h"
#include <fstream>
#include "treetraversal.h"

using namespace std;
 
int main(){

	map<char, string> code;
	Node tree;
	ifstream input("morse.txt");
	treetraversal morsecode;
	morsecode.makeatree(tree, input, code);

	morsecode.decode(tree, " .... . ._.. ._.. ___ ");
	morsecode.decode(tree, ".__ ___ ._. ._.. _..");

	morsecode.encode(tree, "morsecode  5 ",code);


	cout << endl;
	system("pause");

	return 0;
}