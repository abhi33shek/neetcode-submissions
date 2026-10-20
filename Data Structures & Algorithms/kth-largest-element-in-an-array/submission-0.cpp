class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int left = 0, right = n - 1;
        
        while (true) {
            int pivotIdx = partition(nums, left, right);
            if (pivotIdx == target) {
                return nums[pivotIdx];
            } else if (pivotIdx < target) {
                left = pivotIdx + 1;
            } else {
                right = pivotIdx - 1;
            }
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int store = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[store]);
                store++;
            }
        }
        swap(nums[store], nums[right]);
        return store;
    }
};