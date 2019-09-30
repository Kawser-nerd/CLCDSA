#include <iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    
    if(c=='a'||c=='e'||c=='u'||c=='i'||c=='o'){
        cout << "vowel";
    }
    else{
        cout << "consonant";
    }
}