class Solution {
public:
    int maximumScore(int a, int b, int c) {
        vector<int> piles = {a, b, c};

        sort(piles.begin(), piles.end());

        int sum = a + b + c;

        return min(sum / 2, piles[0] + piles[1]);
    }
};
