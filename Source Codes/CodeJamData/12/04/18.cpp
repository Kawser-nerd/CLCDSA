#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <time.h>
#include <memory>
using namespace std;

typedef long long LL;
typedef long long uLL;
typedef unsigned int uint;
#define FOR(i, b, e) for(int i=(b); i<int(e); ++i)
#define FORV(i, b, e) for(i=(b); i<(e); ++i)
#define GET(a) cin >> a
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PB(a) push_back(a)
#define SIZE(a) a.size()
#define PEEK(a) cout << " >> " #a " = " << a << endl
#define peek(a) _peek(#a, a)
template <typename T> void _peek(char name[], T &obj, size_t max_count=32){
    const size_t ipl = 10;
    cout << " >> " << name << " = ["; size_t _count = 0;
    for(typename T::iterator it=obj.begin(); it!=obj.end(); ++it){
        if(_count && _count%ipl == 0) cout << "      [";
        cout << *it; ++_count;
        if(_count%ipl == 0 || _count >= max_count || it == obj.end()-1) cout << " ]\n";
        else cout << ", ";
        if(_count >= max_count) break;
    }
}
template <typename T> ostream &operator << (ostream &cout, pair<T, T> &x){
    cout << "(" << x.first << "," << x.second << ")";
    return cout;
}
template <typename T> inline T GCD(T a, T b){
    if(b==0) return a;
    a %= b; while(a){ swap(a, b); a %= b; }; return b;
}
template <typename T> inline T LCM(T a, T b){
    if(a == 0 || b == 0) return -1;
    a /= GCD(a, b);	T lcm = a * b;
    if(lcm < 0 || lcm/a != b ) return -1;
    return lcm;
}
//===========================================================
int T, test_case;
int H, W;
double D;
char grid[40][40];
bool visited[200][200];
const double error = 1e-7;

int r0, c0;
bool isValid(double dx, double dy){
    double x0 = 2*r0+1; double y0 = 2*c0+1; 
    int r=r0; int c=c0; //current grid
    double x = x0, y = y0; //current position
    double t = D;
    int nr, nc;
    while(t > -error){
        if(t != D && grid[r][c] == '#'){
            if(abs(x-2*nr) > error){
                c += dy>0? -1 : 1;
                dy = -dy;
                continue;
            }
            else if (abs(y-2*nc) > error){
                r += dx>0? -1 : 1;
                dx = -dx;
                continue;
            }
            else if (grid[r+(dx>0? -1 : 1)][c] == '#'){
                c += dy>0? -1 : 1;
                dy = -dy;
                continue;
            }
            else if (grid[r][c+(dy>0? -1 : 1)] == '#'){
                r += dx>0? -1 : 1;
                dx = -dx;
                continue;
            }
            else
                return false;
        }

        double dt, dt1;
        if(r == r0 && c == c0 && t < D){
            if(dx){
                dt = (x0-x)/dx;
                if(dt > 0 && abs(y0 - y - dy*dt) < error && dt < t+error)
                    return true;
            }
            else {
                dt = (y0-y)/dy;
                if(dt > 0 && abs(x0 - x - dx*dt) < error && dt < t+error)
                    return true;
            }
        }

        //move to the next grid
        bool goX = true;
        nr = r + (dx>0? 1: 0);
        nc = c + (dy>0? 1: 0);
        double br = 2*nr; double bc = 2*nc;
        dt = 1000000000.; dt1 = 1000000000.; 
        if(dx){
            dt = (br-x)/dx;
            if(dy){
                dt1 = (bc-y)/dy;
                if(dt1 < dt){
                    dt1; goX =false;
                }
            }               
        }
        else{
            dt1 = (bc-y)/dy; goX = false;
        }

        if(abs(dt-dt1) < error){
            r += dx>0? 1 : -1; c += dy>0? 1 : -1;
            x = br; y = bc; t -= dt;
        }
        else{
            if(goX){
                r += dx>0? 1 : -1; x = br; y += dt*dy; t -= dt;
            }
            else{
                c += dy>0? 1 : -1; x += dt1*dx; y = bc; t -= dt1;
            }
        }

        if(nc == -1 || nc == W || nr == -1 || nr == H)
            return false;
    }

    return false;
}


int solve(){
    memset(visited, false, sizeof(visited));
    int ans=0;
    FOR(i, -50, 51) FOR(j, -50, 51) if(i!=0 || j!=0){      
        int ti = i>0? i: -i; int tj = j>0? j: -j;
        int gcd = GCD(ti, tj);
        if(visited[100 + i/gcd][100 + j/gcd]) 
            continue;

        visited[100 + i/gcd][100 + j/gcd] = true;

        double dx = i/gcd; double dy = j/gcd;
        double dr = sqrt(dx*dx + dy*dy);
        if(dr > (double)D-error) continue;
        
        dx /= dr; dy /= dr;
        if(isValid(dx, dy)) ++ans;
    }

    return ans;
}


int _tmain(int argc, _TCHAR* argv[])
{
    //freopen("z:\\input.txt", "r", stdin);
    freopen("z:\\output.txt", "w", stdout);
    //freopen("z:\\D-small-attempt0.in", "r", stdin);
    freopen("z:\\D-large.in", "r", stdin);


    GET(T);
    FORV(test_case, 1, T+1)
    {
        GET(H); GET(W); GET(D); D*=2.;
        FOR(i, 0, H) FOR(j, 0, W) {
            GET(grid[i][j]);
            if(grid[i][j] == 'X'){
                r0 = i; c0 = j;
            }
        }
        
        cout << "Case #" << test_case << ": " << solve() <<endl;
    }

    return 0;
}

