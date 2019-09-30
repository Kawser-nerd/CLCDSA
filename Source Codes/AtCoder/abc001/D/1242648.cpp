#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int> > P;

int Cf(int first){
    int temp = first % 5;
    return first - temp;
}
int Cb(int second){
    int temp = second % 5;
    if(temp == 0){
        return second;
    }
    second = second - temp + 5;
    if(second % 100 == 60){
        second = second + 100 - 60;
    }
    return second;
}

int main(){
    int n;
    cin >> n;
    P rain(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        int first = stoi(s.substr(0,4));
        int second = stoi(s.substr(5,4));
        rain[i] = make_pair(Cf(first), Cb(second));
    }
    sort(rain.begin(), rain.end());

    int minr = rain[0].first;
    int maxr = rain[0].second;
    int point = 0;
    P pairs;
    for(int i=0;i<n;i++){
        if( maxr >= rain[i].first ){
            maxr = max(maxr, rain[i].second);
        } else {
            pairs.push_back(make_pair(minr,maxr));
            point++;
            minr = rain[i].first;
            maxr = rain[i].second;
        }
    }
    pairs.push_back(make_pair(minr,maxr));
    point++;
    for(int i=0;i<point;i++){
        printf("%04d-%04d\n",pairs[i].first, pairs[i].second);
    }
    return 0;
}