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
        
        double ans=0.0;
        int i,j,k;
        
        int n;
        
        int d;
        
        fin >> d >> n;
        
        for(i=0;i<n; i++)
        {
            double a,b;
            
            fin >> a >> b;
            
            //cout << a << " " << b << " " << d << " " << ans << endl;
            
            double tm = ((double)d-a)/b;
            
            if(tm>ans)
                ans=tm;
        }
        ans = ((double)d)/ans;
        
        cout << "Case #" << ct << ": ";
        fout << "Case #" << ct << ": ";
        
        
        cout << ans;
        fout << ans;
        
        
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

