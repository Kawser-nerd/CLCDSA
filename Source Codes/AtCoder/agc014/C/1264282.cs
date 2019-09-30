using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    public Solve(){}
    StringBuilder sb;
    public static int Main(){
        new Solve().Run();
        return 0;
    }
    void Run(){
        sb = new StringBuilder();
        Calc();
        Console.Write(sb.ToString());
    }
    void Calc(){
        string[] str = Console.ReadLine().Split(' ');
        int H = int.Parse(str[0]);
        int W = int.Parse(str[1]);
        int K = int.Parse(str[2]);
        bool[,] b = new bool[H,W];
        int Si = 0;
        int Sj = 0;
        for(int i=0;i<H;i++){
            string s = Console.ReadLine();
            for(int j=0;j<W;j++){
                b[i,j] = s[j] != '#';
                if(s[j] == 'S'){
                    Si = i;
                    Sj = j;
                }
            }
        }
        if(Si == 0 || Si == H-1 || Sj == 0 || Sj == W-1){
            sb.Append("0\n");
            return;
        }
        int[,] DP = new int[H,W];
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                DP[i,j] = -1;
            }
        }
        {
            int[] P = new int[H*W];
            int p = 0;
            int q = 1;
            P[0] = Si*W+Sj;
            DP[Si,Sj] = 0;
            while(p != q){
                int x = P[p] / W;
                int y = P[p] % W;
                p++;
                {
                    int i = -1;
                    int j = 0;
                    if(x+i >= 0 && x+i < H && y+j >= 0 && y+j < W){
                        if(DP[x+i,y+j] == -1 && b[x+i,y+j]){
                            DP[x+i,y+j] = DP[x,y] + 1;
                            if(DP[x+i,y+j] != K){
                                P[q] = (x+i)*W + (y+j);
                                q++;
                            }
                        }
                    }
                    i = 1;
                    j = 0;
                    if(x+i >= 0 && x+i < H && y+j >= 0 && y+j < W){
                        if(DP[x+i,y+j] == -1 && b[x+i,y+j]){
                            DP[x+i,y+j] = DP[x,y] + 1;
                            if(DP[x+i,y+j] != K){
                                P[q] = (x+i)*W + (y+j);
                                q++;
                            }
                        }
                    }
                    i = 0;
                    j = -1;
                    if(x+i >= 0 && x+i < H && y+j >= 0 && y+j < W){
                        if(DP[x+i,y+j] == -1 && b[x+i,y+j]){
                            DP[x+i,y+j] = DP[x,y] + 1;
                            if(DP[x+i,y+j] != K){
                                P[q] = (x+i)*W + (y+j);
                                q++;
                            }
                        }
                    }
                    i = 0;
                    j = 1;
                    if(x+i >= 0 && x+i < H && y+j >= 0 && y+j < W){
                        if(DP[x+i,y+j] == -1 && b[x+i,y+j]){
                            DP[x+i,y+j] = DP[x,y] + 1;
                            if(DP[x+i,y+j] != K){
                                P[q] = (x+i)*W + (y+j);
                                q++;
                            }
                        }
                    }
                }
            }
        }
        int count = 100000;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(DP[i,j] != -1){
                    count = Math.Min(H-1-i,count);
                    count = Math.Min(i,count);
                    count = Math.Min(W-1-j,count);
                    count = Math.Min(j,count);
                }
            }
        }
        count = (count + K - 1) / K;
        count++;
        sb.Append(count+"\n");
    }
}