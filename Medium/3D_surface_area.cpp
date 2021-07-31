
int surfaceArea(vector<vector<int>> A) {
    int FSA=0;
    
    for(int i=0; i<A.size(); i++) {
        int res=0;
        for(int j=0; j<A[i].size(); j++) {
            if(A[i][j]<=res) {
                res=A[i][j];
                continue;
            }
            FSA+=A[i][j]-res;
            res=A[i][j];
        }
    }
    
    int LSA=0;
    
    for(int i=0; i<A[0].size(); i++) {
        int res=0;
        for(int j=0; j<A.size(); j++) {
            if(A[j][i]<=res) {
                res=A[j][i];
                continue;
            }
            LSA+=A[j][i]-res;
            res=A[j][i];
        }
    }
    
    int BSA=A[0].size()*A.size();
    
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[i].size(); j++) {
         if(A[i][j]==0) BSA--;
    }
    }
   
    return 2*LSA + 2*BSA + 2*FSA;
}