def solve():
    n, m = map(int, input().split())
    grid = [input() for _ in range(n)]

    def is_valid(r, c):
        return 0 <= r < n and 0 <= c < m

    def dfs(r, c, start_r, start_c, visited, path):
        if (r, c) in visited and (r,c) != path[-2] if len(path) > 1 else False :
            if len(path) >= 4 and (start_r, start_c) == (r,c):
                return True
            else:
                return False

        visited.add((r, c))
        path.append((r,c))

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if is_valid(nr, nc) and grid[nr][nc] == grid[start_r][start_c]:
                if dfs(nr, nc, start_r, start_c, visited.copy(), path.copy()):
                    return True
        return False

    for r in range(n):
        for c in range(m):
            if dfs(r, c, r, c, set(), []):
                print("Yes")
                return

    print("No")

solve()