class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }
    
private:
    void backtrack(vector<int>& candidates, int remain, int start,
                   vector<int>& path, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > remain) break;
            path.push_back(candidates[i]);
            backtrack(candidates, remain - candidates[i], i + 1, path, res);
            path.pop_back();
        }
    }
};