// Link : https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/



class DataStream {
public:
typedef long long ll;
public:
    ll val, k, pre, temp;
    DataStream(int value, int K) {
        val=value, k=K;
        pre=-1, temp=0;
    }
    
    bool consec(int num) {
        if(num!=val){
            pre=temp;
        }
        bool result=temp-pre>=k;
        ++temp;
        return result;
    }
};

