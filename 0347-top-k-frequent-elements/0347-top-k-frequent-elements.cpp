class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto x: mp){
            int ele = x.first;
            int freq = x.second;
            pair<int, int> p = { freq, ele };
            pq.push(p);
            if(pq.size()>k) pq.pop();
        }

        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};