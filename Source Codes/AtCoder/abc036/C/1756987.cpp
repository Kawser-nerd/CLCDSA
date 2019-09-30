#include<iostream>                                                                                            
#include<vector>
#include<queue>
#include<map>
//ABC036 C ????
int main(){
 //???????map?????
 std::map<long long,long long> mp;
 //???????vector?????vector
 std::vector<long long> origin,copy;
 //???????QUEUE
 std::priority_queue<long long,std::vector<long long>,std::greater<long long> > que;
 //N???
 long long N;
 std::cin>>N;
 //??????
   long long n;
 for(long long i=0;i<N;i++){
   std::cin>>n;
   origin.push_back(n);
   copy.push_back(n);}
 //???
 std::sort(copy.begin(),copy.end());
 //????
 auto iterater=std::unique(copy.begin(),copy.end());
 copy.erase(iterater,copy.end());
 //QUEUE?PUSH
 for(long long i=0;i<copy.size();i++){
   que.push(copy[i]);}
 //??????
 long long p=0;
 while(!que.empty()){
   n=que.top();
   que.pop();
   //map?n?????????????????????
   mp.insert(std::make_pair(n,p));
   p++;
 }
 for(long long i=0;i<origin.size();i++){
   //???????
   long long answer=mp.at(origin[i]);
   //??
   std::cout<<answer<<std::endl;}
}