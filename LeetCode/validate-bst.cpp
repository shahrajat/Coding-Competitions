typedef struct TreeNode TreeNode;
 bool VerifyBST(TreeNode* root, bool left, bool right, int lmax, int rmin)  
    {  
      if(root== NULL)  
        return true;  
      if(left && root->val >= lmax) return false;  
      if(right && root->val <=rmin) return false;  
      
      bool leftValid = VerifyBST(root->left, true, right, root->val, rmin);  
      bool rightValid = VerifyBST(root->right, left, true, lmax, root->val);  
      return leftValid&&rightValid;        
    }  

bool isValidBST(TreeNode *root) {  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      return VerifyBST(root, false, false, 0,0);  
    }  
   
