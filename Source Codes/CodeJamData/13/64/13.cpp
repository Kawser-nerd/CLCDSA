using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<cmath>
#include<set>
inline int length(pair<int,int> p) {
	return p.second-p.first+1;
}
inline pair<int,int> mymax(pair<int,int> a,pair<int,int> b) {
	if (length(a) < length(b)) return b; else
	if (length(a) > length(b)) return a; else
	return (a.first < b.first) ? a : b;
}
void compress(vector<pair<int,int> > & segments) {
  if (segments.empty()) return;
  sort(segments.begin(),segments.end());
  vector<pair<int,int> > re;
  re.push_back(segments[0]);
  for (vector<pair<int,int> >::iterator it=segments.begin(); it!=segments.end(); ++it) {
    int l = (*it).first, r = (*it).second;
    int & rlast(re.back().second);
    if(l<=rlast+1)rlast=max(rlast,r);
    else re.push_back(*it);
  }
  segments = re;
}
pair<int,int> test(vector<pair<int,int> >&segments1,vector<pair<int,int> >&segments2) {
	if (segments1.size() > segments2.size()) return test(segments2,segments1);
	//cout << "sz1 = " << segments1.size() << ", sz2 = " << segments2.size() << endl;
	vector<pair<int,int> > v;
	for (vector<pair<int,int> >::iterator it=segments1.begin(); it!=segments1.end(); ++it) {
		int l = (*it).first, r = (*it).second;
		//cout<<l<<","<<r<<endl;
		// find indices within segments1 which are united
		int idx1 = lower_bound(segments2.begin(),segments2.end(),make_pair(l,l))-segments2.begin();
		if (idx1 > 0 and segments2[idx1-1].second >= l-1) {
			idx1 --;
		}
		//cout<<"idx1="<<idx1<<endl;
		int idx2 = lower_bound(segments2.begin(),segments2.end(),make_pair(r+1,r+1))-segments2.begin();
		//cout<<":"<<idx2<<endl;
		//cout<<segments1.size()<<endl;
		if (idx2 == (int) segments2.size() or segments2[idx2].first != r+1) {
			idx2 --;
		}
		//cout<<"idx2="<<idx2<<endl;
		if (idx1 <= idx2) {
			v.push_back(make_pair(min(segments2[idx1].first,l),max(segments2[idx2].second,r)));
		} else {
			v.push_back(make_pair(l,r));
		}
		//cout << "[" << v.back().first << " " << v.back().second << "]" << endl;
	}
	pair<int,int> answer(0,0);
	compress(v);
	for (vector<pair<int,int> >::iterator it=v.begin(); it!=v.end(); ++it) {
		//cout<<(*it).first << " " << (*it).second << endl;
		answer = mymax(answer, *it);
	}
	return answer;
}
pair<int,int>solve(int n,int D,vector<vector<int> > aa) {
	vector<vector<pair<int,int> > > segments (100005);
	pair<int,int> answer (0,0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<(int)aa[i].size(); j++) {
			int val = aa[i][j];
			if (segments[val].empty() or segments[val].back().second != i-1) {
				segments[val].push_back(make_pair(i,i));
			} else {
				segments[val].back().second ++;
			}
			//cout<<segments[val].back().first<<" "<<segments[val].back().second << endl;
			answer = mymax(answer, segments[val].back());
		}
	}
	//cout<<"solve:"<<answer.first<<" "<<answer.second<<endl;
	/*for (int v=1; v<=5; v++) {
		for (vector<pair<int,int> >::iterator it=segments[v].begin(); it!=segments[v].end(); ++it) {
			//cout<<(*it).first<<"--"<<(*it).second<<", ";
		}
		//cout<<endl;
	}*/
	set<pair<int,int> > done;
	for (int i=0; i+1<n; i++) {
		for (vector<int>::iterator it1=aa[i].begin(); it1!=aa[i].end(); ++it1) {
			int value = *it1;
			for (vector<int>::iterator it2=aa[i+1].begin(); it2!=aa[i+1].end(); ++it2) {
				int value2 = *it2;
				pair<int,int> p (value,value2);
				if (done.count(p)) continue;
				//cout<<"test "<<value<<","<<value2<<endl;
				answer = mymax(answer, test(segments[value], segments[value2]));
				done.insert(p);
			}
		}
	}
	//cout<<"solve:"<<answer.first<<" "<<answer.second<<endl;
	return answer;
}
pair<int,int>bruteforce(int n,int D,vector<vector<int> > vv) {
	pair<int,int>answer(0,0);
	for (int i1=1; i1<=10; i1++) {
		for (int i2=1; i2<=10; i2++) {
			for (int l=0; l<n; l++) {
				for (int r=l; r<n; r++) {
					bool ok=true;
					for (int i=l; i<=r; i++) {
						if (find(vv[i].begin(),vv[i].end(),i1)==vv[i].end())
						if (find(vv[i].begin(),vv[i].end(),i2)==vv[i].end())
						ok=false;
					}
					if (ok)answer=mymax(answer,make_pair(l,r));
				}
			}
		}
	}
	cout<<"brute:"<<answer.first<<" "<<answer.second<<endl;
	return answer;
}
int main() {
	int T;
	scanf("%d",&T);
	/*while (true) {
		int n = 10;
		int D = 3;
		cout<<endl<<endl;
		vector<vector<int> > aa(n,vector<int>(D));
		cout << "generate: " << endl;
		for (int i=0; i<n; i++) {
			for (int j=0; j<D; j++) {
				aa[i][j]=1+rand()%5;
				printf("%d ",aa[i][j]);
			}
			cout<<endl;
			sort(aa[i].begin(),aa[i].end());
			aa[i].erase(unique(aa[i].begin(),aa[i].end()),aa[i].end());
		}
		cout << "ok" << endl;
		assert(bruteforce(n,D,aa)==solve(n,D,aa));
	}*/
	for (int caseID=1; caseID<=T; caseID++) {
		int n;
		int D;
		int k;
		scanf("%d%d%d",&n,&D,&k);
		vector<vector<int> > aa (n, vector<int> (D));
		//vector<set<int> > first_not (100005);
		for (int i=0; i<n; i++) {
			for (int j=0; j<D; j++) {
				scanf("%d",&aa[i][j]);
			}
			sort(aa[i].begin(),aa[i].end());
			aa[i].erase(unique(aa[i].begin(),aa[i].end()),aa[i].end());
		}
		//assert(bruteforce(n,D,aa)==solve(n,D,aa));
		pair<int,int> answer = solve(n,D,aa);
		cout << "Case #" << caseID << ": " << answer.first << " " << answer.second << endl;
	}
}
