class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k)
            return false;

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        int odd = 0;

        for (int x : freq) {
            if (x % 2 == 1)
                odd++;
        }

        return odd <= k;
    }
};