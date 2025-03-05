# Labyrinth
# You are given a map of a labyrinth, and your task is to find a path from start to end. You can
# walk left, right, up and down.
# Input
# The first input line has two integers n and m : the height and width of the map.
# Then there are n lines of m characters describing the labyrinth. Each character is '.' (foor),
# #(wall), A (start), or B (end). There is exactly one A and one B in the input.
# Output
# First print "YES", if there is a path, and "NO" otherwise.
# If there is a path, print the length of the shortest such path and its description as a string
# consisting of characters L (left), R (right), U (up), and D (down). You can print any valid
# solution.

# n <= 1000
# m <= 1000

from collections import deque

# Hướng di chuyển: (dx, dy) và ký tự tương ứng
directions = [(0, -1, 'L'), (0, 1, 'R'), (-1, 0, 'U'), (1, 0, 'D')]

def bfs(labyrinth, n, m, start, end):
    queue = deque([start])
    parent = {start: None}  # Lưu vết đường đi
    dist = {start: 0}  # Lưu khoảng cách từ 'A'

    while queue:
        x, y = queue.popleft()
        
        # Nếu tìm thấy B, dừng BFS
        if (x, y) == end:
            return dist[(x, y)], parent
        
        for dx, dy, move in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and labyrinth[nx][ny] != '#' and (nx, ny) not in dist:
                queue.append((nx, ny))
                dist[(nx, ny)] = dist[(x, y)] + 1
                parent[(nx, ny)] = ((x, y), move)  # Lưu cha + hướng đi

    return -1, {}  # Không tìm thấy đường đi

def get_path(parent, start, end):
    path = []
    cur = end
    while cur != start:
        cur, move = parent[cur]
        path.append(move)
    return ''.join(reversed(path))

def solve():
    # Đọc dữ liệu đầu vào
    n, m = map(int, input().split())
    labyrinth = [list(input().strip()) for i in range(n)]

    # Tìm vị trí của A và B
    start, end = None, None
    for i in range(n):
        for j in range(m):
            if labyrinth[i][j] == 'A':
                start = (i, j)
            elif labyrinth[i][j] == 'B':
                end = (i, j)

    # Chạy BFS để tìm đường đi ngắn nhất
    distance, parent = bfs(labyrinth, n, m, start, end)

    if distance == -1:
        print("NO")
    else:
        print("YES")
        print(distance)
        print(get_path(parent, start, end))

