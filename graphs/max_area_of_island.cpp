#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cntarea(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 +
               cntarea(grid, i + 1, j, m, n) +
               cntarea(grid, i - 1, j, m, n) +
               cntarea(grid, i, j + 1, m, n) +
               cntarea(grid, i, j - 1, m, n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int curr = cntarea(grid, i, j, m, n);
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << obj.maxAreaOfIsland(grid) << endl;

    return 0;
}