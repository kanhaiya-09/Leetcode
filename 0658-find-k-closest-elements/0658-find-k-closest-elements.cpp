class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        vector<int> helper;

        for(int i = 0; i < arr.size(); i++){
            helper.push_back(abs(x - arr[i]));
        }

        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < helper.size(); i++){

            pq.push({helper[i], arr[i]});

            if(pq.size() > k)
                pq.pop();
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};