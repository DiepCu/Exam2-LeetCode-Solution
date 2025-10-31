#include <bits/stdc++.h>
using namespace std;

class Codec { //declaring the codec
public:

    
    string serialize(TreeNode* root) { //puts the tree into one string
    if (!root) return "";

        ostringstream output ;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* current = que.front(); que.pop();
         if (current) {

                output<< current->val << ',';
                que.push (current->left);
                que.push (current->right);
 
            } else {
                output << "null,";
            }
        }
        string stg = output.str();
        if (!stg.empty()) stg.pop_back(); //prevents excess comas at the end 

        return stg;    
    }

    
    TreeNode* deserialize(string data) {// undo the date to tree
    if (data.empty()) return nullptr;

       
        vector<string> tem;
        tem.reserve(data.size()/2); //adding commas in between the datas
        for (size_t i =0,  j= 0;i <= data.size(); ++i) {

        if (i == data.size() || data[i] == ',') {

                tem.emplace_back(data.substr(j, i -j));
                j = i + 1;
            }
        }

        
        int index =0;


        if (tem[index] =="null") return nullptr;
        TreeNode* root =new TreeNode(stoi(tem[index++])); // building the tree level by level
        queue<TreeNode*> que;
        que.push(root);

        
        while (!que.empty() && index <(int)tem.size()){
            TreeNode* current= que.front(); que.pop();

            if (index <(int)tem.size() && tem[index] !="null"){
                current->left = new TreeNode(stoi(tem[index]));
                que.push(current->left);
            }
            ++index;

         if (tem[index] != "null" && index <(int)tem.size()){
                current->right = new TreeNode(stoi(tem[index]));
                que.push(current->right);
            }
            ++index;
        }
    return root;    
    }
};

