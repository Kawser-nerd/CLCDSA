#include <iostream>
#include <string>

using namespace std;

int main(){
    
int h,w;

cin>>h>>w;

char arr[h][w];

for(int i=0;i<h;i++){
    
    for(int j=0;j<w;j++){
        cin>>arr[i][j];
    }
    cout<<endl;
}

char arr1[h+2][w+2];

for(int i=0;i<h;i++){
    
    for(int j=0;j<w;j++){
      arr1[i+1][j+1] =    arr[i][j];
    }
    
}

for(int i=0;i<h+2;i++){
    arr1[i][0]='#';
    arr1[i][w+1]='#';

}
for(int i=0;i<w+2;i++){
    arr1[0][i]='#';
    arr1[h+1][i]='#';
}



for(int i=0;i<h+2;i++){
    
    for(int j=0;j<w+2;j++){
        
        cout<<arr1[i][j];
        
    }cout<<endl;
}








    
}