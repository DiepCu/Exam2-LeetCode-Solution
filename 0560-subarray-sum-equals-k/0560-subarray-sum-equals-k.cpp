class Solution {
public:

    int subarraySum(vector<int>& nums, int k){

         unordered_map<long long,int> frequency; //declaring and creating table
        frequency[0] = 1;                        

        int sum = 0;
        int count = 0;

        for (int x : nums){ //run for as long as ther is numbers

            sum += x;                    
            long long target = sum -k  ;    

            if (frequency.count(target)) count+= frequency[target]; //counting up the sum

            ++frequency[sum];                 
        }
        return count;
    }
};
 