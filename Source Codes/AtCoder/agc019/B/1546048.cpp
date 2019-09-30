#define _CRT_SECURE_NO_WARNINGS
        #include<iostream>
        #include<string>
        #include<sstream>
        #include<algorithm>
        #include<cmath>
        #include<vector>
        #include <map>
        #include <set>
        #include <list>
        #include<fstream>
        #include<stdio.h>
        #include<iomanip>
        #include<climits>
        #include<list>
        #include <functional>
        #include <utility>
        #include <numeric>
        #define all(v) ((v).begin()),((v).end())
        #define sz(v) ((int)(v).size())
        #define PI 3.14159265
        typedef long long ll;
        typedef unsigned long long ull;
        using namespace std;
        int  main()
        {
        	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        	//freopen("input.txt", "r", stdin);
        	//freopen("out.txt", "w", stdout);
        	///////////////////////////////////////////

        	string s;
        	cin >> s;
   map<char,ll>mp;ll ans=0;
   for(int i=0;i<sz(s);i++)
   {
     mp[s[i]]++;

   }
 ans=sz(s);
 ans=(ans*(ans-1))/2;
// cout<<mp['a']<<endl;
 for(char i='a';i<='z';i++){

     if(mp[i]>1)
        ans-=(mp[i]*(mp[i]-1)/2);
 }
 cout<<ans+1<<endl;
}