//approach: DFS
class Solution {
public:
    void generateFromSeed(int pre, int n, vector<int> &result){
        if(pre>n) return;
        for(int i=0; i<10; i++) {
            int next = pre*10+i;
            if(next<=n){
                result.push_back(next);
                generateFromSeed(next, n, result);
            } else          //reduces unnecessary calls
                break;
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        //iterate over all seeds
        for(int i=1; i<=9 && i<=n; i++) {
            result.push_back(i);    //add seed
            generateFromSeed(i, n, result); //dfs starting from seed
        }
        return result;
    }
};
