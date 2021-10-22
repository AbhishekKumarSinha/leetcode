#include<bits/stdc++.h>


using namespace std;


struct ListNode {
           int val;
           ListNode *next;
           ListNode() : val(0), next(nullptr) {}
           ListNode(int x) : val(x), next(nullptr) {}
           ListNode(int x, ListNode *next) : val(x), next(next) {}
       };

class Solution {
public:
  
    // 217. Contains Duplicate
    /*
    Given an integer array nums, 
    return true if any value appears at least twice in the array, 
    and return false if every element is distinct.

    Ex: 1
    Input: nums = [1,2,3,1]
    Output: true

    Ex: 2
    Input: nums = [1,2,3,4]
    Output: false

    Ex: 3
    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true

    */
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> duplicate;
        
        for(const auto& a : nums)
        {
            try
            {
                duplicate.at(a);
                return true;
            }
            catch(exception& e)
            {
                duplicate[a] = 1;
            }
        }
        return false;
    }

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

    // 53. Maximum Subarray
    /*
    Given an integer array nums, 
    find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    A subarray is a contiguous part of an array.

    Ex: 1
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.


    Ex: 2
    Input: nums = [1]
    Output: 1


    Ex: 3
    Input: nums = [1]
    Output: 1

    Constraints
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

    */

    int maxSubArray(vector<int>& nums) {
        
        long max_sub = nums[0];
        long current_sum = 0;
        
        for(const auto& a : nums)
        {
            if(current_sum < 0)
            {
                current_sum = 0;
            }
            
            current_sum += a;
            max_sub = max(max_sub, current_sum);
        }
        
        return max_sub;
    }


};

int main()
{
  Solution s;
  // 21. Merge Two Sorted Lists [ Easy ] [ Linked List ]
  // mergeTwoLists();

  // 217. Contains Duplicate [ Easy ] [ Array ]
  // containsDuplicate

  // 53. Maximum Subarray [ Easy ] [ Array ]
  // maxSubArray();


  return 0;
}
