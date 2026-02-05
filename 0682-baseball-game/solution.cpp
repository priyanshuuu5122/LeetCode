class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        for (string op : operations) {
            if (op == "C") {
                st.pop_back();
            }
            else if (op == "D") {
                st.push_back(2 * st.back());
            }
            else if (op == "+") {
                int n = st.size();
                st.push_back(st[n-1] + st[n-2]);
            }
            else {
                st.push_back(stoi(op)); 
            }
        }

        int sum = 0;
        for (int x : st) sum =sum + x;
        return sum;
    }
};



















// ✅ 1) Class banayi
// class Solution {


// ➡️ Ye LeetCode ka standard format hai, iske andar hum apna function likhte hain.

// ✅ 2) Public section
// public:


// ➡️ public ka matlab: function ko outside access kar sakte hain (LeetCode call karega).

// ✅ 3) Function start
// int calPoints(vector<string>& operations) {


// ➡️ Ye function operations array lega (strings ki list)
// ➡️ Aur final answer integer me return karega.

// ✅ 4) Stack jaisa vector
// vector<int> st;


// ➡️ Ye vector valid scores store karega
// ➡️ Ye stack ki tarah kaam karega (push/pop last se).

// Example: st = [5,10,15]

// ✅ 5) Loop har operation ke liye
// for (string op : operations) {


// ➡️ Ye loop operations ke har element pe chalega
// ➡️ op me ek ek string aayegi like "5", "D", "+", "C"

// 🟡 Condition 1: "C"
// if (op == "C") {
//     st.pop_back();
// }


// ➡️ Agar op "C" hai to last score cancel karna hai
// ➡️ pop_back() vector ka last element hata deta hai

// Example: st = [5,2]
// C → st = [5]

// 🟡 Condition 2: "D"
// else if (op == "D") {
//     st.push_back(2 * st.back());
// }


// ➡️ "D" ka matlab: last score ka double add karo
// ➡️ st.back() = last element deta hai
// ➡️ push_back() new score add karta hai

// Example: st = [5]
// D → double = 10
// st = [5,10]

// 🟡 Condition 3: "+"
// else if (op == "+") {
//     int n = st.size();
//     st.push_back(st[n-1] + st[n-2]);
// }


// ➡️ "+" ka matlab: last 2 valid scores ka sum add karo

// Step by step:
// int n = st.size();


// ➡️ n me vector ka size store kar rahe hain

// st.push_back(st[n-1] + st[n-2]);


// ➡️ st[n-1] = last score
// ➡️ st[n-2] = second last score
// ➡️ dono ka sum push kar diya

// Example: st = [5,10]
// + → 5+10 = 15
// st = [5,10,15]

// 🟡 Condition 4: Number
// else {
//     st.push_back(stoi(op));
// }


// ➡️ Agar "C", "D", "+" nahi hai
// ➡️ to op ek number hoga like "5" or "-2"

// stoi(op) kya karta hai?

// ➡️ String ko integer me convert karta hai
// "5" → 5
// "-2" → -2

// Example: op = "7"
// st.push_back(7)

// ✅ Loop end
// }


// ➡️ Sare operations process ho gaye.

// ✅ Total sum nikalna
// int sum = 0;


// ➡️ sum variable banaya starting 0 se

// Valid scores add karna
// for (int x : st) sum += x;


// ➡️ st ke har score ko sum me add kar diya

// Example: st = [5,10,15]
// sum = 0+5+10+15 = 30

// ✅ Final answer return
// return sum;


// ➡️ Total score return kar diya

// ✅ Function end
// }
// };

// ⭐ Short Summary (1 line)

// ✔️ Hum vector ko stack ki tarah use karke scores store karte hain, aur end me sabka sum return kar dete hain.
