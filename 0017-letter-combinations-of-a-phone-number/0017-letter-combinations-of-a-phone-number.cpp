class Solution {
public:
    vector<string> ans;

    string mp[10] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int index, string &digits, string &current) {
        // All digits processed
        if (index == digits.size()) {
            ans.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (char ch : mp[digit]) {
            current.push_back(ch);

            solve(index + 1, digits, current);

            current.pop_back();  // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        string current;
        solve(0, digits, current);

        return ans;
    }
};