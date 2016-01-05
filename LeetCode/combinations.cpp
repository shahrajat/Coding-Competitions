class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if(k==0 || n==0 || k>n)
        {
            return result;
        }
        else if(k==1)
        {
            for(int i=1; i<=n ; i++)
            {
                vector<int> temp = {i};
                result.push_back(temp);
            }
        }
        else
        {
           vector<vector<int>> prevWithN = combine(n-1, k-1);   //get all combinations of size k-1 without n
           for(vector<int> p : prevWithN)       //add n to each of the subsets
           {
               p.push_back(n);      
               result.push_back(p);
           }
           
           vector<vector<int>> prevNoN = combine(n-1, k);       //get all combinations of size k without n
           for(vector<int> p: prevNoN)      //simply add those sets to the result
               result.push_back(p);
        }
        return result;
    }
};
