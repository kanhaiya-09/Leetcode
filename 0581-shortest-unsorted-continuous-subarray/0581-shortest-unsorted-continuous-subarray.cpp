class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int left = -1, right = -1;

        // Find right boundary
        int maxSeen = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < maxSeen) {
                right = i;
            } else {
                maxSeen = nums[i];
            }
        }

        // Already sorted
        if (right == -1)
            return 0;

        // Find left boundary
        int minSeen = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > minSeen) {
                left = i;
            } else {
                minSeen = nums[i];
            }
        }

        return right - left + 1;
    }
};