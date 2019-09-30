using System;
using System.Collections.Generic;
class Solve{
    public int h;
    public int w;
    public bool[][] a;
    long[][] watched;
    bool[][] blue;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void dfs(int i,int j,long k){
        watched[i][j] = k;
        blue[i][j] = true;
        if(i != h-1 && watched[i+1][j] == 0 && a[i+1][j]){
            dfs(i+1,j,k);
        }
        if(i != 0 && watched[i-1][j] == 0 && a[i-1][j]){
            dfs(i-1,j,k);
        }
        if(j != w-1 && watched[i][j+1] == 0 && a[i][j+1]){
            dfs(i,j+1,k);
        }
        if(j != 0 && watched[i][j-1] == 0 && a[i][j-1]){
            dfs(i,j-1,k);
        }
    }
    void Calc(){
        getinput();
        long count = 0;
        watched = new long[h][];
        blue = new bool[h][];
        for(int i = 0;i < h;i++){
            watched[i] = new long[w];
            blue[i] = new bool[w];
            for(int j = 0;j < w;j++){
                watched[i][j] = 0;
                if(i == 0){
                    blue[i][j] = true;
                }
                else{
                    blue[i][j] = false;
                }
            }
        }
        for(int i = h-1;i >= 1;i--){
            for(int j = 1;j < w-1;j++){
                if(a[i][j] && watched[i][j] == 0){
                    int k = 1;
                    count++;
                    dfs(i,j,count);
                    while(i-k > 0){
                        if(a[i-k][j]){
                            if(watched[i-k][j] == 0){
                                dfs(i-k,j,count);
                            }
                            else if(watched[i-k][j] != count){
                                break;
                            }
                        }
                        else{
                            blue[i-k][j] = true;
                            if(a[i-k][j-1] && watched[i-k][j-1] == 0){
                                dfs(i-k,j-1,count);
                            }
                            if(a[i-k][j+1] && watched[i-k][j+1] == 0){
                                dfs(i-k,j+1,count);
                            }
                            if((a[i-k][j-1] && watched[i-k][j-1] != count) || (a[i-k][j+1] && watched[i-k][j+1] != count)){
                                break;
                            }
                        }
                        k++;
                    }
                }
            }
        }
        for(int i = 0;i < h;i++){
            string s = "";
            for(int j = 0;j < w;j++){
                if(!blue[i][j] || a[i][j]){
                    s += "#";
                }
                else{
                    s += ".";
                }
                if(j == w-1){
                    Console.WriteLine(s);
                }
            }
        }
        Console.WriteLine("");
        for(int i = 0;i < h;i++){
            string s = "";
            for(int j = 0;j < w;j++){
                if(blue[i][j]){
                    s += "#";
                }
                else{
                    s += ".";
                }
                if(j == w-1){
                    Console.WriteLine(s);
                }
            }
        }
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        h = int.Parse(str[0]);
        w = int.Parse(str[1]);
        a = new bool[h][];
        for(int i = 0;i < h;i++){
            string s = Console.ReadLine();
            a[i] = new bool[w];
            for(int j = 0;j < w;j++){
                if(s[j] == '#'){
                    a[i][j] = true;
                }
                else{
                    a[i][j] = false;
                }
            }
        }
    }    
}