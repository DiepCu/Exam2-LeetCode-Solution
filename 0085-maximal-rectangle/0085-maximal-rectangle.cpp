class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) { //using stacks finds the biggest area in a histogram

      if (matrix.empty() || matrix[0].empty()) 
      
      return 0;

        int row = matrix.size(), column = matrix[0].size();

        vector<int> leng(column, 0); 
        int BiggestArea = 0;

        auto AreaOfHistogram = [&](const vector<int>& hr)  {

            vector<int> tm = hr; tm.push_back(0);           
            stack<int> string;                               
            int result = 0;

            
            for (int t = 0; t < (int)tm.size(); ++t) {
            while (!string.empty() && tm[t] <tm[string.top()]){ //computes and finds the largegest rectangle in the histogram


                int leng = tm[string.top()];string.pop();
                int left = string.empty() ? -1:string.top();
                    int width = t -left -1;
                    result = max(result, leng*width);
                }
                string.push(t);
            }
            return result;
        };

        for (int rw = 0; rw < row; ++rw) {

            for (int cl = 0; cl < column; ++cl)
                leng[cl] = (matrix[rw][cl] == '1') ? leng[cl] +1:0;


            BiggestArea = max(BiggestArea, AreaOfHistogram(leng)); //find the biggest max of area
        }


        return BiggestArea;  
    }
};