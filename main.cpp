#include<iostream>

using namespace std;


class Solution {
public:
  
    // 21. Merge Two Sorted Lists
    /*
    Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
    Ex: 1
    Input: l1 = [1,2,4], l2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    Ex: 2
    Input: l1 = [], l2 = []
    Output: []
    Ex: 3
    Input: l1 = [], l2 = [0]
    Output: [0]
    */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      
      /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
        
        ListNode* head = nullptr;
        
        ListNode* previous = nullptr;

        
        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val)
            {
                ListNode* current = new ListNode(l1->val);
                
                if(previous == nullptr)
                {
                    previous = current;    
                }
                else
                {
                    previous->next = current;
                    previous = current;
                }
                
                l1  = l1->next;
                
                if(head == nullptr)
                {
                    head = current;
                }
            }
            else
            {
                ListNode* current = new ListNode(l2->val);
                if(previous == nullptr)
                {
                    previous = current;    
                }
                else
                {
                    previous->next = current;
                    previous = current;
                }
                
                l2 = l2->next;
                
                if(head == nullptr)
                {
                    head = current;
                }
            }
            
           
        }
        
        if(l1 != nullptr)
        {
            //cout << "L1 != NULL" << endl;
            while(l1 != nullptr)
            {
                ListNode* current = new ListNode(l1->val);
                if(previous == nullptr)
                {
                    previous = current;
                }
                else
                {
                    previous->next = current;
                    previous = current;
                }
                
                if(head == nullptr)
                {
                    head = current;
                }
                
                l1 = l1->next;
            }
        }
        
        if(l2 != nullptr)
        {
            //cout << "L2 != NULL" << endl;
            while(l2 != nullptr)
            {
                ListNode* current = new ListNode(l2->val);
                cout << current->val << endl;
                
                if(previous == nullptr)
                {
                    previous = current;
                }
                else
                {
                    previous->next = current;
                    previous = current;
                }
                
                if(head == nullptr)
                {
                    head = current;
                }
                
                l2 = l2->next;
            }
        }
        return head;
        
    }
};

int main()
{
  Solution s;
  // 21. Merge Two Sorted Lists [ Easy ] [ Linked List ]
  // mergeTwoLists();
  return 0;
}
