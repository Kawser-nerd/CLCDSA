using System;
using System.Collections.Generic;
class Solve{
    public int h;
    public int w;
    public int gi,gj;
    public bool[,] a;
    int count;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    int Min(int i1,int i2){
        if(i1 < i2){
            return i1;
        }
        else{
            return i2;
        }
    }
    int Max(int i1,int i2){
        if(i1 > i2){
            return i1;
        }
        else{
            return i2;
        }
    }
    void Calc(){
        getinput();
        int[,] sumvertical = new int[h+1,w];
        int[,] sumhorizontal = new int[h,w+1];
        int[,,,] dp = new int[h-gi,gi+1,w-gj,gj+1];
        for(int i = 0;i < w;i++){
            sumvertical[0,i] = 0;
        }
        for(int i = 0;i < h;i++){
            sumhorizontal[i,0] = 0;
        }
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(a[i,j]){
                    sumvertical[i+1,j] = sumvertical[i,j] + 1;
                    sumhorizontal[i,j+1] = sumhorizontal[i,j] + 1;
                }
                else{
                    sumvertical[i+1,j] = sumvertical[i,j];
                    sumhorizontal[i,j+1] = sumhorizontal[i,j];
                }
            }
        }
        for(int i = 0;i < h-gi;i++){
            for(int j = 0;j < gi+1;j++){
                for(int k = 0;k < w-gj;k++){
                    for(int l = 0;l < gj+1;l++){
                        int max = 0;
                        if(i !=0){
                            if(gi+i < h-j){
                                int left = Max(k,gj-l);
                                int right = Min(w-l-1,gj+k);
                                if(left <= right && max < sumhorizontal[gi+i,right+1] - sumhorizontal[gi+i,left] + dp[i-1,j,k,l])
                                    max = sumhorizontal[gi+i,right+1] - sumhorizontal[gi+i,left] + dp[i-1,j,k,l];
                                if(left > right && max < dp[i-1,j,k,l])
                                    max = dp[i-1,j,k,l];
                            }
                            else{
                                if(max < dp[i-1,j,k,l]){
                                    max = dp[i-1,j,k,l];
                                }
                            }
                        }
                        if(j != 0){
                            if(gi-j >= i){
                                int left = Max(k,gj-l);
                                int right = Min(w-l-1,gj+k);
                                if(left <= right && max < sumhorizontal[gi-j,right+1] - sumhorizontal[gi-j,left] + dp[i,j-1,k,l])
                                    max = sumhorizontal[gi-j,right+1] - sumhorizontal[gi-j,left] + dp[i,j-1,k,l];
                                if(left > right && max < dp[i,j-1,k,l])
                                    max = dp[i,j-1,k,l];
                            }
                            else{
                                if(max < dp[i,j-1,k,l]){
                                    max = dp[i,j-1,k,l];
                                }
                            }
                        }
                        if(k != 0){
                            if(gj+k < w-l){
                                int bottom = Max(i,gi-j);
                                int top = Min(h-j-1,gi+i);
                                if(bottom <= top && max < sumvertical[top+1,gj+k] - sumvertical[bottom,gj+k] + dp[i,j,k-1,l])
                                    max = sumvertical[top+1,gj+k] - sumvertical[bottom,gj+k] + dp[i,j,k-1,l];
                                if(bottom > top && max < dp[i,j,k-1,l])
                                    max = dp[i,j,k-1,l];
                            }
                            else{
                                if(max < dp[i,j,k-1,l]){
                                    max = dp[i,j,k-1,l];
                                }
                            }
                        }
                        if(l != 0){
                            if(gj-l >= k){
                                int bottom = Max(i,gi-j);
                                int top = Min(h-j-1,gi+i);
                                if(bottom <= top && max < sumvertical[top+1,gj-l] - sumvertical[bottom,gj-l] + dp[i,j,k,l-1])
                                    max = sumvertical[top+1,gj-l] - sumvertical[bottom,gj-l] + dp[i,j,k,l-1];
                                if(bottom > top && max < dp[i,j,k,l-1])
                                    max = dp[i,j,k,l-1];
                            }
                            else{
                                if(max < dp[i,j,k,l-1]){
                                    max = dp[i,j,k,l-1];
                                }
                            }
                        }
                        dp[i,j,k,l] = max;
                    }
                }
            }   
        }
        Console.WriteLine(dp[h-gi-1,gi,w-gj-1,gj]);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        h = int.Parse(str[0]);
        w = int.Parse(str[1]);
        a = new bool[h,w];
        for(int i = 0;i < h;i++){
            string s = Console.ReadLine();
            for(int j = 0;j < w;j++){
                if(s[j] == 'o'){
                    a[i,j] = true;
                }
                else{
                    a[i,j] = false;
                }
                if(s[j] == 'E'){
                    gi = i;
                    gj = j;
                }
            }
        }
    }     
}