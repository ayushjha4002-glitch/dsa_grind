class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        for(int i=0;i<32;i++){
            int ath=(a>>i)& 1;
            int bth= (b>>i) & 1;
            int cth= (c>>i) &1;
            if(cth==1){
                //or ko 1 banana h
                if(ath==0 && bth==0){
                    ans++;
                }
            } else{
                 if(ath==1 && bth==1){
                    ans+=2;
                } else if(ath==1 || bth==1){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};