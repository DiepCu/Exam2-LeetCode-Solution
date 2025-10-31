class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> step;          
        heights.push_back(0);    //declaring step pand pushing bakc haight
        int wholeArea =0;       //keep at 0


        for (int k = 0; k < heights.size(); ++k){


            while (!step.empty() && heights[k] <heights[step.top()]){  
                //always caluculate arena if the crueent bar is smaller than the bar stacked on top of it

                int height = heights[step.top()];
                step.pop();
                int width = step.empty() ?k : k -step.top() -1;
                wholeArea =max(wholeArea, height *width); //compute max area
            }


            step.push(k); 


        }
        return wholeArea;   



    }
};