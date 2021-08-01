/*
Keep in mind that it's not necessary that balls of type 0
need to be in box 0. They all just need to be in one box dosen't 
matter which.
*/

string organizingContainers(vector<vector<int>> container) {
    
    ll e=0, t=0;
    vector<ll> a, b;
    
    for(int i=0; i<container.size(); i++) {
        e=0; t=0;
        for(int j=0; j<container[0].size(); j++) {        
        
            
            e+=container[i][j];
            t+=container[j][i];
        }
        a.push_back(e);
        b.push_back(t);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a==b) return "Possible";
        return "Impossible";  
}