class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";

        for(int i = 0; i < s.size(); i++) {
            if(!result.empty() && result.back() == s[i]) {
                result.pop_back();
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
















// ✅ Line by Line Explanation
// ✅ Line 1:
// class Solution {


// ➡️ LeetCode me solution likhne ke liye Solution class banani hoti hai.

// ✅ Line 2:
// public:


// ➡️ public ka matlab: class ke andar jo functions hain, wo bahar se access ho sakte hain.

// ✅ Line 3:
// string removeDuplicates(string s) {


// ➡️ Function ka naam removeDuplicates hai
// ➡️ Input: string s
// ➡️ Output: string (final answer string return karega)

// ✅ Line 4:
// string ans = "";


// ➡️ ans ek empty string hai
// ➡️ Ye stack ki tarah behave karega (push/pop last se)

// ✅ Line 5:
// for(int i = 0; i < s.size(); i++) {


// ➡️ Loop string s ke har character pe chalega
// ➡️ i = 0 se start
// ➡️ i < s.size() tak chalega

// ✅ Line 6:
// if(!ans.empty() && ans.back() == s[i]) {


// ➡️ Ye check karta hai:

// !ans.empty()
// ✅ ans empty nahi hona chahiye (warna back() error dega)

// ans.back() == s[i]
// ✅ ans ka last character current character ke equal hai kya?

// ➡️ Agar equal hai → adjacent duplicate mil gaya

// ✅ Line 7:
// ans.pop_back();


// ➡️ pop_back() means ans ke last character ko delete kar do
// ➡️ Duplicate pair remove karne ke liye

// Example:
// ans = "ab" and current char = 'b'
// ➡️ last 'b' remove → ans = "a"

// ✅ Line 8:
// } else {


// ➡️ Agar duplicate nahi mila, toh else chalega

// ✅ Line 9:
// ans.push_back(s[i]);


// ➡️ push_back() means current character ko ans me add kar do
// ➡️ Like stack push

// Example:
// ans="a" current char = 'c'
// ➡️ ans="ac"

// ✅ Line 10:
// }


// ➡️ if-else block close

// ✅ Line 11:
// }


// ➡️ for loop close

// ✅ Line 12:
// return ans;


// ➡️ Final updated string return kar do
// ➡️ Jisme koi adjacent duplicates nahi honge

// ✅ Line 13:
// }


// ➡️ Function close

// ✅ Line 14:
// };


// ➡️ Class close

// 🔥 Small Dry Run Example

// Input: "abbaca"

// Start: ans=""

// 'a' → add → ans="a"

// 'b' → add → ans="ab"

// 'b' → duplicate → pop → ans="a"

// 'a' → duplicate → pop → ans=""

// 'c' → add → ans="c"

// 'a' → add → ans="ca"

// ✅ Output: "ca"
