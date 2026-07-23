class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});

        }
        while(!pq.empty()){
            int x = pq.top().first;
            for(int i =0;i<x;i++){
                ans.push_back(pq.top().second);
            }
            pq.pop();
        }
        return ans;
    }
};