using System;
using System.Text;
using System.Collections.Generic;
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
        int H,W;
        H = int.Parse(str[0]);
        W = int.Parse(str[1]);
        long[,] a = new long[H,W];
        for(int i=0;i<H;i++){
            str = Console.ReadLine().Split(' ');
            for(int j=0;j<W;j++){
                a[i,j] = long.Parse(str[j]);
            }
        }
        int[] b = new int[H*W];
        for(int i=0;i<H*W;i++){
            b[i] = i;
        }
        Array.Sort(b,(x,y) => a[x/W,x%W] < a[y/W,y%W] ? 1 : (a[x/W,x%W] == a[y/W,y%W] ? 0 : -1));
        long[,] c = new long[H,W];
        long count = 0;
        for(int i=0;i<H*W;i++){
            int x = b[i]/W;
            int y = b[i]%W;
            long cost = 1;
            if(x != 0 && a[x,y] < a[x-1,y]){
                cost = (cost + c[x-1,y]) % Define.mod;
            }
            if(x != H-1 && a[x,y] < a[x+1,y]){
                cost = (cost + c[x+1,y]) % Define.mod;
            }
            if(y != 0 && a[x,y] < a[x,y-1]){
                cost = (cost + c[x,y-1]) % Define.mod;
            }
            if(y != W-1 && a[x,y] < a[x,y+1]){
                cost = (cost + c[x,y+1]) % Define.mod;
            }
            c[x,y] = cost;
            count = (count + cost) % Define.mod;
        }
        sb.Append(count+"\n");
    }
}
public static class Define{
    public const long mod = 1000000007;
}