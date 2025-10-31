class Solution {
public:



    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string,  vector<string>>  buckets;

        for (const string& pph : strs) {
            string key = pph;

            sort(key.begin(), key.end());      //anagram sorts keys that are the same
            buckets[key].push_back(pph);


        }

        vector<vector<string>> answer;
        answer.reserve(buckets.size());

        
     for (auto& [_,group]:buckets) answer.push_back(move (group))  ; // prints the answers



        return answer;
    }
};