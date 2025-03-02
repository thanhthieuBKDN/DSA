from collections import deque
class DiGraph:
    def __init__(self, vertices):
        self.v = vertices
        self.adj_list = {}
        for vertex in range(self.v):
            self.adj_list[vertex] = []

    def add_edge(self, vertex1, vertex2):
        self.adj_list[vertex1].append(vertex2)

class DepthFirstSearch:
    def __init__(self, adj_list, start_vertext):
        self.visited = [False]* len(adj_list)
        self.dfs(adj_list, start_vertext)
    def dfs(self, adj_list, vertex):
        self.visited[vertex] = True
        print(vertex)
        for next in adj_list[vertex]:
            if self.visited[next] == False:
                self.dfs(adj_list, next)     

class BreadthFirstSearch:
    def __init__(self, adj_list, start_vertex):
        print("BFS")
        self.visited = [False] * len(adj_list)
        self.bfs(adj_list, start_vertex)

    def bfs(self, adj_list, start_vertex):
        queue = deque()
        queue.append(start_vertex)
        self.visited[start_vertex] = True

        while queue:
            vertex = queue.popleft()
            print(vertex)
            for next in adj_list[vertex]:
                if not self.visited[next]:
                    queue.append(next)
                    self.visited[next] = True





diGraph = DiGraph(6)

diGraph.add_edge(0, 1)
diGraph.add_edge(0, 5)
diGraph.add_edge(5, 4)
diGraph.add_edge(4, 3)
diGraph.add_edge(3, 2)

dfs = DepthFirstSearch(diGraph.adj_list, 0)


bfsGraph = DiGraph(6)
bfsGraph.add_edge(0, 1)
bfsGraph.add_edge(0, 2)
bfsGraph.add_edge(1, 2)
bfsGraph.add_edge(3, 2)
bfsGraph.add_edge(2, 4)
bfsGraph.add_edge(4, 3)
bfsGraph.add_edge(3, 5)
bfsGraph.add_edge(5, 0)

bfs = BreadthFirstSearch(bfsGraph.adj_list, 0)













