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
        
        string ans;
        int i,j,k;
        
        int r,nr,y,ny,b,nb;
        
        int n;
        
        fin >> n >> r >> nb >> y >> nr >> b >> ny;
        
        vector<string> rval;
        vector<string> yval;
        vector<string> bval;
        
        bool isok = true;
        
        if(y+ny==n && y==ny)
        {
            for(i=0; i<y; i++)
            {
                ans+="YV";
            }
        }
        else if(r+nr==n && r==nr)
        {
            for(i=0; i<r; i++)
            {
                ans+="RG";
            }
        }
        else if(b+nb==n && b==nb)
        {
            for(i=0; i<b; i++)
            {
                ans+="BO";
            }
        }
        else
        {
            if(nr>0)
            {
                string s = "R";
                for(i=0; i<nr; i++)
                {
                    s+="GR";
                }
                rval.push_back(s);
                r-=(nr+1);
            }
            if(nb>0)
            {
                string s = "B";
                for(i=0; i<nb; i++)
                {
                    s+="OB";
                }
                bval.push_back(s);
                b-=(nb+1);
            }
            if(ny>0)
            {
                string s = "Y";
                for(i=0; i<ny; i++)
                {
                    s+="VY";
                }
                yval.push_back(s);
                y-=(ny+1);
            }
        }
        if(r<0 || b<0 || y<0)
        {
            isok=false;
        }
        else if(ans.size()==0){
            while(r>0)
            {
                rval.push_back("R");
                r--;
            }
            while(y>0)
            {
                yval.push_back("Y");
                y--;
            }
            while(b>0)
            {
                bval.push_back("B");
                b--;
            }
            
            vector<string> mx;
            vector<string> s1;
            vector<string> s2;
            
            if(rval.size()>=yval.size() && rval.size()>=bval.size())
            {
                mx=rval;
                s1=yval;
                s2=bval;
            }
            else if(yval.size()>=rval.size() && yval.size()>=bval.size())
            {
                mx=yval;
                s1=rval;
                s2=bval;
            }
            else{
                mx=bval;
                s1=rval;
                s2=yval;
            }
            if(mx.size()>s1.size()+s2.size())
                isok=false;
            else{
                while(mx.size()>0)
                {
                    ans+=mx[mx.size()-1];
                    mx.pop_back();
                    
                    if(s1.size()>s2.size())
                    {
                        ans+=s1[s1.size()-1];
                        s1.pop_back();
                    }
                    else{
                        ans+=s2[s2.size()-1];
                        s2.pop_back();
                    }
                }
                while(s1.size()>0 || s2.size()>0)
                {
                    if(s1.size() >0 && ans[ans.size()-1]!=s1[0][0])
                    {
                        ans+=s1[s1.size()-1];
                        s1.pop_back();
                    }
                    if(s2.size()>0 && ans[ans.size()-1]!=s2[0][0])
                    {
                        ans+=s2[s2.size()-1];
                        s2.pop_back();
                    }
                }
            }
            
        }
        if(!isok)
            ans="IMPOSSIBLE";
        
        
        cout << "Case #" << ct << ": ";
        fout << "Case #" << ct << ": ";
        
        
        cout << ans;
        fout << ans;
        
        
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

