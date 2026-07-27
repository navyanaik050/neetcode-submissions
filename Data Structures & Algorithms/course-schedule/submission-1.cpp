class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses);

        for(auto &prerequisite : prerequisites){
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            adjList[prerequisiteCourse].push_back(course);
            ++inDegree[course];

        }
        
        queue<int> process;
        for(int i =0; i<numCourses; i++){
            if(inDegree[i] == 0){
                process.push(i);
            }
        }

        while(!process.empty()){
            int currentCourse = process.front();
            process.pop();

            --numCourses;

            for(auto &course : adjList[currentCourse]){
                if(--inDegree[course] == 0){
                    process.push(course);
                }
            }
        }
        return numCourses == 0;
    }
};
