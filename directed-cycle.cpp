bool isCyclic(int V, vector<int> adj[]) {
        vector<int>indegree(V,0);
        // hum sabke indegree ko 0 nai kar sakte 
        // iske liye apne ko vector<int> chahiye
        //queue
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        // bfs start karenge wahan se jiska indegree 0 hai
        // ek bar aur chalna padega
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        if(q.size()==0)
        return 1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        for(int i=0;i<V;i++)
        {
            if(indegree[i]!=0)
            return 1;
        }
        return 0;
    }