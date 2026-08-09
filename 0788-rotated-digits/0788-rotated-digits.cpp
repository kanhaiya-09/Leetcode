class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;

        for (int x = 1; x <= n; x++) {
            int num = x;
            bool valid = true;
            bool changed = false;

            while (num > 0) {
                int digit = num % 10;
                num /= 10;

                if (digit == 2 || digit == 5 ||
                    digit == 6 || digit == 9) {
                    changed = true;
                }
                else if (digit == 0 || digit == 1 || digit == 8) {
                   
                }
                else {
                
                    valid = false;
                    break;
                }
            }

            if (valid && changed) {
                ans++;
            }
        }

        return ans;
    }
};
