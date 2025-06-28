#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/next-greater-element-i/description/

// Brute force solution
// Use two loops to go through both arrays and find all greater elements
// TC: N1 * N2 = N^2 
class Solution_bf {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;

        // For each element in nums1, find each el in nums2
        for(int i = 0; i<nums1.size(); i++){
            
            for(int j = 0; j<nums2.size(); j++){
                // Once found, we search if there is a greater element than it.
                if(nums1[i] == nums2[j]){
                    for(int k = j; k<nums2.size(); k++){
                        if(nums2[k] > nums2[j]){
                            result.push_back(nums2[k]);
                            break;
                        }
                        // If no element was greater than it, we just add -1 to result.
                        if(k==nums2.size()-1) result.push_back(-1);
                    }
                }
            }
        }

        return result;
    }
};


// Optimal Monotonic stack solution
// We keep use a monotonic stack to track next greater element of every element in nums2 in a hashmap
// TC: N1 + N2
class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            map<int,int> mpp;
            vector <int> result;

            // Push every element to stack, if element to be pushed is greater than top, we pop the top
            // and hash next greater element of popped element.
            for(int i = 0; i<nums2.size(); i++){
                while(!st.empty() && st.top() < nums2[i]){
                    mpp[st.top()] = nums2[i];
                    st.pop();
                    
                }
                st.push(nums2[i]);
            }

            // Assign -1 to leftover elements who do not have a next greater element
            while( !st.empty()){
                mpp[st.top()] = -1;
                st.pop();
            }

            // Create final result array
            for(int i = 0; i<nums1.size(); i++){
                result.push_back(mpp[nums1[i]]);
            }

            return result;
        }
};