#include<iostream>
#include<vector>
#include<queue>

#define INF 1000000000

struct Way{

    int to;
    int cost;

};

struct Node{
    
    bool confirm;
    int power;
    std::vector<Way> next;
    std::vector<Way> previous;
    int gocost;
    int backcost;

};

struct NN{
    int number;
    int cost;
};

bool operator< (const NN &n1, const NN &n2){
    return n1.cost > n2.cost;
};

int temp;
int N,M,T;
Node node[100000];
long long result;
std::priority_queue<NN> que;

//N:???
//M:???
//T:????
//A:???????

int main(){

    std::cin>>N>>M>>T;

    for(int i=0;i<N;i++){
    std::cin>>node[i].power;
    node[i].confirm=false;
    node[i].gocost=INF;
    node[i].backcost=INF;
    }

    node[0].confirm=true;
    node[0].gocost=0;
    node[0].backcost=0;

    int a,b;
    for(int i=0;i<M;i++){
    std::cin>>temp>>a>>b;
    node[temp-1].next.push_back((Way){a-1,b});
    node[a-1].previous.push_back((Way){temp-1,b});
    }

    int now=0;//????

    //?????????
    for(int i=0;i<N-1;i++){
        //??????????
        for(auto&& x:node[now].next){
            if(!node[x.to].confirm){
            node[x.to].gocost=node[x.to].gocost<node[now].gocost+x.cost?node[x.to].gocost:node[now].gocost+x.cost;//?????????
            que.push((NN){x.to,node[x.to].gocost});
            }
        }
        if(!que.empty()){
        node[que.top().number].confirm=true;
        now=que.top().number;
        que.pop();
        }
        //?????????
    }

    now=0;

    std::priority_queue<NN>().swap(que);

    for(int i=1;i<N;i++)
    node[i].confirm=false;

    //?????????
    for(int i=0;i<N-1;i++){
        //??????????
        for(auto&& x:node[now].previous){
            if(!node[x.to].confirm){
            node[x.to].backcost=node[x.to].backcost<node[now].backcost+x.cost?node[x.to].backcost:node[now].backcost+x.cost;//?????????
            que.push((NN){x.to,node[x.to].backcost});
            }
        }
        if(!que.empty()){
        node[que.top().number].confirm=true;
        now=que.top().number;
        que.pop();
        }
        //?????????
    }

    for(int i=0;i<N;i++){
        temp=(T-(node[i].gocost+node[i].backcost))*node[i].power;
        result=temp>result?temp:result;
    }

    std::cout<<result<<std::endl;

    return 0;
}