class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        int freq[128] = {0}; 
        
        for (char ch : s) {
            freq[ch]++;
            if (freq[ch] % 2 == 1) {
                oddCount++;
            } else {
                oddCount--;
            }
        }
        
        if (oddCount > 1) {
            return s.length() - oddCount + 1;
        }
        
        return s.length();
    }
};
