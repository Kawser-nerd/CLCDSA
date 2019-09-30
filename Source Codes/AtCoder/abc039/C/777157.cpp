#include<iostream>
using namespace std;

int main(){
  int i;
  int b=0;
  char s[20];
  int breakb=0;

  for(i=0;i<20;i++) cin >> s[i];

  for(i=0;i<20;i++){
    switch(s[i]){
    case 'W':
      if(i>0){
        if(s[i-1] == 'W'){
          if(b==3) breakb = 1;
          else  b = 0;
        }
      }
      break;
    case 'B':
      b++;
      break;
    }
    if(breakb) break;
  }

  switch(i){
  case 12:
    cout << "Do" << endl;
    break;
  case 10:
    cout << "Re" << endl;
    break;
  case 8:
    cout << "Mi" << endl;
    break;
  case 7:
    cout << "Fa" << endl;
    break;
  case 17:
    cout << "So" << endl;
    break;
  case 15:
    cout << "La" << endl;
    break;
  case 13:
    cout << "Si" << endl;
    break;
  }
  return 0;
}