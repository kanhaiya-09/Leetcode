class Solution {
public:
    typedef pair<int, pair<int, int>> pip;
    vector<int> smallestRange(vector<vector<int>>& arr) {
         priority_queue<pip, vector<pip>, greater<pip>> pq;
         int mx = INT_MIN;
        for(int i=0; i<arr.size();i++){
            mx = max(mx, arr[i][0]);
            pq.push({arr[i][0], {i, 0}});
        }
        int mn = pq.top().first;
        int start = mn;
        int end = mx;
        while(true){
            
            int minRow = pq.top().second.first;
            int minColumn = pq.top().second.second;
            pq.pop();
            if(minColumn==arr[minRow].size()-1) break;
            int x = arr[minRow][minColumn+1];
            pq.push({x, {minRow, minColumn+1}});
            mx = max(mx, arr[minRow][minColumn+1]);
            mn = pq.top().first;
            if(mx-mn < end-start){
                end = mx;
                start = mn;
            }
        }
        return {start, end};
    }
};