/*
Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.

Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:

==>> It must be greater than the original word
==>> It must be the smallest word that meets the first condition
*/

string biggerIsGreater(string w) {
    int n= w.length()-1, i;      
        for(i=n; i>0; i--) {
            if(w[i-1]< w[i]) {    
                sort(&w[i], &w[n+1]);
                break;           
            }
        }
        if(i<=0) return "no answer";
        else {
           for(int j=i; j<=n; j++) {
               if(w[j]>w[i-1]) {
                   swap(w[j],w[i-1]);
                   return w;
                } 
            }
        }
        return "Flow wont reach here";
}

// Instead of this could also be done using next_permutation() function

string biggerIsGreater(string w) {
    int flag=0;
    for(int i =w.length()-1; i>0; i--) {
        if(w[i-1]<w[i]) {
           flag=1;
           break; 
        }
    }
    if(flag==0) return "no answer";
    next_permutation(w.begin(), w.end());
    return w;
}