class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // insert all stones
        for(int stone : stones) {
            pq.push(stone);
        }

        while(pq.size() > 1) {
            int y = pq.top(); pq.pop(); // heaviest
            int x = pq.top(); pq.pop(); // second heaviest

            if(x != y) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};