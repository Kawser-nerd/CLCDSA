#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");

long long eval[100];
double sval[100];

long long d[100][100];

double t[100][100];

int main(void)
{
    int ttt=0;
    fin >> ttt;
    int ct = 0;
    string s;
    
    cout.precision(9);
    fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
    
    while(ttt>0)
    {
        ct++;
        ttt--;
        
        double ans=0.0;
        int i,j,k;
        
        int n,q;
        
        fin >> n >> q;
        for(i=0;i<n; i++)
        {
            fin >> eval[i] >> sval[i];
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                fin >> d[i][j];
                if(i==j)
                    d[i][j]=0.0;
                t[i][j]=-1.0;
            }
        }
        for(k=0; k<n; k++)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(d[i][k]>=0 && d[k][j]>=0)
                    {
                        long long e = d[i][k]+d[k][j];
                        if(d[i][j]<0 || e<d[i][j])
                            d[i][j]=e;
                    }
                }
            }
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(d[i][j]<=eval[i])
                {
                    double tm = ((double)d[i][j])/sval[i];
                    if(t[i][j]<0 || tm < t[i][j])
                    {
                        //cout << i << " " << j << " " << tm << endl;
                        t[i][j]=tm;
                    }
                }
            }
        }
        
        for(k=0; k<n; k++)
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(t[i][k]>=0 && t[k][j]>=0)
                    {
                        double e = t[i][k]+t[k][j];
                        if(t[i][j]<0 || e<t[i][j])
                            t[i][j]=e;
//                        if(i==2 && k==3 && j==1)
//                        {
//                            cout << "X " << e << " " << t[i][j] << endl;
//                        }
                    }
                }
            }
        }
        //cout << t[2][1] << endl;
        
        
        
        cout << "Case #" << ct << ":";
        fout << "Case #" << ct << ":";
        
        for(k=0; k<q; k++)
        {
            
            fin >> i >> j;
            cout << " " << t[i-1][j-1];
            fout << " " << t[i-1][j-1];
        }
        
        
        
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

