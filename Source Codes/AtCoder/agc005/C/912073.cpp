#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include<algorithm>
using namespace std;
int a[105];
int b[105];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int n;
    scanf("%d",&n);
    int ma = 0;
    int i;
    multiset<int> s;
    multiset<int>::iterator I;
    for(i=1;i<=n;i++)
        {
        scanf("%d",&a[i]);
        ma = max(ma,a[i]);
        s.insert(a[i]);
        b[a[i]]++;
    }
    if(ma%2==0)
        {
        i = ma/2;
        I = s.find(i);
        if(I==s.end())return printf("Impossible\n")*0;
        s.erase(I);
        for(i++;i<=ma;i++)
            {
            I = s.find(i);
           if(I==s.end())return printf("Impossible\n")*0;
        s.erase(I);
            I = s.find(i);
             if(I==s.end())return printf("Impossible\n")*0;
        s.erase(I);
        }
    }
    else {
        for(i=(1+ma)/2; i<=ma;i++)
            {
            I = s.find(i);
             if(I==s.end())return printf("Impossible\n")*0;
        s.erase(I);
            I = s.find(i);
             if(I==s.end())return printf("Impossible\n")*0;
        s.erase(I);
        }
    }
   // printf("remaining %d\n",s.size());
   if(s.size()==0) return  printf("Possible\n")*0;
    int mi = (1+ma)/2 + 1;
    if(*s.begin()<mi)return printf("Impossible\n")*0;
    printf("Possible\n");
    return 0;
}