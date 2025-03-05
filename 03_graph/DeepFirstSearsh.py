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
        else:
            raise ValueError("One or both vertices not found in graph")

    def __str__(self):
        return str(self.adj_list)
    
class Path:
    def __init__(self, grapsh, source):
        self.graph = graph
        self.source = source
        self.visited = {}
        for vertex in graph.adj_list:
            self.visited[vertex] = False

# Example usage:
if __name__ == "__main__":
    graph = Graph()
    graph.add_vertex('A')
    graph.add_vertex('B')
    graph.add_edge('A', 'B')
    graph.add_vertex('C')
    graph.add_edge('A', 'C')
    print(graph)