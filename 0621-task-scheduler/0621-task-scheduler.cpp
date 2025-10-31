class Solution {
public:
    int leastInterval(vector<char>& tasks, int n){


       int frequency[26] ={0}; //26 character in the alphabet
    for (char c : tasks) frequency[c - 'A']++;

      
        int maxFrequency =0 ;
        int maxNum =0;

    for (int freq :frequency){

            if (freq >maxFrequency) { maxFrequency =freq; maxNum= 1; } //check the most cosunt and how frequent it is
            else if (freq == maxFrequency) {maxNum++; } //break ties
        }

        
        int Table= (maxFrequency - 1) * (n + 1) +maxNum; //arrange to where most frequent goes first

        
    return max((int)tasks.size(), Table); 

    }
};