class Solution {
public:

    int countSubarrays(vector<int>& nums, int maxSum)
    {
        int count = 1;
        int sum = 0;

        for(int num : nums)
        {
            if(sum + num <= maxSum)
            {
                sum += num;
            }
            else
            {
                count++;
                sum = num;
            }
        }

        return count;
    }

    int splitArray(vector<int>& nums, int k)
    {
        int left = *max_element(nums.begin(), nums.end());

        int right = accumulate(nums.begin(), nums.end(), 0);

        while(left <= right)
        {
            int mid = left + (right-left)/2;

            int subarrays = countSubarrays(nums, mid);

            if(subarrays <= k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};