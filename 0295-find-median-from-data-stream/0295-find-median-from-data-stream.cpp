class MedianFinder {
public:
priority_queue<int>left; //max heap
 priority_queue<int, vector<int>, greater<int>>right; // min heap
    MedianFinder() {
        

        


        
         
    }
    
    void addNum(int num) {
        if(left.empty() ||  num<= left.top()){
            left.push(num);
        } else{
             right.push(num);

        }
           
        
//balncing the data set heap
        if(left.size()> right.size()+1){
            right.push(left.top());
            left.pop();
        } else if( right.size()>left.size()+1){
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        if(right.size()>left.size()){
            return right.top();
        } else if( left.size()> right.size()){
            return left.top();
        } else{
            return( left.top()+ right.top())/2.00;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */