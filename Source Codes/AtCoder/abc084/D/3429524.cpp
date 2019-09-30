#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

template<typename input_Integer>
vector<input_Integer> is_Prime(input_Integer N){


    vector<input_Integer> Prime;
    vector<bool> check(N+1,true);
    check[0]=false;
    check[1]=false;


    for(input_Integer i = 2; i * i <= N; ++i){
        if(check[i]){
            for(input_Integer k = i * 2; k < N; k += i){
                check[k] = false;
            }
        }
    }
    for (int i = 0; i < check.size(); i++){
    	if (check[i]) Prime.push_back(i);
    }


    return Prime;
}


int main(){
    int Q;
    cin>>Q;
    vector<int> Prime;
    Prime=is_Prime(100000);
    vector<bool> check(100005);

    for(int x :Prime){
        check[x]=true;
    }

    for(int i=check.size()-1;i>=0;--i){
        if(check[i]){
            check[i]=check[(i+1)/2];
        }
    }
    
    vector<int> niteru;

    for(int i=0;i<check.size();++i){
        if(check[i]){
            niteru.emplace_back(i);
        }
    }

    int l,r;
    for(int i=0;i<Q;++i){
        cin>>l>>r;
        int ans=upper_bound(niteru.begin(),niteru.end(),r)-lower_bound(niteru.begin(),niteru.end(),l);

    cout<<ans<<endl;

    }

}