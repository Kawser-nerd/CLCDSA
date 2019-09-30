#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

vector<string> lst;

bool isgreatereq(string &a,string &b) {
	while(a[0]=='0') a=a.substr(1);
	while(b[0]=='0') b=b.substr(1);
	if(SZ(a)!=SZ(b)) return SZ(a)>SZ(b);
	return a>=b;
}

void run(int casenr) {
	char buff[200]; scanf("%s",buff); string a=buff; scanf("%s",buff); string b=buff;
	int ret=0;
	REPSZ(i,lst) if(isgreatereq(lst[i],a)&&isgreatereq(b,lst[i])) ++ret;
	printf("Case #%d: %d\n",casenr,ret);
}

void read() {
	FILE *fp = fopen("c.all", "r");
	char buff[200];
	while(fscanf(fp,"%s",buff)==1) lst.PB(buff);
}

bool ispalin(ll x) {
	char s[100]; int n=0;
	while(x!=0) { s[n++]='0'+x%10; x/=10; } s[n]='\0';
	for(int i=0;i<n-1-i;++i) if(s[i]!=s[n-1-i]) return false;
	return true;
}

string add(string a,string b,int times,int offset) {
	int c=0,alen=SZ(a),blen=SZ(b);
	for(int i=0;i<blen||c!=0;++i) {
		if(i<blen) c+=(b[blen-i-1]-'0')*times;
		if(c==0) continue;
		while(offset+i>=alen) { ++alen; a=string(1,'0')+a; }
		c+=a[alen-i-1-offset]-'0';
		a[alen-i-1-offset]='0'+c%10;
		c/=10;
	}
	return a;
}

string square(string s) {
	string ret; int slen=SZ(s);
	REPSZ(i,s) ret=add(ret,s,s[i]-'0',slen-1-i);
	return ret;
}

void test(const string &s) {
	string t=square(s); int slen=SZ(s),tlen=SZ(t);
	int cnt1=0; REP(i,slen) if(s[i]=='1') ++cnt1;
	bool ok=true;
	for(int j=0;j<tlen-1-j;++j) if(t[j]!=t[tlen-1-j]) { ok=false; break; }
//	if(!ok) printf("err: %s -> %s\n",s.c_str(),t.c_str());
//	if((cnt1<10)!=ok) printf("diff: %s -> %s\n",s.c_str(),t.c_str());
	if(!ok) return;
//	printf("%s -> %s\n",s.c_str(),t.c_str());
	printf("%s\n",t.c_str());
}

void testbf() {
	FORE(i,1,10000000) { if(ispalin(i)&&ispalin((ll)i*i)) printf("%d -> %lld\n",i,(ll)i*i);	}
}

void testbasic() {
	FORE(len,1,12) {
		int hlen=(len+1)/2;
		ll minprefix=1,maxprefix=10; REP(i,hlen-1) { minprefix*=10; maxprefix*=10; }
		for(ll i=minprefix;i<maxprefix;++i) {
			string s(len,'?');
			ll x=i; REP(j,hlen) { s[hlen-1-j]=s[len-hlen+j]='0'+x%10; x/=10; }
			test(s);
		} 
	}
}

void testdiglimit() {
	FORE(len,1,30) {
		int hlen=(len+1)/2;
		string s(len,'0'); s[0]=s[len-1]='1';
		while(true) {
			test(s);
			int at=hlen-1;
			while(at>=0&&s[at]=='1') { s[at]=s[len-1-at]='0'; --at; }
			if(at<0) break;
			++s[at]; if(len-1-at!=at) ++s[len-1-at];
		}
	}
}

void gen() {
	FORE(len,1,51) {
		int hlen=(len+1)/2;

		//1xxx1 -> max 9 ones in palindrome, can only be 2 in middle (if odd len) when max 4 ones
		string s1(len,'0'); s1[0]=s1[len-1]='1'; test(s1); // no extra ones
		if(1<hlen&&len%2==1) { string s8(len,'0'); s8[0]=s8[len-1]='1'; s8[hlen-1]='2'; test(s8); }
		FOR(i,1,hlen) { // at least one extra one
			string s2(len,'0'); s2[0]=s2[len-1]=s2[i]=s2[len-1-i]='1'; test(s2);
			if(i+1<hlen&&len%2==1) { string s9(len,'0'); s9[0]=s9[len-1]=s9[i]=s9[len-1-i]='1'; s9[hlen-1]='2'; test(s9); }
			FOR(j,i+1,hlen) { // at least two extra ones
				string s3(len,'0'); s3[0]=s3[len-1]=s3[i]=s3[len-1-i]=s3[j]=s3[len-j-1]='1'; test(s3);
				FOR(k,j+1,hlen) { // at least three extra ones
					string s4(len,'0'); s4[0]=s4[len-1]=s4[i]=s4[len-1-i]=s4[j]=s4[len-j-1]=s4[k]=s4[len-k-1]='1'; test(s4);
					if(len%2==1&&k+1<hlen) { // four extra ones, one if which is in the middle
						string s5(len,'0'); s5[0]=s5[len-1]=s5[i]=s5[len-1-i]=s5[j]=s5[len-j-1]=s5[k]=s5[len-k-1]=s5[hlen-1]='1'; test(s5);
					}
				}
			}
		}

		//2xxx2 -> almost all zeroes, only middle digit can be one (if odd len)
		string s6(len,'0'); s6[0]=s6[len-1]='2'; test(s6);
		if(1<hlen&&len%2==1) { string s7(len,'0'); s7[0]=s7[len-1]='2'; s7[hlen-1]='1'; test(s7); }

		//3 (only for len==1)
		if(len==1) test("3");
	}
}


int main() {
//	testbf();
//	testbasic();
//	testdiglimit();
//	gen();

	read();
	int n; scanf("%d",&n); FORE(i,1,n) run(i);

	return 0;
}