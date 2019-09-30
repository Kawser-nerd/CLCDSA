#include<iostream>
#include<cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int number = 0;
    cin >> number;
    char** input = new char*[number];

    for(int i = 0; i < number; i++){
        input[i] = new char[51];
        cin >> input[i];
    }
    char same[51] = {0};
    int count = 0;
    for(int i = 0; i < strlen(input[0]); i++){
        bool find = true;
        for(int j = 1; j < number; j++){
            char* ptr = NULL;
            ptr = strchr(input[j],input[0][i]);
            if(ptr== NULL){
                find = false;
            }
        }
        if(find){
            for(int j = 1; j < number; j++){
                char* ptr = NULL;
                ptr = strchr(input[j],input[0][i]);
                if(ptr != NULL){
                    *ptr = '*';
                }
            }
            same[count] = input[0][i];
            count ++;
        }
        
    }
    same[count] = '\0';
    sort(same,same+strlen(same));
    cout << same;
    return 0;
}