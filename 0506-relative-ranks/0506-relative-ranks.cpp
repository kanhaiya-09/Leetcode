class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> mp; // Score , index
        int n = score.size();
        for(int i=0; i<score.size();i++){
           mp[score[i]] = i;
        }
        priority_queue <int> pq;
        for(int i=0; i<score.size();i++){
            pq.push(score[i]);
        }
        vector<string> ans(n);
        for(int i =0; i<n; i++){
            int x = mp[pq.top()];
            if(i==0) ans[x] = "Gold Medal";
            else if(i==1) ans[x] = "Silver Medal";
            else if(i==2) ans[x] = "Bronze Medal";
            else {
                ans[x] = to_string(i+1);
            }
            pq.pop();
        }
        return ans;
    }
};