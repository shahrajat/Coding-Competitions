class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t temp = 0; 
        for(int i=0;i<sizeof(uint32_t)*8; i++)
            if(n>>i&1)  //if the ith bit is set
                temp |= (1 << (31-i));      //set the (31-i)th bit
        return temp;
    }
};
