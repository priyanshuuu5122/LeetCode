class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() <= 1) return s;

        int start = 0, max_len = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Case 1: Odd length palindromes (centered at i)
            int len1 = expandAroundCenter(s, i, i);
            // Case 2: Even length palindromes (centered between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = std::max(len1, len2);
            
            if (len > max_len) {
                max_len = len;
                // Calculate the starting index of the palindrome substring
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, max_len);
    }

private:
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        // Returns the length of the palindrome found
        return right - left - 1;
    }
};