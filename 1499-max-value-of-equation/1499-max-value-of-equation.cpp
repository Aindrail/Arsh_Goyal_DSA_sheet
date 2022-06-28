class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;	// {y - x, x}
            int ans = INT_MIN;
            for (const auto &p: points)
            {
                const int x = p[0],
                    y = p[1];
                while (!q.empty() && x - q.top().second > k) q.pop();
                if (!q.empty())
                    ans = max(ans, x + y + q.top().first);
                q.emplace(y - x, x);
            }
            return ans;
    }
};