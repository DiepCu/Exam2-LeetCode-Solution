class Solution {
public:



    long long bucketIndex(long long num, long long width) { //bukcet index funcyion
        return num >=0 ? num /width :((num +1) /width) -1;
    }


    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indDiff, int valDiff) { 
         if (indDiff <=0 || valDiff <0) return false;

    unordered_map<long long, long long> bucket; 
    const long long width = (long long) valDiff +1; //delcares width of the bucktets

        for (int i = 0; i < (int)nums.size(); ++i) {

            long long num = nums[i]; //stores the values into nums array 
            long long index = bucketIndex(num, width)  ;

            

         if (bucket.count(index)) //checking differentials
         return true;

            
            if (bucket.count(index -1) &&llabs(num -bucket[index -1]) <= valDiff) 
        return true;

            if (bucket.count(index +1) &&llabs(num -bucket[index +1]) <= valDiff)
             return true;

            
            bucket[index] = num; //puts in current values

           
            if (i >= indDiff) {

                long long prevIndex = bucketIndex((long long)nums[i -indDiff], width); //checks window size anf differentials
                bucket.erase(prevIndex);
            }
        }



        return false;  
    }
};