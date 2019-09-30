/**********************************************************************
Author: hanshuai
Created Time:  2011/6/11 22:31:15
File Name: A.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
const double eps = 1e-9;
int W, G;
struct Pt{
    int x, y;
    Pt(){}
    Pt(int _x, int _y):x(_x),y(_y){}
};
struct PL{
    vector<Pt > vp;
    int sz;
    void input(){
        vp.clear();
        for(int i = 0; i < sz; i ++){
            int x, y;
            scanf("%d%d", &x, &y);
            y += 2000;
            vp.push_back(Pt(x, y));
        }
    }
    vector<double> area;
    void init(){
        area = vector<double>(sz);
        for(int i = 0; i < sz; i ++){
            if(i == 0) area[i] = 0;
            else{
                double v = vp[i-1].y + vp[i].y;
                double h = vp[i].x - vp[i-1].x;
                area[i] = (v*h)/2;
            }
        }
    }
    double getArea(double x){
        double ret = 0;
        for(int i = 1; i < sz; i ++){
            if(vp[i].x > x - eps){
                double len1 = vp[i].x - vp[i-1].x;
                double len2 = x - vp[i-1].x;
                double y = (vp[i].y-vp[i-1].y)*(len2/len1) + vp[i-1].y;
                
                double v = vp[i-1].y + y;
                double h = x - vp[i-1].x;
                ret += (v*h)/2;
                break;
            }else{
                ret += area[i];
            }
        }
        return ret;
    }
}XL, XU;
double getA(double x){
    return XU.getArea(x) - XL.getArea(x);
}
int main() {
    freopen("A.out", "w", stdout);
    int test, cas = 0;
    scanf("%d", &test);
    while(test --){
        printf("Case #%d:\n", ++cas);
        int L, U;
        scanf("%d%d%d%d", &W, &L, &U, &G);
        XL.sz = L; XU.sz = U;
        XL.input(); XU.input();
        XL.init(); XU.init();
        double sum = getA(W);
        double need = 0;
        for(int i = 1; i < G; i ++){
            need += sum / G;
            double l = 0, r = W, mid;
            for(int j = 0; j < 50; j ++){
                mid = (l + r)/2;
                if(getA(mid) > need) r = mid;
                else l = mid;
            }
            printf("%.10lf\n", mid);
        }
        fprintf(stderr, "cas = %d\n", cas);
//        printf("%lf\n", sum);
//        printf("%lf\n", getA(4.29));
    }
    return 0;
}

