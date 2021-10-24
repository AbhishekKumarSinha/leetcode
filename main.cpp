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


    // 1. Two Sum
    /*
    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.

    You can return the answer in any order.

    Ex: 1
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    Ex: 2
    Input: nums = [3,2,4], target = 6
    Output: [1,2]


    Ex: 3
    Input: nums = [3,3], target = 6
    Output: [0,1]
    
    Constraints
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

    */

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
      
        int size = nums.size();
        
        bool is_found = false;
        for(int i = 0; i < size; i++)
        {
            for(int j = i+1; j < size; j++)
      
        {
                long temp = nums[i] + nums[j];
                if(temp == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    is_found = true;
                    break;
                }
            }
            
            if(is_found)
                break;
        }
        
        return result;

    }

    /*
    88. Merge Sorted Array
    You are given two integer arrays nums1 and nums2, 
    sorted in non-decreasing order, 
    and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in non-decreasing order.

    The final sorted array should not be returned by the function, 
    but instead be stored inside the array nums1. 
    To accommodate this, nums1 has a length of m + n, 
    where the first m elements denote the elements that should be merged, 
    and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

    Example 1:

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
    
    Example 2:

    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].
    
    Example 3:

    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
    */

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> result;
        int i = 0, j = 0;
        for(; i < m && j < n;)
        {
            if(nums1[i] == nums2[j]) 
            {
                result.push_back(nums1[i]);
                result.push_back(nums2[j]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);   
                j++;
            }
        }
        while(i < m)        
        {
            result.push_back(nums1[i]);
            i++;
        }
        while(j < n)
        {
            result.push_back(nums2[j]);   
            j++;
        }
        
        nums1 = result;

    
    }

    /*
    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown
       1
      1 1
     1 2 1
    1 3 3 1
    1 4 6 4 1

    Example 1:

    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    Example 2:

    Input: numRows = 1
    Output: [[1]]
    */

    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        
        for(int i = 1 ; i <= numRows; i++)
        {
            vector<int> current;
            if(i == 1)
            {                
                current.push_back(1);
            }
            else if(i == 2)
            {
                current.push_back(1);
                current.push_back(1);
            }
            else if(i == 3)
            {
                current.push_back(1);
                current.push_back(2);
                current.push_back(1);
            }
            else //  4, 5, 6, 7,...
            {
                current.push_back(1);
                
                int s = res[i-2].size(); // 3
                
                // 0 , 1 , 
                for(int j = 0; j < s-1; j++)
                {
                    int n = res[i-2][j] + res[i-2][j+1];
                    current.push_back(n);
                }
                              
                current.push_back(1);
                
            }
            res.push_back(current);
            
        }
        return res;
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

  // 1. Two Sum
  // twoSum()

  // 88. Merge Sorted Array
  // merge()


  return 0;
}
