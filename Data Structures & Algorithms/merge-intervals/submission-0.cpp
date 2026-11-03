class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        for (auto& cur : intervals) {
            if (result.empty() || result.back()[1] < cur[0]) {
                // No overlap with the last merged interval
                result.push_back(cur);
            } else {
                // Overlap (including touching endpoints): extend the end
                result.back()[1] = max(result.back()[1], cur[1]);
            }
        }
        return result;
    }
};