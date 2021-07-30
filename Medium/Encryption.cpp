/*
An English text needs to be encrypted using the following encryption scheme.
Sample input: haveaniceday
Sample output: hae and via ecy
*/

string encryption(string s) {
    float n=sqrt(s.length());
    int f=floor(n), c=ceil(n);
    string str, tstr;
    
    for(int i=0; i<s.length(); i++) {
        if(s[i]==' ') {
            continue;
        }
        tstr+=s[i];
    }
    
    for(int i=0; i<c; i++) {
        int j=i;
        while(j<tstr.length()) {
            str=str+tstr[j];
            j+=c;
        }
        str+=' ';
    }
    return str;
}
