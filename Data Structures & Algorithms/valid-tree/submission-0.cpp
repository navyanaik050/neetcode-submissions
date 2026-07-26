class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1){
            return false;
        }
        vector<vector<int>> adjList(n);
        for(auto &edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        unordered_set <int> visit;
        if(!dfs(0, -1, visit, adjList)){
            return false;
        }

        return visit.size() == n;

    }

    bool dfs(int node, int parent, unordered_set<int>& visit, vector<vector<int>>& adjList){
        if(visit.count(node)){
            return false;
        }
        visit.insert(node);
        for(auto neighbour : adjList[node]){
            if(neighbour == parent){
                continue;
            }
            if(!dfs(neighbour, node, visit, adjList)){
                return false;
            }
        }
        return true;
    }
};
