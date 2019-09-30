#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int stom(string s){
    int t = stoi(s);
    int h = t/100;
    int m = t%100;
    return h*60+m;
}
void print_time(int t){
     t = t*5;
    int h = t/60;
    int m = t%60;
    printf("%02d%02d",h,m);
}

int main(void){
    // Here your code !
    int n;
    cin>>n;
    vector<int> r_table(24*60/5+1);
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        int idx = str.find("-");
        string a = str.substr(0,idx);
        string b = str.substr(idx+1,str.size()-idx-1);
        int begin = stom(a)/5;
        int end = stom(b); end = end%5 ==0 ? end/5 : end/5+1;
        r_table[begin]++; r_table[end]--;
        //cout<<begin<<" "<<end<<endl;
        //print_time(begin);printf("-");print_time(end);cout<<endl;
    }
    bool b_flag = false;
    int cnt = 0;
    int begin = 0;
    for(int i = 0;i<r_table.size();i++){
        if(!b_flag&&r_table[i]>0) {b_flag = true;begin = i;}
        cnt += r_table[i];
        if(b_flag&&cnt == 0){
            print_time(begin);printf("-");print_time(i);cout<<endl;
            b_flag = false;
        }
        
    }
    return 0;
}