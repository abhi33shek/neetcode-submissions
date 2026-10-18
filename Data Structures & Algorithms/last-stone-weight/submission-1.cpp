
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());
        
        while (maxHeap.size() > 1) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = maxHeap.top(); maxHeap.pop();
            
            if (a != b) {
                maxHeap.push(a - b);
            }
        }
        
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};