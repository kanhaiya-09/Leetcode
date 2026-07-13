class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        auto cmp = [](pair<int,int> a, pair<int,int> b) {
            if(a.first == b.first)
                return a.second < b.second;   // larger element gets higher priority
            return a.first > b.first;         // smaller frequency gets higher priority
        };

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       decltype(cmp)> pq(cmp);

        for(auto x : mp) {
            int ele = x.first;
            int freq = x.second;
            pq.push({freq, ele});
        }

        while(!pq.empty()) {
            int freq = pq.top().first;
            int ele = pq.top().second;
            pq.pop();

            while(freq--) {
                ans.push_back(ele);
            }
        }

        return ans;
    }
};