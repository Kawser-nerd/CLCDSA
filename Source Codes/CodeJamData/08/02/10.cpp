#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int, int> readTableLine(){
	int hs, ms, ha, ma;
	scanf("%d:%d %d:%d", &hs, &ms, &ha, &ma);
	return make_pair(60*hs+ms, 60*ha+ma);
}

int readi(){
	int k; 
	scanf("%d",&k);
	return k;
}

struct trainEvent{
	int time;
	char station, type;
	bool operator<(const trainEvent &sec) const{
		if(time==sec.time)
			return type<sec.type;
		return time<sec.time;
	}
};

bool possible(int A, int B, vector<trainEvent> &events){
	int Av[2]={A,B};
	for(int i=0; i<events.size(); i++){
		if(events[i].type=='D'){
			if(Av[events[i].station]==0)
				return false;
			else
				Av[events[i].station]--;
		}
		else
			Av[events[i].station]++;
	}
	return true;
}
int main(){
	for(int test=1, testCount=readi(); test<=testCount; test++){
		int T = readi(), N[2];
		N[0]=readi(); N[1]=readi();
		vector<trainEvent> events;
		for(int S=0; S<2; S++){
			for(int i=0; i<N[S]; i++){
				pair<int,int> times=readTableLine();
				trainEvent te;
				te.time=times.first;
				te.station=S;
				te.type='D';
				events.push_back(te);
				te.time=times.second+T;
				te.station=1-S;
				te.type='A';
				events.push_back(te);
			}
		}
		sort(events.begin(), events.end());
		for(int A=0; A<=N[0]; A++)
			for(int B=0; B<=N[1]; B++)
				if(possible(A, B, events)){
					printf("Case #%d: %d %d\n", test, A, B);
					goto break2;
				}
break2:;
	}
	return 0;
}
