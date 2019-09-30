#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
//??????
#define DEB(variable) cout << #variable << '=' << variable << endl

//for????(??????)
#define FOR(LoopVariable,numberOFbegin,numberOFend) for (int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define REP(LoopVariable,numberOFend) for(int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)


int main(){

    int n;
    cin >> n;cin.ignore(); // ????????(????????)??1????????
    string s;
    getline(cin, s);

    bool space_flag = 1,first_letter_flag=0;

    int m = s.size();
    REP(i,m){
        if(s[i]=='b'||s[i]=='B'||s[i]=='c'||s[i]=='C'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 1;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='d'||s[i]=='D'||s[i]=='w'||s[i]=='W'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 2;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='t'||s[i]=='T'||s[i]=='j'||s[i]=='J'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 3;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='f'||s[i]=='F'||s[i]=='q'||s[i]=='Q'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 4;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='l'||s[i]=='L'||s[i]=='v'||s[i]=='V'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 5;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='s'||s[i]=='S'||s[i]=='x'||s[i]=='X'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 6;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='p'||s[i]=='P'||s[i]=='m'||s[i]=='M'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 7;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='h'||s[i]=='H'||s[i]=='k'||s[i]=='K'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 8;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='n'||s[i]=='N'||s[i]=='g'||s[i]=='G'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 9;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]=='z'||s[i]=='Z'||s[i]=='r'||s[i]=='R'){
            if(space_flag==0&&first_letter_flag==1){
                cout << " ";
            }
            cout << 0;
            space_flag = 1;
            first_letter_flag=1;
        }else if(s[i]==' '&&space_flag==1){
            
            space_flag = 0;
        }
    }

    cout << endl;
    return 0;
}