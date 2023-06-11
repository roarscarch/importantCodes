class dsu{
    public:
        vector<int> parent;
        vector<int> size;
        dsu(int n)
        {
            parent.assign(n,-1);
            size.assign(n,0);
        }
        void make_friends(int v)
        {
            parent[v]=v;
            size[v]=1;
        }
        int find_parent(int v)
        {
            if(v==parent[v])    return v;
            return parent[v]=find_parent(parent[v]);
        }
        void union_set(int x,int y)
        {
            x=find_parent(x);
            y=find_parent(y);
            if(x!=y)
            {
                if(size[x]<size[y]) swap(x,y);
                parent[y]=x;
                size[x]+=size[y];
            }
        }
};