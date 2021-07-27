/*
Given an array of integers, find the longest subarray where the absolute difference between any two elements is less than or equal to 1.
*/

//Basic idea: check all subsets and select the one with max length

int helper(vector<int> a,vector<int> vect,long unsigned i)
{
    if(i==a.size())
    {
        sort(vect.begin(),vect.end());
        for(long unsigned j=0;j<vect.size();j++)
        {
            if(abs(vect[0]-vect[j])>1)
            {
                return 0;
            }           
        }
        return vect.size();
    }
    int x=helper(a,vect,i+1);
    vect.push_back(a[i]);
    int y=helper(a,vect,i+1);
    return max(x,y);   
}

int pickingNumbers(vector<int> a) 
{
    vector<int> vect;
    long unsigned i=0;   
    return helper(a,vect,i);
}


//Gives TLE in some cases

//Optmisition: Removed Recursive call stacks

int pickingNumbers(vector<int> a) 
{
    sort(a.begin(),a.end());
    int count=0,res=0;
    
    for(int i=0;i<a.size();i++)
    {
        count=1;
        for(int j=i+1;j<a.size();j++)
        {
            if(abs(a[i]-a[j])<=1)
            {
                count++;
            }
        }
        res=max(res,count);
    }
    return res;
}


