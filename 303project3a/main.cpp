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

	system("pause");





	return 0;
}