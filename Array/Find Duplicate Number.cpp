// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

// Using Floyd's and Tortoise Algorithm 

https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Find the intersection point of two runners
        int tortoise = nums[0];
        int hare = nums[0];
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);
        
        // Find the "entrance" to the cycle
        tortoise = nums[0];
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};