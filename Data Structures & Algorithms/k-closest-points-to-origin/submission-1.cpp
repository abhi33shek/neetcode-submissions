class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        while (true) {
            int p = partition(points, left, right);
            if (p == k - 1) break;
            if (p < k - 1) left = p + 1;
            else right = p - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

private:
    int dist(const vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left;
        int l = left + 1, r = right;
        
        while (l <= r) {
            if (dist(points[l]) > dist(points[pivot]) &&
                dist(points[r]) < dist(points[pivot])) {
                swap(points[l++], points[r--]);
            }
            if (dist(points[l]) <= dist(points[pivot])) l++;
            if (dist(points[r]) >= dist(points[pivot])) r--;
        }
        swap(points[pivot], points[r]);
        return r;
    }
};