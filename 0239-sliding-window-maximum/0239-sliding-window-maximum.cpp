class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> window;            //stores valueing in the window       
        vector<int> answer;            //window values are always decreasing 
        


        for (int i =0;i <(int)nums.size();++i) {
            
            while (!window.empty() &&window.front() <= i-k) window.pop_front();
            // pop indices that arent in the current window

           
            while (!window.empty() &&nums[window.back()] <=nums[i]) window.pop_back();
            // Makes sure the dque is decracing and remove the smaller values in the back
           

            window.push_back(i);
            // push back the current window value
            

            if (i>= k -1) answer.push_back(nums[window.front()]);
            // push back the current answer 
        }

        return answer; 


    }
};