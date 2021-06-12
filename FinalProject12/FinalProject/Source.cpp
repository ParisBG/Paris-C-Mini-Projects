#include "Header_H.h"
using namespace std;

void insertPrompt(MySearchTree&);
void searchPrompt(MySearchTree&);

int main() {
	vector<double> treeBranches;
	MySearchTree tree;

	//PROMPT USER FOR TREE VALUES
	insertPrompt(tree);

	//PUT VALUES IN ORDER
	tree.inOrder(treeBranches);

	//PRINT ALL TREE VALUES OUT IN ORDER
	cout << "MANUALLY PRINTING TREE IN ORDER (LOW-HIGH)..."<< endl;
	for (int i = 0; i < treeBranches.size(); i++) {
		cout << treeBranches[i] << endl;
	}

	//SEARCH TREE FOR SPECIFIC VALUES
	searchPrompt(tree);

	//SEARCH TREE FOR SPECIFIC VALUES
	searchPrompt(tree);

	//FIND OUT TREE SIZE
	cout << "TREE SIZE (NUMBER OF NODES) = "<< treeBranches.size() << endl << endl;

	//FIND OUT LEAF COUNT
	cout << "LEAF COUNT IS THE NUMBER OF NODES WITH BOTH A LEFT AND A RIGHT CHILD THAT ARE NULL" << endl;
	cout << "THE LEAF COUNT OF THIS TREE = " << tree.leafCount() << endl << endl;

	//FIND TREE HEIGHT
	cout << "THE HEIGHT OF THIS TREE = " << tree.treeHeight() << endl << endl;

	//CLONE THE TREE
	MySearchTree cloneTree(tree);
	vector<double> cloneBranches;
	cout << "A CLONE OF THE ORIGINAL TREE HAS BEEN CREATED!" << endl;
	cout << "SHOWING CLONE VALUES..." << endl;
	for (int i = 0; i < cloneBranches.size(); i++) {
		cout << cloneBranches[i] << endl;
	}

	//FIND THE MAX WIDTH OF THE TREE
	cout << endl <<"THE MAXIMUM WIDTH OF THIS TREE = " << tree.getMaxWidth() << endl;

	return 0;
}

void insertPrompt(MySearchTree &tree) {
	double userNum;
	cout << "WELCOME TO THE BINARY TREE PROGRAM!" << endl << endl;
	cout << "ENTER 5 RANDOM NUMBERS TO CREATE YOUR CUSTOM BINARY TREE" << endl;

	for (int i = 0; i < 5; i++) {
		cout << "#" << (i+1) << ": ";
		cin >> userNum;
		tree.insert(userNum);
	}
	cout << endl;
}

void searchPrompt(MySearchTree& tree) {
	double userNum;
	cout << endl << "ENTER ANY NUMBER TO SEARCH TO SEE IF THE TREE CONTAINS IT: ";
	cin >> userNum;

	if (tree.search(userNum)) {
		cout << endl << "The number " << userNum << " was found in the tree!" << endl;
	} else {
		cout << endl << "The number " << userNum << " was NOT found in the tree!" << endl;
	}

	cout << endl;
}





