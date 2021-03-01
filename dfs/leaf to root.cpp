/*
Hi guys!
In my approach to the solution, I tried to go from leaf to the node.
And while traversing this way I saved the computed time cost of the nodes so that we don't have to compute them again and again.
Here's my code for the same.
*/
class Solution {
public:
    int reverse_dfs(vector<int>& manager, vector<int>& informTime,int current_emp,vector<int> &visited)
    {
       
        int senior=manager[current_emp]; //senior to the current employee
        
        /*if the time taken from senior to already known :
        we can simply add the time from senior to current employee to the existing code and return it*/
        if(visited[senior]!=-1)
        {
            return visited[senior]+informTime[senior];
        }
        
        //Computing the cost of senior and storing it
        visited[senior]=reverse_dfs(manager,informTime,senior,visited);
        
        //Before returning we'll save the current_emp cost for future references
        return visited[current_emp]=visited[senior]+informTime[senior];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>visited(n,-1); //stores the time from head to current
        
        visited[headID]=0; //for the head we know that 0 mins are req
        
        int total_time=0; //our final answer is stored here
        
        for(int current_emp=0;current_emp<n;current_emp++)
        {
            // If the employee is already visited we can continue to the next employee
            if(visited[current_emp]!=-1)
            {
                total_time=max(total_time,visited[current_emp]);
            }
            else
            {
                visited[current_emp]=reverse_dfs(manager,informTime,current_emp,visited);
                total_time=max(total_time,visited[current_emp]);
                
            }
        }
        return total_time;
    }
};
