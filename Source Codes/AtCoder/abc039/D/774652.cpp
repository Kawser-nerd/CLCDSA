#include <iostream>

using namespace std;

int H, W;
int a[100][100];

// ???0?????????????
void check(int i, int j) {
    if (a[i][j] == 1) {
        bool b = true;
        if (i > 0) {
            if (j > 0) {     if (a[(i-1)][(j-1)] == 0) { b = false; } }
                             if (a[(i-1)][(j  )] == 0) { b = false; }
            if (j < (W-1)) { if (a[(i-1)][(j+1)] == 0) { b = false; } }
        }

            if (j > 0) {     if (a[(i  )][(j-1)] == 0) { b = false; } }
            if (j < (W-1)) { if (a[(i  )][(j+1)] == 0) { b = false; } }

        if (i < (H-1)) {
            if (j > 0) {     if (a[(i+1)][(j-1)] == 0) { b = false; } }
                             if (a[(i+1)][(j  )] == 0) { b = false; }
            if (j < (W-1)) { if (a[(i+1)][(j+1)] == 0) { b = false; } }
        }
    
        if (b) {
            a[i][j] = 2;
        }
    }
}

// ???1?????????
bool check2(int i, int j) {
    bool b = true;
    if (i > 0) {
        if (j > 0) {
            if (a[(i-1)][(j-1)] > 1) { b = false; }
        }
        
        if (a[(i-1)][(j)] > 1) { b = false; }
        
        if (j < (W-1)) {
            if (a[(i-1)][(j+1)] > 1) { b = false; }
        }
    }
    
    if (j > 0) {
        if (a[(i)][(j-1)] > 1) { b = false; }
    }
    
    if (a[(i)][(j)] > 1) { b = false; }
    
    if (j < (W-1)) {
        if (a[(i)][(j+1)] > 1) { b = false; }
    }
    
    if (i < (H-1)) {
        if (j > 0) {
            if (a[(i+1)][(j-1)] > 1) { b = false; }
        }
        
        if (a[(i+1)][(j)] > 1) { b = false; }
        
        if (j < (W-1)) {
            if (a[(i+1)][(j+1)] > 1) { b = false; }
        }
    }
    
    return b;
}

int main()
{

    cin >> H >> W;

    for (int i=0; i<H; i++) {
        string s;
        cin >> s;
        
        for (int j=0; j<W; j++) {
            a[i][j] = ((s[j]=='#') ? 1 : 0);
        }
    }
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            check(i, j);
        }
    }
    
    bool possible = true;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (a[i][j] == 1) {
                if(check2(i, j)) {
                    possible = false;
                }
            }
            
        }
    }
    
    if (possible) {
        cout << "possible" << endl;
        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                cout << ((a[i][j] > 1) ? '#' : '.');
            }
            cout << endl;
        }
        
    } else {
        cout << "impossible" << endl;
    }
    
    return 0;
}