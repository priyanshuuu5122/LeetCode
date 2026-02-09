// 1st method
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int>mp;
//         for(auto n: nums){
//             mp[n]++;
//         }
//         for(auto it:mp){
//             if(it.second>(nums.size()/2)) return it.first;
//         }
//         return -1;
        
//     }
// };
//2nd method 
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int candidate        = 0;
//         int count = 0;

//         for(int i = 0; i < nums.size(); i++) {
//             if(count == 0) {
//                 candidate = nums[i];
//             }

//             if(nums[i] == candidate) {
//                 count++;
//             } else {
//                 count--;
//             }
//         }
//         return candidate;
//     }
// };



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

