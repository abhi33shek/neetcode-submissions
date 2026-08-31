class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) break;

            int j = i + 1, k = n - 1;
            int target = -nums[i];

            while (j < k) {
                int curr_sum = nums[j] + nums[k];
                if (curr_sum < target) {
                    j++;
                } else if (curr_sum > target) {
                    k--;
                } else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};