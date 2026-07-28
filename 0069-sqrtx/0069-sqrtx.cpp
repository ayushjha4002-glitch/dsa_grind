class Solution {
public:
    int mySqrt(int x) {
        int low=0 ,ans=0, high= x;
        while(low<=high){
            long long mid= low+ (high-low)/2;
            if(mid * mid <=x){
                ans=mid;
                low= mid+1;
            }else{
                high= mid-1;
            }
        }
        return ans;
        
    }
};