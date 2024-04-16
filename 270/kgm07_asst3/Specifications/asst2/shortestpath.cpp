/**
 * Class WeightedGraph represents a weighted directed graph.
 */
class WeightedGraph {
private:
    std::map<int, std::vector<std::pair<int, int>>> nodelist;
    mutable std::vector<int> neighbors;
    mutable std::vector<int> path;

public:
    /**
     * Constructor to create a WeightedGraph with the specified number of nodes.
     *
     * @param numNodes The number of nodes in the graph.
     */
    WeightedGraph(int numNodes);

    /**
     * Adds a weighted edge from the source node to the destination node with the specified weight.
     *
     * @param source The source node.
     * @param destination The destination node.
     * @param weight The weight of the edge.
     */
    void addEdge(int source, int destination, int weight);

    /**
     * Returns the number of outgoing edges from the specified node.
     *
     * @param nodeID The ID of the node.
     * @return The number of outgoing edges.
     */
    int numOutgoing(const int nodeID) const;

    /**
     * Returns a reference to a vector containing the IDs of nodes adjacent to the specified node.
     *
     * @param nodeID The ID of the node.
     * @return A reference to a vector of adjacent node IDs.
     */
    const std::vector<int>& adjacent(const int nodeID) const;

    /**
     * Finds and returns the shortest path from the start node to the end node using Dijkstra's algorithm.
     *
     * @param start The ID of the start node.
     * @param end The ID of the end node.
     * @return A vector containing the IDs of nodes in the shortest path from start to end.
     */
    std::vector<int> shortestPath(int start, int end);

    /**
     * Calculates and returns the total weight of the shortest path from the start node to the end node.
     *
     * @param start The ID of the start node.
     * @param end The ID of the end node.
     * @return The total weight of the shortest path. Returns -1 if no path exists.
     */
    int shortestPathWeight(int start, int end);
};
