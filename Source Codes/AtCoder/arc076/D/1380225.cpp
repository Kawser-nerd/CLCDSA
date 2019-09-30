#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<map>
#include<functional>
using namespace std;
typedef long long int llint;
typedef bool izryt;
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
const int big=1e9;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
template <typename T>
class seg_tree{
public:
	T treemax,treemin,lazyplus;
	int seghi,segmg;
	seg_tree *left;
	seg_tree *right;
	seg_tree(int hi,int mg){
		treemax=0;treemin=0;lazyplus=0;
		seghi=hi;segmg=mg;
		left=NULL;right=NULL;
		int tyu=(hi+mg)/2;
		if(hi+1<mg){make_left(hi,tyu);make_right(tyu,mg);}
	}
	~seg_tree(){delete left;delete right;}
	void make_left(int hi,int mg){if(this->left!=NULL){cout<<"??"<<endl;throw(1);}this->left=new seg_tree(hi,mg);}
	void make_right(int hi,int mg){if(this->right!=NULL){cout<<"??"<<endl;throw(1);}this->right=new seg_tree(hi,mg);}
	void seg_plus(int hi,int mg,T val){//???????
	//timecount++;//???
		if(hi<=seghi&&segmg<=mg){lazyplus+=val;return;}
		if(mg<=seghi||segmg<=hi){return;}
		left->seg_plus(hi,mg,val);
		right->seg_plus(hi,mg,val);
		treemin=min(left->treemin+left->lazyplus,right->treemin+right->lazyplus);
		treemax=max(left->treemax+left->lazyplus,right->treemax+right->lazyplus);
		return;
	}
	/*T ask_min(int hi,int mg){//??(hi,mg]????,?????
		//timecount++;//???
		if(hi<=seghi&&segmg<=mg){return treemin+lazyplus;}
		if(mg<=seghi||segmg<=hi){return big;}
		T leret,riret;
		if(right!=NULL&&left!=NULL&&lazyplus!=0){
			right->lazyplus+=this->lazyplus;
			left->lazyplus+=this->lazyplus;
			treemax+=lazyplus;
			treemin+=lazyplus;
			lazyplus=0;
		}
		leret=left->ask_min(hi,mg);
		riret=right->ask_min(hi,mg);
		return min(leret,riret);
	}*/
	T ask_max(int hi,int mg){
		//timecount++;//???
		if(hi<=seghi&&segmg<=mg){return treemax+lazyplus;}
		if(mg<=seghi||segmg<=hi){return -big;}
		T leret,riret;
		if(right!=NULL&&left!=NULL&&lazyplus!=0){
			right->lazyplus+=this->lazyplus;
			left->lazyplus+=this->lazyplus;
			treemax+=lazyplus;
			treemin+=lazyplus;
			lazyplus=0;
		}
		leret=left->ask_max(hi,mg);
		riret=right->ask_max(hi,mg);
		return max(leret,riret);
	}
};
const int mod=1e9+7;
//????????
int main(void){
	int i,j,n,m,q,w,ans=0;
	cin>>n>>m;
	maxeq(ans,n-m);
	vector<pair<int,int>>taka(n);
	seg_tree<int> isu(0,m+2);
	for(i=0;i<n;i++){cin>>q>>w;taka[i]=mp(q,w);}
	sort(taka.begin(),taka.end());
	for(i=0;i<m+2;i++){isu.seg_plus(i,i+1,i-m-1);}
	//ans=maxeq(ans,?????-????)
	//???????????????????
	for(i=0;i<n;i++){
		isu.seg_plus(0,taka[i].sec+1,1);
		int nowisu=isu.ask_max(0,m+2)-taka[i].fir;
		//cout<<"nowisu="<<nowisu<<endl;
		//for(j=0;j<m+2;j++){cout<<i<<" "<<j<<" "<<isu.ask_max(j,j+1)<<endl;}
		maxeq(ans,nowisu);
	}
	cout<<ans<<endl;
}