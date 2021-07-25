
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
        k=k%a.size();
        
    for(int i=0;i<queries.size();i++){
        if(queries[i]-k<0) {
            queries[i]=a[queries[i]-k+a.size()];
        }
        else queries[i]=a[queries[i]-k];
        
    }
    return queries;

}
