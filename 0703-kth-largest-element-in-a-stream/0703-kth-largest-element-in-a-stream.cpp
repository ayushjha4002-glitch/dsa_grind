class KthLargest {
public:
priority_queue<int , vector<int>, greater<int>>pq;
int a;
    KthLargest(int k, vector<int>& nums) {
        a=k;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>a){
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>a){
            pq.pop();
        }
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */