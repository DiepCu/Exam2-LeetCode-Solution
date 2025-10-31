class Solution {
public:

    vector<vector<int>>
    
     getSkyline(vector<vector<int>>& buildings) {
       
        vector<pair<int,int>> occ;
        occ.reserve(buildings.size() *2) ;

    for (auto& b : buildings) {

            int Left = b[0], Right =b[1], Height = b[2];
            occ.emplace_back(Left, -Height) ; //declaring the begining and end of the building
            occ.emplace_back(Right,  Height); 
        }


        sort(occ.begin(), occ.end());



        multiset<int> active = {0};  //sets the height to 0 
        int lastMax = 0;
        vector<vector<int>> answer;

    for (auto [num, Height] : occ) { //determines wether exiting or entering a building
 
            if (Height < 0) {  

                active.insert(-Height);

            } else {      
                               
                auto tr =active.find(Height);
                if (tr !=active.end()) active.erase(tr); 
            }

            int currMax =*active.rbegin();
            if (currMax !=lastMax) { 


                answer.push_back({num, currMax}) ; //comparing the current max to the last max
                lastMax =currMax;
            }
        }

        return answer;


    }
};