class Solution {
public:
int fun(int n){
    int sum=0;
    while(n>0){
        int digit= n%10;
        sum+=digit*digit;
        n=n/10;
        
    }
    return sum;
}
    bool isHappy(int n) {
        int slow= fun(n);
        int fast= fun(fun(n));
        while(slow!=fast){
            slow= fun(slow);
            fast= fun(fun(fast));
            if(slow==fast){
                break;
            }
        }
        return (slow==1);
        
    }
};