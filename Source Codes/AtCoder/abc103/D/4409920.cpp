#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
int N,M;
vector<pair<int,int>> v;

bool comp(pair<int,int> p1,pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    cin >> N >> M;
    v = vector<pair<int,int>>(M);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        v[i] = make_pair(a,b);
    }
    sort(v.begin(),v.end(),comp);
    int rm = -1;
    int count = 0;
    for(int i=0;i<M;i++){
        //cout << v[i].first << " " << v[i].second << endl;
        if(v[i].first <= rm) continue;
        else{
            rm = v[i].second -1;
            //cout << rm << endl;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}