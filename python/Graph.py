class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_vertex(self, vertex):
        if vertex not in self.adj_list:
            self.adj_list[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.adj_list and vertex2 in self.adj_list:
            self.adj_list[vertex1].append(vertex2)
            self.adj_list[vertex2].append(vertex1)

class DepthFirstSearch:
    def __init__(self, adj_list, start_vertex):
        self.adj_list = adj_list
        self.visited = {}
        self.dfs(start_vertex)

    def dfs(self, vertex):
        self.visited[vertex] = True
        print(vertex, end=" ")

        for neighbor in self.adj_list[vertex]:
            if neighbor not in self.visited:
                print("visited: ", self.visited)
                self.dfs(neighbor)


graph = Graph()

for i in range(0, 7):
    graph.add_vertex(i)

graph.add_edge(0, 1)
graph.add_edge(0, 6)
graph.add_edge(0, 2)
graph.add_edge(0, 5)

graph.add_edge(6, 4)
graph.add_edge(4, 3)
graph.add_edge(3, 5)

dfs = DepthFirstSearch(graph.adj_list, 0)








