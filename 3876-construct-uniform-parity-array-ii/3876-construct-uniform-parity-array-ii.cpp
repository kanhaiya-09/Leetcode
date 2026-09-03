class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        // If minimum is odd, every even number can subtract
        // this minimum odd number to become odd.
        if (mn % 2 == 1) {
            return true;
        }

        // If minimum is even, every odd number needs a smaller
        // odd number to become even. But there is no smaller
        // odd number than the minimum, so impossible if odds exist.
        for (int x : nums1) {
            if (x % 2 == 1)
                return false;
        }

        return true;
    }
};

