/*
Given head, the head of a linked list, determine if 
the linked list has a cycle in it.
There is a cycle in a linked list if there is some 
node in the list that can be reached again by 
continuously following the next pointer. 

Return true if there is a cycle in the linked list. 
Otherwise, return false.
*/


#include <cstddef>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		if (!head  ||  !head->next){
			return false;
		}
		
        ListNode *slow = head, *fast = head->next;

		while(fast != slow){
			if(!fast->next  ||  !fast->next->next){
				return false;
			}
			fast = fast->next->next;
			slow = slow->next;
		}

		return true;
    }
};