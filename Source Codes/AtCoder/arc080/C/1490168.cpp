#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<map>
using namespace std;
typedef long long int llint;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
const int mod=1000000007;
const int big=1e9+10;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-9;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
int gcd(int a,int b){if(a%b==0){return b;}else return gcd(b,a%b);}//a>b
template<typename T>class seg_tree{
public:
	T treemin;
	int seghi,segmg;
	seg_tree *left;
	seg_tree *right;
	seg_tree(int hi,int mg){
		treemin=0;
		seghi=hi;segmg=mg;
		left=NULL;right=NULL;
		int tyu=(hi+mg)/2;
		if(hi+1<mg){make_left(hi,tyu);make_right(tyu,mg);}
	}
	~seg_tree(){delete left;delete right;}
	void make_left(int hi,int mg){if(this->left!=NULL){cout<<"??"<<endl;throw(1);}this->left=new seg_tree(hi,mg);}
	void make_right(int hi,int mg){if(this->right!=NULL){cout<<"??"<<endl;throw(1);}this->right=new seg_tree(hi,mg);}
	void setval(int pla,T val){//pla????val????
		if(seghi==pla&&segmg==pla+1){treemin=val;return;}
		if(pla<left->segmg){left->setval(pla,val);}
		else{right->setval(pla,val);}
		treemin=min(left->treemin,right->treemin);
	}
	T seg_ask(int hi,int mg){
		if(hi<=seghi&&segmg<=mg){return treemin;}
		if(mg<=seghi||segmg<=hi){return big;}
		T leret,riret;
		leret=left->seg_ask(hi,mg);
		riret=right->seg_ask(hi,mg);
		return min(leret,riret);
	}
};
vector<int>retu;
vector<int> kaz;
vector<vector<int>>ko;
vector<pair<int,int>>val;
int allbas=0;
int solve(int fi,int la,seg_tree<int>& ki,seg_tree<int>& gu){
	if(fi==la){return -1;}
	int hd,mg,thsbas=allbas;
	if(fi%2==0){
		hd=kaz[gu.seg_ask(fi/2,la/2)];
		mg=kaz[ki.seg_ask(hd/2,(la+1)/2)];
	}else{
		hd=kaz[ki.seg_ask(fi/2,la/2)];
		mg=kaz[gu.seg_ask((hd+1)/2,(la+1)/2)];
	}
	val[thsbas]=mp(retu[hd],retu[mg]);
	allbas++;
	int iti;
	
	iti=solve(fi,hd,ki,gu);if(iti!=-1){ko[thsbas].pub(iti);}
	
	iti=solve(hd+1,mg,ki,gu);if(iti!=-1){ko[thsbas].pub(iti);}
	
	iti=solve(mg+1,la,ki,gu);if(iti!=-1){ko[thsbas].pub(iti);}
	return thsbas;
}
int main(void){
	int i,n;cin>>n;
	seg_tree<int> ki(0,n/2+2),gu(0,n/2+2);
	retu.res(n);
	ko.res(n);
	val.res(n);
	kaz.res(n);
	vector<int>ans;
	for(i=0;i<n;i++){
		cin>>retu[i];retu[i]--;
		kaz[retu[i]]=i;
		if(i%2==0){gu.setval(i/2,retu[i]);}
		else{ki.setval(i/2,retu[i]);}
	}
	
	auto it=solve(0,n,ki,gu);
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> que;
	que.push(mt(val[0].fir,val[0].sec,0));
	while(!que.empty()){
		int q=get<0>(que.top()),w=get<1>(que.top()),ban=get<2>(que.top());
		que.pop();
		ans.pub(q);
		ans.pub(w);
		for(i=0;i<ko[ban].size();i++){
			que.push(mt(val[ko[ban][i]].fir,val[ko[ban][i]].sec,ko[ban][i]));
			
		}
		
	}
	for(i=0;i<ans.size();i++){
		cout<<ans[i]+1<<" ";
	}cout<<endl;
	return 0;
}