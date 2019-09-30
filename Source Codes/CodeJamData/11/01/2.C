#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>

using namespace std;

void do_case(void)
{
  int N;
  scanf("%d", &N);

  char robot;
  int but;

  int i;

  int time=0;
  int bpos=1,opos=1;
  int btime=0,otime=0;
  //  char last='O';
  for(i=0;i<N;++i){
    scanf(" %c %d", &robot, &but);

    if(robot == 'O'){
      int d = but - opos;
      if(d < 0) d = -d;
      if(d > otime){
        time += d - otime + 1;
        btime += d - otime + 1;
      }else{
        ++time;
        ++btime;
        //        if(last == 'O') otime = 0;
      }
      otime = 0;
      opos = but;
      //      last = 'O';
    }else{
      int d = but - bpos;
      if(d < 0) d = -d;
      if(d > btime){
        time += d - btime + 1;
        otime += d - btime + 1;
      }else{
        ++time;
        ++otime;
        //        if(last == 'B') btime = 0;
      }
      btime = 0;
      bpos = but;
      //      last = 'B';
    }
  }
  printf("%d\n", time);
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  int cases;
  scanf("%d\n", &cases);
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
