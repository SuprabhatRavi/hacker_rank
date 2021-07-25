int findDigits(int n) {
    int num=n,res=0;
    while(num>0){
        if(num%10==0){
            num/=10;
            continue;
        } 
        else if(n%(num%10)==0) res++;
        num/=10;
    }
    return res;
}
