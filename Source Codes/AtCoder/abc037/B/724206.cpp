#include <iostream>
#include <fstream>

using namespace std;

#define fin cin

//B
int main(){
   // ifstream fin("in.txt");
    int n, q;
    fin >> n >> q;
    
    int a[100] = {};
    for(int i = 0; i < q; i++){
        int begin, end, num;
        fin >> begin >> end >> num;

        for(int j = begin- 1 ; j < end; j++)a[j] = num;
        
    }
    
    for(int i = 0; i < n; i++)cout << a[i] << endl;
    
    
    return 0;
}