// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
};

ListNode* list (int* array, int items)
{
	struct ListNode *head = (ListNode*) malloc(sizeof(ListNode));
	head->val = array[0];
	head->next = NULL;
	
	struct ListNode *last = head;
	for (int i = 1; i < items; i++) {
		last->next = (ListNode*) malloc(sizeof(ListNode));
		last = last->next;
		last->val = array[i];
		last->next = NULL;
	}
	
	return head;
}

void circle (ListNode* head, int pos)
{
	if (pos == -1) return;

	struct ListNode* to = NULL;
	int id = 0;

	while (head) {
		if (id == pos) to = head;
		if (head->next == NULL) {
			head->next = to;
			return;
		}
		head = head->next;
		id++;
	}
}

void print (ListNode* head)
{
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	
	cout << endl;
}

bool hasCycle (ListNode* head)
{
	if (!head || !head->next) return false;
	
	struct ListNode *one = head, *two = head;
	
	while (one && two) {
		one = one->next;
		two = two->next;
		if (two) two = two->next;
		if (one == two) return true;
	}
	
	return false;
}

int main ()
{
	int array[] = {3, 2, 0, -4}, pos = 1;
	int size = sizeof(array) / sizeof(int);
	struct ListNode* head = list(array,size);
	circle(head,pos); // print(head);
	cout << boolalpha << hasCycle(head) << endl;
    return 0;
}
