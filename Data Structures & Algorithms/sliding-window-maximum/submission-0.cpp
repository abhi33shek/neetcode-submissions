class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }
            
            if (i >= k - 1) {
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};