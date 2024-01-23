// Link : https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/

class Solution
{
    public:
    unordered_set<string> st;
    bool isPossible(string& s)
    {
        int n=s.length();
        //take all possible string by removing 1 character and search them in given set
        for (int i=0;i<n;i++)
        {
            string temp="";
            for (int j=0;j<n;j++)
            {
                if (j==i)
                    continue;
                temp.push_back(s[j]);
            }
            if (st.find(temp)!=st.end())
                return true;
        }
        return false;
    }
    int wordtotal(vector<string>& arr, vector<string>& target)
    {
        int n=target.size();
        for (auto& i:arr)
        {
            sort(i.begin(),i.end());  //Sort all strings and insert them in set
            st.insert(i);
        }
        
        int total=0;
        for (int i=0;i<n;i++)
        {
            sort(target[i].begin(),target[i].end());
            if (isPossible(target[i]))
                total++;
        }
        return total;
    }
};