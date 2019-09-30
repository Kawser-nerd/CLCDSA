#include <algorithm>
#include <iostream> 
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, k;
string poly;
string s[100];
int cnt[100][4];

int m;
int ch[4], pw[4];

int ret[11];
int curr[4];

void rec( int taken ) {
    for( int i = 0; i < n; ++i ) {
        for( int j = 0; j < m; ++j ) curr[j] += cnt[i][j];
        
        int eval = 1;
        for( int j = 0; j < m; ++j ) 
            for( int pp = 0; pp < pw[j]; ++pp )
                eval = (eval * curr[j]) % 10009;
        ++taken;
        ret[taken] = (ret[taken] + eval) % 10009;
        
        if( taken < k ) rec( taken );
        
        --taken;
        for( int j = 0; j < m; ++j ) curr[j] -= cnt[i][j];
    }
}

int main( void ) {
    int T;
    cin >> T;
    for( int tt = 1; tt <= T; ++tt ) {
        cin >> poly >> k;
        cin >> n;
        for( int i = 0; i < n; ++i ) 
            cin >> s[i];
        
        vector<string> terms;
        while( poly.find( "+" ) != string::npos ) {
            terms.push_back( poly.substr( 0, poly.find("+") ) );
            poly = poly.substr( poly.find("+")+1 );
        }
        terms.push_back( poly );

        for( int i = 1; i <= k; ++i ) ret[i] = 0;
        
        for( vector<string>::iterator it = terms.begin(); it != terms.end(); ++it ) {
            string term = *it;
            map<char, int> mmm;
            for( int i = 0; i < term.size(); ++i ) 
                ++mmm[term[i]];
            m = 0;
            for( map<char,int>::iterator it = mmm.begin(); it != mmm.end(); ++it ) {
                ch[m] = it->first;
                pw[m] = it->second;
                ++m;
            }

            for( int i = 0; i < n; ++i ) {
                for( int j = 0; j < 4; ++j ) cnt[i][j] = 0;
                for( int t = 0; t < s[i].size(); ++t ) 
                    for( int j = 0; j < m; ++j ) 
                        if( s[i][t] == ch[j] )
                            ++cnt[i][j];
            }
            
            rec( 0 );
        }

        printf( "Case #%d:", tt );
        for( int i = 1; i <= k; ++i ) printf( " %d", ret[i] );
        printf( "\n" );
    }
    return 0;
}
