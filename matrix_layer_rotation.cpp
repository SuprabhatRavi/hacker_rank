
/*
Problem statement: You are given a 2D matrix of dimension X * y and a positive integer r. You have to rotate the matrix r times and print the resultant matrix. 
Rotation should be in anti-clockwise direction.
*/

//Basic Idea: Make a function to rotate the matrix by 1 and run it r times to get the desired output.

void matrixRotation(vector<vector<int>> a, int r){
    //rotates matrix by 1 r times
    while(r>0){
    int top=0, left=0, bottom=a.size()-1, right=a[0].size()-1;  
    //keep the loops in limit 
    while(top<bottom && left<right){
        int temp=a[top][left+1];                     
        //storing last element of the cycle
        for(int i=top; i<bottom; i++){
            swap(a[i][left],temp);
        }
        for(int i=left; i<right; i++){
            swap(a[bottom][i],temp);
        }
        for(int i=bottom; i>top; i--){
            swap(a[i][right],temp);
        }
        for(int i=right; i>left; i--){
            swap(a[top][i],temp);
        }
        top++;  left++; bottom--;   right--;
    }
    r--;
   }
    //Prints the matrix
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

//The code gives TLE in few cases.
//Experience: Took me about 8 hrs to finally come up with an acceptable solution.
/*
Optmisitiion: A ring(any layer) of a matrix m * n can only have 2*(m+n-2) possible rotations. That means we only need to rotate the ring of the matrix by 
a maximum of 2*(m+n-2)-1 in worst case. I've noticed that as we go into the inner rings (layers) the number of rotations required is reduced by 8 (I've verified 
it with examples). There are few exceptions such as a matrix of 3 * 5 or 5 * 3 or any matrix that has a 1D array left at the cetre (That case could be solved by
adding an extra if case in the code as it follows the same pattern until it gets to the innermost layer). But since there was a constraint min(m,n)%2==0, we wont
face that exception. so, as the maximum number of rotations in worst cases can be only 2*(m+n-2)-1, 2*(m+n-2)-9, 2*(m+n-2)-17,... we can find the rotations we 
need to do by r%2*(m+n-2), r%2*(m+n-2)-8, r%2*(m+n-2)-16,... Adding it into code will look like.
*/

void matrixRotation(vector<vector<int>> a, int r){
    
    int n=2*(a.size()+a[0].size()-2);
    int top=0, left=0, bottom=a.size()-1, right=a[0].size()-1; 
    while(top<bottom && left<right) {
     int rotation=r%n;
    while(rotation>0){
        int temp=a[top][left+1];                     

        for(int i=top; i<bottom; i++){
            swap(a[i][left],temp);
        }
        for(int i=left; i<right; i++){
            swap(a[bottom][i],temp);
        }
        for(int i=bottom; i>top; i--){
            swap(a[i][right],temp);
        }
        for(int i=right; i>left; i--){
            swap(a[top][i],temp);
        }
        rotation--;
    }
    top++;  left++; bottom--;   right--;    n-=8;
   }

    //Prints the matrix
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
