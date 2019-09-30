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
        int X1 = int.Parse(str[0]);
        int X2 = int.Parse(str[1]);
        int X3 = int.Parse(str[2]);
        int X4 = int.Parse(str[3]);
        int X5 = int.Parse(str[4]);
        int X6 = int.Parse(str[5]);
        str = Console.ReadLine().Split(' ');
        int Y1 = int.Parse(str[0]);
        int Y2 = int.Parse(str[1]);
        int Y3 = int.Parse(str[2]);
        int Y4 = int.Parse(str[3]);
        int Y5 = int.Parse(str[4]);
        int Y6 = int.Parse(str[5]);
        Fact F = new Fact(2000000);
        long count = 0;
        {
            int YLB = Y3-Y1;
            int YLS = Y3-Y2-1;
            int YRB = Y6-Y3+1;
            int YRS = Y5-Y3;
            for(int x=X3;x<=X4;x++){
                int XLB = x-X1+1;
                int XLS = x-X2;
                int XRB = X6-x+1;
                int XRS = X5-x;
                long c = (2*Define.mod + F.GetConv(XLB+YLB,XLB) + F.GetConv(XLS+YLS,XLS) - F.GetConv(XLB+YLS,XLB) - F.GetConv(XLS+YLB,XLS)) % Define.mod;
                long d = (2*Define.mod + F.GetConv(XRB+YRB,XRB) + F.GetConv(XRS+YRS,XRS) - F.GetConv(XRB+YRS,XRB) - F.GetConv(XRS+YRB,XRS)) % Define.mod;
                count = (count + c * d % Define.mod * (Define.mod - x - Y3)) % Define.mod; 
            }
        }
        {
            int YLB = Y4-Y1+1;
            int YLS = Y4-Y2;
            int YRB = Y6-Y4;
            int YRS = Y5-Y4-1;
            for(int x=X3;x<=X4;x++){
                int XLB = x-X1+1;
                int XLS = x-X2;
                int XRB = X6-x+1;
                int XRS = X5-x;
                long c = (2*Define.mod + F.GetConv(XLB+YLB,XLB) + F.GetConv(XLS+YLS,XLS) - F.GetConv(XLB+YLS,XLB) - F.GetConv(XLS+YLB,XLS)) % Define.mod;
                long d = (2*Define.mod + F.GetConv(XRB+YRB,XRB) + F.GetConv(XRS+YRS,XRS) - F.GetConv(XRB+YRS,XRB) - F.GetConv(XRS+YRB,XRS)) % Define.mod;
                count = (count + c * d % Define.mod * (x + Y4 + 1)) % Define.mod; 
            }
        }
        {
            int XLB = X3-X1;
            int XLS = X3-X2-1;
            int XRB = X6-X3+1;
            int XRS = X5-X3;
            for(int y=Y3;y<=Y4;y++){
                int YLB = y-Y1+1;
                int YLS = y-Y2;
                int YRB = Y6-y+1;
                int YRS = Y5-y;
                long c = (2*Define.mod + F.GetConv(XLB+YLB,XLB) + F.GetConv(XLS+YLS,XLS) - F.GetConv(XLB+YLS,XLB) - F.GetConv(XLS+YLB,XLS)) % Define.mod;
                long d = (2*Define.mod + F.GetConv(XRB+YRB,XRB) + F.GetConv(XRS+YRS,XRS) - F.GetConv(XRB+YRS,XRB) - F.GetConv(XRS+YRB,XRS)) % Define.mod;
                count = (count + c * d % Define.mod * (Define.mod - X3 - y)) % Define.mod; 
            }
        }
        {
            int XLB = X4-X1+1;
            int XLS = X4-X2;
            int XRB = X6-X4;
            int XRS = X5-X4-1;
            for(int y=Y3;y<=Y4;y++){
                int YLB = y-Y1+1;
                int YLS = y-Y2;
                int YRB = Y6-y+1;
                int YRS = Y5-y;
                long c = (2*Define.mod + F.GetConv(XLB+YLB,XLB) + F.GetConv(XLS+YLS,XLS) - F.GetConv(XLB+YLS,XLB) - F.GetConv(XLS+YLB,XLS)) % Define.mod;
                long d = (2*Define.mod + F.GetConv(XRB+YRB,XRB) + F.GetConv(XRS+YRS,XRS) - F.GetConv(XRB+YRS,XRB) - F.GetConv(XRS+YRB,XRS)) % Define.mod;
                count = (count + c * d % Define.mod * (X4 + y + 1)) % Define.mod; 
            }
        }
        sb.Append(count+"\n");
    }
}
class Fact{
    public long[] f;
    public long[] rf;
    public Fact(int N){
        f = new long[N+1];
        rf = new long[N+1];
        for(int i=0;i<N+1;i++){
            if(i == 0){
                f[i] = 1;
            }
            else{
                f[i] = (f[i-1]*i)%Define.mod;
            }
        }
        for(int i=N;i>=0;i--){
            if(i == N){
                rf[i] = pow(f[N],Define.mod-2);
            }
            else{
                rf[i] = rf[i+1]*(i+1)%Define.mod;
            }
        }
    }
    public long pow(long N,long K){
        if(K == 0){
            return 1;
        }
        else if(K % 2 == 0){
            long t = pow(N,K/2);
            return t*t%Define.mod;
        }
        else{
            return N*pow(N,K-1)%Define.mod;
        }
    }
    public long GetFact(int N){
        return f[N];
    }
    public long GetConv(int N,int R){
        return ((f[N]*rf[R])%Define.mod*rf[N-R])%Define.mod;
    }
}
public static class Define{
    public const long mod = 1000000007;
}