/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> clone;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node && !clone[node]) {
            clone[node] = new UndirectedGraphNode(node->label);
            for (auto n : node->neighbors)
                clone[node]->neighbors.push_back(cloneGraph(n));
        }
        return clone[node];
    }
};
