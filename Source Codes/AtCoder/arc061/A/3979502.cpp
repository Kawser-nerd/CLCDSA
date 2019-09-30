#include <iostream>
#include <vector>
#include <set>
using namespace std;


long rec(string &s, long start, long index, long sum) {
    //cout<<s<<"\t"<<start<<"\t"<<index<<"\t"<<sum<<endl;

    if(start>=s.size()){
        return sum;
    }
    if(index>=s.size()){
        string digit_s=s.substr(start);
        long digit = stol(digit_s);
        return digit + sum;
    }
    
    // index????+?????????
    long result1 = rec(s, start, index+1, sum);
    // index????+??????
    long result2 = 0;
    if (index > start) {
        string digit_s=s.substr(start, index-start);
        long digit = stol(digit_s);
        result2 = rec(s, index, index+1, sum+digit);
    }

    return result1 + result2;
}

int main() {
    string s;
    cin>>s;

    cout<<rec(s, 0, 0, 0)<<endl;

    return 0;
}