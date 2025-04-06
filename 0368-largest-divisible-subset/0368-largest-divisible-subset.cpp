class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxSubsetSize = 1, maxSubsetIndex = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j; }}
            if (dp[i] > maxSubsetSize) {
                maxSubsetSize = dp[i];
                maxSubsetIndex = i; } }
        vector<int> result;
        while (maxSubsetIndex != -1) {
            result.push_back(nums[maxSubsetIndex]);
            maxSubsetIndex = parent[maxSubsetIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};