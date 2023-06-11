class NumMatrix {
public:
vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
      int n=matrix.size();
      int m=matrix[0].size();
        mat.resize(n+1,vector<int>(m+1));
        for(int i=0;i<=m;i++)mat[0][i]=0;
        for(int j=0;j<=n;j++)mat[j][0]=0;
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
            mat[i][j]=matrix[i-1][j-1]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
          }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return mat[r2+1][c2+1]-mat[r1][c2+1]-mat[r2+1][c1]+mat[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */