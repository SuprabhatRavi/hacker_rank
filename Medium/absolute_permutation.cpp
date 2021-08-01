/*
Approach: Every number i can be at only two places to give 
a diccefence of k and they are i-k or i+k if a permutation with
these rules is possible we get our final permutation in O(n) else 
it's not possible and we return -1
*/

vector<int> absolutePermutation(int n, int k) {
    
    vector<int> v(n);
    fill(v.begin(), v.end(), 0);
    for(int i=0; i<n; i++) {
       if(i+1-k > 0) {
           if(v[i-k]==0) {
               v[i-k]=i+1;
           }
           else {
               v[(i+k)%n]= i+1;
           }
           
       }
       else {
           if(i+1+k ==0) {
               v[k]=i+1;
           }
           else {
               if(v[(i+k)%n]==0){
                v[(i+k)%n]= i+1;
           }
           else {
               v[(i+2*k)%n]=i+1;
           }
           }
         
       }
    }
    
    int flag=1;
    for(int i=0; i<n; i++) {
        if(abs(v[i]-i-1)!=k || v[i]==0) {
            flag=0;
            break;
        }
    }
    
    if(flag==0) {
        vector<int> vect={-1};
        return vect;
    }
    else return v;
    
    
}
