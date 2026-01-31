class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;
        char ans = letters[0];   // default for circular case

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];   // possible answer
                high = mid - 1;       // search left
            } else {
                low = mid + 1;        // search right
            }
        }
        return ans;
    }
};

