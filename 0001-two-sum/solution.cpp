// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {

//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }

//         return {-1, -1};
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;  // value -> index

        for(int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];

            // check: kya required value pehle aa chuki hai?
            if(mp.find(left) != mp.end()) {
                return { mp[left], i };
            }

            // current value ko map me store karo
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

