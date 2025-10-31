class MedianFinder {
public:

priority_queue<int> bigHeap;  
    priority_queue<int, vector<int>, greater<int>> smolHeap; //delcaring big heap for the lowerhalf and small heap for upper


    MedianFinder()  {
        
    }
    void addNum(int num) {
        
    bigHeap.push(num); //pushes num into lower

        
        smolHeap.push(bigHeap.top());
        bigHeap.pop();

       
        if (smolHeap.size() >bigHeap.size()) { //balnces the left and right


            bigHeap.push(smolHeap.top()) ; // if the right exceeds left balance again
            smolHeap.pop();
        }
    }
 
        
    
    
    double findMedian() {
        
        if (bigHeap.size() > smolHeap.size()) 
        //finding the middle
        
         return bigHeap.top();
        
        
        return (bigHeap.top() +smolHeap.top()) /2.0  ; //averages the 2 medians
    }
};

