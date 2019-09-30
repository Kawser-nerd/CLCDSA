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
        bool[,] Map = new bool[H,W];
        for(int i=0;i<H;i++){
            string s = Console.ReadLine();
            for(int j=0;j<W;j++){
                Map[i,j] = s[j] == '#';
            }
        }
        int[,] DPR = new int[H-1,W];
        int[,] DPS = new int[H-1,W];
        for(int i=0;i<H-1;i++){
            for(int j=W-1;j>=0;j--){
                if(j == W-1){
                    if(Map[i,j] == Map[i+1,j]){
                        DPS[i,j] = 1;
                        DPR[i,j] = 0;
                    }
                    else{
                        DPS[i,j] = 0;
                        DPR[i,j] = 1;
                    }
                }
                else{
                    if(Map[i,j] == Map[i+1,j]){
                        DPS[i,j] = 1+DPS[i,j+1];
                        DPR[i,j] = 0;
                    }
                    else{
                        DPS[i,j] = 0;
                        DPR[i,j] = 1+DPR[i,j+1];
                    }
                }
            }
        }
        long count = W;
        for(int i=0;i<W;i++){
            int p = 0;
            int[] stack = new int[H+1];
            int[] point = new int[H+1];
            for(int j=0;j<H-1;j++){
                int h = Math.Max(DPS[j,i],DPR[j,i]);
                while(p > 0 && stack[p-1] > h){
                    int l = p == 1 ? 0 : point[p-2] + 1;
                    count = Math.Max(count,stack[p-1]*(j+1-l));
                    p--;
                }
                stack[p] = h;
                point[p] = j;
                p++;
            }
            while(p > 0 && stack[p-1] > 0){
                int l = p == 1 ? 0 : point[p-2] + 1;
                count = Math.Max(count,stack[p-1]*(H-l));
                p--;
            }
        }
        sb.Append(count+"\n");
    }
}