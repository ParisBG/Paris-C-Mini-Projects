#ifndef Header_H
#define Header_H
#include <iostream>
using namespace std;


//Template that will create a static stack of any data type.
template <class T>
class MyStaticStack{

    private:
        T* mStackArray;
        int mTop;
        int mStackSize;

    public:
        MyStaticStack(int size) {
            mStackArray = new T[size];
            mStackSize = size;
            mTop = -1;
        }

        MyStaticStack(const MyStaticStack &obj) {
            if (obj.mStackSize == 0) {
                mStackArray = new T[obj.mStackSize];
            } else {
                mStackArray = nullptr;
            }

            mStackSize = obj.mStackSize;

            for (int i = 0; i < mStackSize; i++) {
                mStackArray[count] = obj.mStackArray[count];
            }

            mTop = obj.mTop;
        }

        ~MyStaticStack() {
            if (mStackSize > 0) {
                delete[] mStackArray;
            }
        }

        void push(T pushMe) {
            if (isFull()) {
                cout << "MY STACK IS ALREADY FULL!" << endl;
            } else {
                mTop++;
                mStackArray[mTop] = pushMe;
            }
        }

        void pop(T& popMe) {
            if (isEmpty()) {
                cout << "MY STACK IS EMPTY!" << endl;
            } else {
                popMe = mStackArray[mTop];
                mTop--;
            }
        }

        bool isEmpty() {
            bool status;
            if (mTop == -1) {
                status = true;
            } else {
                status = false;
            }

            return status;
        }

        bool isFull() {
            bool status;
            if (mTop == (mStackSize - 1)) {
                status = true;
            } else {
                status = false;
            }

            return status;
        }

        void show() {
            cout << mStackArray[mTop] << endl;
        }
};




//Template that will create a dynamic stack of any data type.
template <class T>
class MyDynamicStack {
private:
    struct StackNode {
        T mValue;      
        StackNode* mNext;
    };

    StackNode* mTop;

public:
   
    MyDynamicStack(){ mTop = 0;}
    ~MyDynamicStack() {
        StackNode* nodePtr, * nextNode;

        // Position nodePtr at the top of the stack.
        nodePtr = mTop;

        // Traverse the list deleting each node.
        while (nodePtr != 0) {
            nextNode = nodePtr->mNext;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }

    void push(T pushMe) {
        StackNode* newNode; // Pointer to a new node

        // Allocate a new node and store num there.
        newNode = new StackNode;
        newNode->mValue = pushMe;

        // If there are no nodes in the list
        // make newNode the first node.
        if (isEmpty()){
            mTop = newNode;
            newNode->mNext = 0;

            // Otherwise, insert NewNode before top.
        } else {
            newNode->mNext = mTop;
            mTop = newNode;
        }
    }

    void pop(T& popMe) {
        StackNode* temp; // Temporary pointer

       // First make sure the stack isn't empty.
        if (isEmpty()){
            cout << "The stack is empty.\n";

            // pop value off top of stack
        } else  {
            popMe = mTop->mValue;
            temp = mTop->mNext;
            delete mTop;
            mTop = temp;
        }
    }

    bool isEmpty() {
        bool status;

        if (!mTop)
            status = true;
        else
            status = false;

        return status;
    }

    void show() {
        cout << mTop->mValue << endl;
    }

};

#endif



