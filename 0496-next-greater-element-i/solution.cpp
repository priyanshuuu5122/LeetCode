class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for (int x : nums1) {

            stack<int> st;
            bool found = false;

            int i = 0;
            while (nums2[i] != x) i++;
            for (int j = i + 1; j < nums2.size(); j++)
                st.push(nums2[j]);

            int nextGreater = -1;
            while (!st.empty()) {
                if (st.top() > x)
                    nextGreater = st.top();
                st.pop();
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};

