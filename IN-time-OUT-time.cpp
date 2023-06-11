void dfs(int parent,vector<vector<int>>adj,int &currentTime ,int currentNode)
{
    inTime[currentNode]=currentTime++;
    // entry into dfs
    for(int neighbour:adj[currentNode])
    {
        // tree ka ek hi rule hai
        // visited array nai chahiye 
        // kahin par bhi jao parent nai hona chahiye
        if(neigbour!=parent)
        {
            dfs(currentNode,adj,currentTime,neighbour);
        }
    }
    //exiting the dfs
    yahan par tum dfs ko exit kar rahe ho 
    outTime[currentNode]=currentTime++;
}
// yehi hai tumhara intime outime trick
// if u r asked ki x->y (x y ka ancestor hai ya nahi then y ka intime outime x ke intime outime ke andar hona chahiye)