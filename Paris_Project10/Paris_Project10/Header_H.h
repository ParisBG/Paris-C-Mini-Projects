#ifndef Header_H
#define Header_H
#include <iostream> 

using namespace std;


class MyLinkedList {

    public:
		struct ListNode{
			ListNode(double val, ListNode* nxt = NULL) {
				mData = val;
				mNext = nxt;
			}

			double mData;
			ListNode* mNext;
	
		};

		ListNode* mHead;

		MyLinkedList() { mHead = NULL; }
		MyLinkedList(const MyLinkedList& original) {
			mHead = copyList(original.mHead);
		}
		~MyLinkedList() {
			ListNode* pt = mHead;

			while (pt != NULL) {
				ListNode* trash = pt;
				pt = pt->mNext;
				delete trash;
			}
		}

		void addNode(double x) {
			if (mHead == NULL) {
				mHead = new ListNode(x);
			} else {
				mHead = new ListNode(x, mHead);
			}
			cout << "\"" << x << "\" " << " added successfully!" << endl;

		}
		bool checkNode(double x) {
			if (mHead == NULL)
				return false;
			else
			{
				ListNode* pt;
				while (pt != NULL)
				{
					if (pt->mData == x)
						return true;
					pt = pt->mNext;
				}
				return false;
			}
		}
		void print() {
			ListNode* pt = mHead;
			while (pt != NULL) {
				cout << pt->mData << "  " << endl;
				pt = pt->mNext;
			}

			cout << endl;
		}
		int recursiveCheck(double x) {
			if (mHead == NULL)
				return -1;
			else
			{
				int pos = 0;
				ListNode* aptr = mHead;
				while (aptr != NULL)
				{
					if (aptr->mData == x)
						return pos;
					aptr = aptr->mNext;
					pos++;
				}
				return -1;
			}
		}
		void remove(double x) {
			if (mHead == NULL)
				return;
			else
			{
				ListNode* present, * past{};
				present = mHead;
				while (present != NULL && present->mData != x)
				{
					past = present;
					present = present->mNext;
				}
				if (present)
				{
					past->mNext = present->mNext;
					delete present;
				}
			}

			cout << "Successfully removed " << "\"" << x << "\"" << " from the list!" << endl;

		}
		void rearrangeList() {
			if (mHead == NULL)
				return;
			else
			{

				ListNode* minElem, * present, * scan, * past;
				bool swap;
				scan = mHead;
				past = scan->mNext;
				do
				{
					swap = false;
					for (present = past->mNext; present != NULL; present = present->mNext)
					{
						if (past->mData > present->mData)
						{

							past->mNext = past->mNext->mNext;
							scan->mNext = present;
							present->mNext = past;
							swap = true;
						}
						scan = past;
						past = present;
					}
				} while (swap);
			}

			cout << "List re-arranged successfully!" << endl;

		}


private:
	static ListNode* copyList(ListNode* aList) {
		cout << "List copied successfully!" << endl;

		if (aList == NULL)
			return NULL;
		else {
			ListNode* tailCopy = copyList(aList->mNext);
			return new ListNode(aList->mData, tailCopy);
		}
	}

};


#endif