class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        auto cmp = [&](pair<int,int> a, pair<int,int> b) {
            return arr[a.first] * arr[b.second] >
                   arr[b.first] * arr[a.second];
        };

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       decltype(cmp)> pq(cmp);

        int n = arr.size();

        for(int j = 1; j < n; j++)
            pq.push({0, j});

        while(--k){
            auto [i,j] = pq.top();
            pq.pop();

            if(i + 1 < j)
                pq.push({i+1, j});
        }

        auto [i,j] = pq.top();
        return {arr[i], arr[j]};
    }
};
