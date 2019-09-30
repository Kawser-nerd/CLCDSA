#include <iostream>
#include <string> 
#include <cassert>
#include <algorithm> 
#define NDEBUG
#ifdef NDEBUG
#define DBG(x) 
#else
#define DBG(x) x
#endif

using namespace std;

struct event{
  bool arrival; // true iff arrival 
  bool ata; // true if departure from a / adjusted arrival at a.
  int time; // time in minutes
};

bool operator<(const event &e1, const event &e2){
  if(e1.time < e2.time)
    return true;
  if(e1.time == e2.time){
    if(e1.arrival && !e2.arrival)
      return true;   
  }
  return false;
}

void readandsolve(int cse){
  int t, na, nb;
  cin >> t >> na >> nb;
  DBG(cout << t << na << nb << endl;)
  event *events = new event[2*na+2*nb];
  for(int i=0; i<2*na; i+=2){
    int hr,min;
    scanf("%d:%d", &hr, &min);

    events[i].ata = true;
    events[i].arrival=false;
    events[i].time = 60*hr + min;

    scanf("%d:%d", &hr, &min);
    events[i+1].ata = false;
    events[i+1].arrival=true;
    events[i+1].time = 60*hr + min + t;
  }
  for(int i=2*na; i<2*nb+2*na; i+=2){
    int hr,min;
    scanf("%d:%d", &hr, &min);
    events[i].ata = false;
    events[i].arrival=false;
    events[i].time = 60*hr + min;
    scanf("%d:%d", &hr, &min);
    events[i+1].ata = true;
    events[i+1].arrival=true;
    events[i+1].time = 60*hr + min + t;
  }
  
  sort(events,events+2*na+2*nb);
  int actr = 0;
  int bctr = 0;
  int amax = 0;
  int bmax = 0;

  for(int i=0; i<2*na+2*nb; ++i){
    DBG(cout << events[i].ata << " " << events[i].arrival << " " << events[i].time << endl;)
    int *counter = (events[i].ata ? &actr : &bctr);
    int *maxctr = (events[i].ata ? &amax : &bmax);
    if(events[i].arrival){
      (*counter)--;
    }
    else{
      (*counter)++;
      DBG(cout << *counter << " is the counter" << endl;)
      if(*maxctr < *counter){
	*maxctr = *counter;
      }
    }
  }
  cout << "Case #" << cse << ": " << amax << " " << bmax <<  endl; 
}

int main(){
  int n;
  cin >> n;
  for (int i=0; i<n; ++i){
    readandsolve(i+1);
  }
  return 0; 
}
