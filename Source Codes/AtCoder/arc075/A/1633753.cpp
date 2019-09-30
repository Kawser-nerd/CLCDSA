//
// Created by Akifumi Ohata on 2017/09/29.
//


#include<iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    int N;

    cin >> N ;

    std::vector<int> scores;

    for(int n=0;n<N ;n++) {
        int tmp;
        cin >>tmp;

        scores.push_back(tmp);

    }

    std::sort(scores.begin(),scores.end());

    ONEMOER:

    int score_sum =std::accumulate(scores.begin(), scores.end(), 0);


    if(score_sum%10 ==0 && score_sum !=0){


        for(int k =0;k<scores.size();k++){
            if (scores[k] % 10 ==0){
                continue;
            }else{
                scores.erase(scores.begin()+k);
                goto ONEMOER;

            }

        }
       // scores.erase(scores.begin());

       // goto ONEMOER;

    }



    if(score_sum%10==0){
        score_sum=0;
    }

    cout << score_sum <<endl;

    return 0;
}