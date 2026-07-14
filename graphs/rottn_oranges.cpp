#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            ans = max(ans, t);

            int dx[] = {1, 0, -1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++) {
                int nx = r + dx[i];
                int ny = c + dy[i];

                if(nx >= 0 && ny >= 0 &&
                   nx < grid.size() && ny < grid[0].size() &&
                   grid[nx][ny] == 1) {

                    q.push({{nx, ny}, t + 1});
                    grid[nx][ny] = 2;
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    Solution obj;
    cout << obj.orangesRotting(grid) << endl;

    return 0;
}