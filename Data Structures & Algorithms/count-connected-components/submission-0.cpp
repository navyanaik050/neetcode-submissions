class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto &j : edges){
            adjList[j[0]].push_back(j[1]);
            adjList[j[1]].push_back(j[0]);
        }

        vector<bool> visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adjList, visited, i);
                count++;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>adjList, vector<bool>& visited, int node){
        visited[node] = true;
        for(auto neighbour : adjList[node]){
            if(!visited[neighbour]){
                dfs(adjList, visited, neighbour);
            }
        }
    }
};
