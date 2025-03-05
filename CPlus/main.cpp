#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 1000;
int n, m;
vector<string> grid;
vector<vector<int> > dist;
vector<vector<pair<int, int > > > parent;
pair<int, int> start, endPos;

// 4 hướng di chuyển: (dx, dy) và ký tự tương ứng
vector< pair<int, int> > directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dirChar = {'L', 'R', 'U', 'D'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}

bool bfs() {
    queue<pair<int, int> > q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // Nếu tìm thấy đích, dừng BFS
        if (make_pair(x, y) == endPos) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    return false;
}

string getPath() {
    string path;
    pair<int, int> cur = endPos;

    while (cur != start) {
        pair<int, int> prev = parent[cur.first][cur.second];

        for (int i = 0; i < 4; i++) {
            if (prev.first + directions[i].first == cur.first &&
                prev.second + directions[i].second == cur.second) {
                path += dirChar[i];
                break;
            }
        }
        cur = prev;
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') endPos = {i, j};
        }
    }

    if (bfs()) {
        cout << "YES\n";
        cout << dist[endPos.first][endPos.second] << "\n";
        cout << getPath() << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

