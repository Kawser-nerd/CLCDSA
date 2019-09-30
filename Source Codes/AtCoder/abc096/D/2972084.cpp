#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<algorithm>
#define L long long
#include<string.h>
#include <math.h>
using namespace std;
int n;
long long area;
int a [60]={2,3,13,23,43,53,73,83,103,113,163,173,193,223,233,263,283,293,313,353,373,383,433,443,463,503,523,563,593,613,643,653,673,683,733,743,773,823,853,863,883,953,983,1013,1033,1063,1093,1103,1123,1153,1163,1193,1213,1223,1283,1303,1373};
int  main()
{
       while(cin>>n)
       {
           for(int i=0;i<n-1;i++)
            cout<<a[i]<<' ';
           cout<<a[n-1]<<endl;
       }

    return 0;
}