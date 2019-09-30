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
        int H = int.Parse(str[0]);
        int W = int.Parse(str[1]);
        long K = long.Parse(str[2]);
        bool[,] b = new bool[H,W];
        long c = 0;
        long e = 0;
        for(int i=0;i<H;i++){
            string s = Console.ReadLine();
            for(int j=0;j<W;j++){
                b[i,j] = s[j] == '#';
                if(b[i,j]){
                    c++;
                }
            }
        }
        bool b1 = false;
        for(int i=0;i<W;i++){
            if(b[0,i] && b[H-1,i]){
                b1 = true;
                e++;
            }
        }
        bool b2 = false;
        for(int i=0;i<H;i++){
            if(b[i,0] && b[i,W-1]){
                b2 = true;
                e++;
            }
        }
        if(b1 && b2){
            sb.Append("1\n");
        }
        else{
            long d = 0;
            if(b1){
                for(int i=0;i<H-1;i++){
                    for(int j=0;j<W;j++){
                        if(b[i,j] && b[i+1,j]){
                            d++;
                        }
                    }
                }
            }
            if(b2){
                for(int i=0;i<H;i++){
                    for(int j=0;j<W-1;j++){
                        if(b[i,j] && b[i,j+1]){
                            d++;
                        }
                    }
                }
            }
            long[,] M = new long[2,2];
            M[0,0] = c;
            M[0,1] = Define.mod-d;
            M[1,1] = e;
            long[,] ans = Pow(M,K-1);
            sb.Append((ans[0,0]+ans[0,1])%Define.mod+"\n");
        }
    }
    long[,] Mul(long[,] a,long[,] b){
        long[,] c = new long[a.GetLength(0),b.GetLength(1)];
        for(int i=0;i<a.GetLength(0);i++){
            for(int j=0;j<b.GetLength(1);j++){
                long d = 0;
                for(int k=0;k<a.GetLength(1);k++){
                    d = (d+a[i,k]*b[k,j])%Define.mod;
                }
                c[i,j] = d;
            }
        }
        return c;
    }
    long[,] Pow(long[,] a,long e){
        if(e == 0){
            long[,] c = new long[a.GetLength(0),a.GetLength(0)];
            for(int i=0;i<a.GetLength(0);i++){
                for(int j=0;j<a.GetLength(0);j++){
                    c[i,j] = i == j ? 1 : 0;
                }
            }
            return c;
        }
        else if(e%2 == 0){
            long[,] b = Mul(a,a);
            return Pow(b,e/2);
        }
        else{
            return Mul(Pow(a,e-1),a);
        }
    }
}
public static class Define{
    public const long mod = 1000000007;
}