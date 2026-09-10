
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        // Fix the largest side
        for (int k = n - 1; k >= 2; k--) {
            int left = 0;
            int right = k - 1;

            while (left < right) {
                if (nums[left] + nums[right] > nums[k]) {
                    // All indices [left, right-1] work with right and k
                    ans += right - left;
                    right--;
                } 
                else {
                    left++;
                }
            }
        }

        return ans;
    }
};
