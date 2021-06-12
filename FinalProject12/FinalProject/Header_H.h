#ifndef Header_H
#define Header_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class MySearchTree{

	private:
        struct MyTreeNode {
            double value;
            MyTreeNode* left;
            MyTreeNode* right;
        };

        MyTreeNode* root;

        void inOrder(MyTreeNode* nodePtr, vector<double> &v) const {
            if (nodePtr) {
                inOrder(nodePtr->left, v);
                v.push_back(nodePtr->value);
                inOrder(nodePtr->right, v);
            }
        }

        bool search(double x, MyTreeNode* t){
            while (t) {
                if (t->value == x) {
                    return true;
                } else if (x < t->value) {
                    t = t->left;
                } else {
                    t = t->right;
                }
            }

            return false;
        }

        void determineBranch(MyTreeNode *&nodePtr, MyTreeNode *&newNode) {
            if (nodePtr == nullptr) {
                nodePtr = newNode;
            } else if (newNode->value < nodePtr->value){
                determineBranch(nodePtr->left, newNode);
            } else {
                determineBranch(nodePtr->right, newNode);
            }
        }

        double leafCount(MyTreeNode* t) {
            if (t == nullptr) {
                return 0;

            } else if (t->left == nullptr && t->right == nullptr) {
                return 1;

            } else {
                return (leafCount(t->left) + leafCount(t->right));
            }
        }
        double treeHeight(MyTreeNode* t) {
            double heightLeft, heightRight = 0;

            if (t == nullptr) {
                return 0;
            } else {
                heightLeft = treeHeight(t->left);
                heightRight = treeHeight(t->right);

                return max(heightLeft, heightRight) + 1;
            }
        }
        void copyTree(MyTreeNode*& thisRoot, MyTreeNode*& sourceRoot) {
            if (sourceRoot == NULL) {
                thisRoot = NULL;
            } else {
                thisRoot = new MyTreeNode;
                thisRoot->value = sourceRoot->value;
                copyTree(thisRoot->left, sourceRoot->left);
                copyTree(thisRoot->right, sourceRoot->right);
            }
        }

        /* Get width of a given level */
        double getWidth(MyTreeNode* root, int level) {

            if (root == NULL)
                return 0;

            if (level == 1)
                return 1;

            else if (level > 1)
                return getWidth(root->left, (level - 1)) + getWidth(root->right, (level - 1));
        }

	public:
        MySearchTree() {root = nullptr;}
        MySearchTree(MySearchTree &source){
            if (source.root == NULL)
                root = NULL;
            else
                copyTree(this->root, source.root);
        }
		void insert(double num){
            MyTreeNode *newNode = nullptr;

            newNode =  new MyTreeNode;
            newNode->value = num;
            newNode->left = newNode->right = nullptr;

            determineBranch(root, newNode);

        }
        void inOrder(vector<double> &v) const { inOrder(root,v); }
        bool search(double x) {return search(x, root);}
        double leafCount() {
            if (root == nullptr) {
                return 0;

            } else if (root->left == nullptr && root->right == nullptr){
                return 1;

            } else {
                    return (leafCount(root->left) + leafCount(root->right));
            }
        }
        double treeHeight() {
            double heightLeft, heightRight = 0;

            if (root == nullptr) {
                return 0;
            } else {
                heightLeft = treeHeight(root->left);
                heightRight = treeHeight(root->right);

                return max(heightLeft, heightRight) + 1;
            }
        }
        double getMaxWidth(){
            double maxWidth = 0;
            double width;
            double h = treeHeight(root);
            int i;

            /* Get width of each level and compare
                the width with maximum width so far */
            for (i = 1; i <= h; i++) {
                width = getWidth(root, i);
                if (width > maxWidth)
                    maxWidth = width;
            }

            return maxWidth;
        } 
};

#endif

