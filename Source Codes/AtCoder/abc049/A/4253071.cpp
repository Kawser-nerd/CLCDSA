#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
int main()
{

    char c;
    cin>>c;
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        cout<<"vowel";
    }
    else
    {
        cout<<"consonant";
    }
    return 0;
}