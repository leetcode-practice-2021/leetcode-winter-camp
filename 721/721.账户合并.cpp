/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
    bool isSame(const vector<string>& emails1,const vector<string>& emails2){
        // 先排序后比较？
        for(int i = 1; i< emails1.size(); ++i){
            for(int j = 1; j < emails2.size(); ++j){
                if(emails1[i] == emails2[j]){
                    //cout << "true";
                    return true;
                }
            }
        }
        return false;
    }

    int find(vector<int> uf_set, int idx){
        int tempRes = idx;
        while (uf_set[tempRes]!=-1)
        {
            tempRes = uf_set[tempRes];
        }
        int temp = idx;
        while (uf_set[temp]!=-1)
        {
            int tempHead = uf_set[temp];
            uf_set[temp] = tempRes;
            temp = tempHead;
        }
        return tempRes;
    }

    void unionTwo(vector<int>& uf_set, int i,int j){
        if(i < j){
            uf_set[j] = i;
        }else if(i > j){
            uf_set[i] = j;
        }
    }
//[["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]]
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        map<string, vector<int>> idxes;
        vector<int> uf_set(accounts.size(), -1 );
        for(int i = 0; i < accounts.size(); ++i){
            auto curIt = idxes.find(accounts[i][0]);
            if(curIt==idxes.end()){
                vector<int> temp{i};
                idxes.insert(pair<string, vector<int>>(accounts[i][0],temp));
            }else{
                for(int j = 0; j < curIt->second.size(); ++j){
                    //cout << curIt->second[j] << endl;
                    if(isSame(accounts[curIt->second[j]], accounts[i])){
                        //todo union
                        int num1 = find(uf_set, curIt->second[j]);
                        int num2 = find(uf_set, i);
                        if(num1==num2){
                            continue;
                        }
                        //cout << "num1:" << num1 << "--num2:" << num2 << endl; 
                        unionTwo(uf_set, num1, num2);
                        if(num1>num2){
                            int swapTemp = num1;
                            num1 = num2;
                            num2 = swapTemp;
                        }
                        accounts[num1].insert(
                            accounts[num1].end(),
                            accounts[num2].begin()+1,
                            accounts[num2].end() );
                        //break;
                    }
                }
                curIt->second.push_back(i);
            }
        }

        set<int> heads;
        for(int i = 0; i< uf_set.size(); ++i){
            //cout << uf_set[i] << endl;
            int head = find(uf_set, i);
            //cout << head << endl;
            if(heads.find(head)==heads.end()){
                sort(accounts[i].begin()+1, accounts[i].end() );
                accounts[i].erase(unique(accounts[i].begin()+1,accounts[i].end()), accounts[i].end()); 
                res.push_back(accounts[i] ); //todo
                heads.insert(head);
            }
        }
        return res;
    }
};
// @lc code=end

