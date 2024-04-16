#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits>

class WeightedGraph {
public:
    WeightedGraph(int numNodes) : numNodes(numNodes) {
        for (int i = 0; i < numNodes; ++i) {
            adjacencyList[i] = std::vector<std::pair<int, int>>(); // {destination, weight}
        }
    }

    void addEdge(int source, int destination, int weight) {
        if (source >= 0 && source < numNodes && destination >= 0 && destination < numNodes) {
            adjacencyList[source].emplace_back(destination, weight);
        }
    }

    int numOutgoing(const int nodeID) const {
        if (nodeID >= 0 && nodeID < numNodes) {
            return adjacencyList.at(nodeID).size();
        }
        return 0;
    }

    const std::vector<std::pair<int, int>>& adjacent(const int nodeID) const {
        static const std::vector<std::pair<int, int>> emptyList;
        if (nodeID >= 0 && nodeID < numNodes) {
            return adjacencyList.at(nodeID);
        }
        return emptyList;
    }

    std::vector<int> shortestPath(int start, int end) {
        std::vector<int> distance(numNodes, std::numeric_limits<int>::max());
        std::vector<int> parent(numNodes, -1);

        distance[start] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& neighbor : adjacencyList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }

        std::vector<int> path;
        int current = end;
        while (current != -1) {
            path.insert(path.begin(), current);
            current = parent[current];
        }
        return path;
    }

    int shortestPathWeight(int start, int end) {
        std::vector<int> path = shortestPath(start, end);
        if (path.empty()) {
            return std::numeric_limits<int>::max();
        }
        int weight = 0;
        for (int i = 0; i < path.size() - 1; ++i) {
            for (const auto& neighbor : adjacencyList[path[i]]) {
                if (neighbor.first == path[i + 1]) {
                    weight += neighbor.second;
                    break;
                }
            }
        }
        return weight;
    }
    
private:
    int numNodes;
    std::map<int, std::vector<std::pair<int, int>>> adjacencyList;
};

int main() {
    WeightedGraph graph(6);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 3, 5);
    graph.addEdge(2, 1, 1);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 4, 2);
    graph.addEdge(4, 5, 6);

    int startNode = 0;
    int endNode = 5;
    std::vector<int> shortestPath = graph.shortestPath(startNode, endNode);

    if (!shortestPath.empty()) {
        std::cout << "Shortest Path from " << startNode << " to " << endNode << ": ";
        for (int node : shortestPath) {
            std::cout << node << " ";
        }
        int pathWeight = graph.shortestPathWeight(startNode, endNode);
        std::cout << "\nPath Weight: " << pathWeight << std::endl;
    } else {
        std::cout << "No path found from " << startNode << " to " << endNode << std::endl;
    }

    return 0;
}
