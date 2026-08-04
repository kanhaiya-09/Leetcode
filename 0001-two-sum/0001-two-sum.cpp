class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        int n=nums.size();
        for(int i=0; i<n;i++){
            int rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                ans.push_back(m[rem]);
                ans.push_back(i);
            }
            else m[nums[i]]=i;
        }
        return ans;
    }
};