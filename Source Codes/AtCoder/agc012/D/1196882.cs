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
        int N = int.Parse(str[0]);
        long X = int.Parse(str[1]);
        long Y = int.Parse(str[2]);
        long[][] Color = new long[N][];
        {
            List<long>[] C = new List<long>[N];
            for(int i=0;i<N;i++){
                C[i] = new List<long>();
            }
            for(int i=0;i<N;i++){
                str = Console.ReadLine().Split(' ');
                C[int.Parse(str[0])-1].Add(long.Parse(str[1]));
            }
            for(int i=0;i<N;i++){
                Color[i] = C[i].ToArray();
                Array.Sort(Color[i]);
            }
        }
        long min = 1000000000;
        int minc = -1;
        long min2 = 1000000000;
        for(int i=0;i<N;i++){
            if(Color[i].Length > 0 && min > Color[i][0]){
                min = Color[i][0];
                minc = i;
            }
        }
        for(int i=0;i<N;i++){
            if(i != minc && Color[i].Length > 0 && min2 > Color[i][0]){
                min2 = Color[i][0];
            }
        }
        int count = 0;
        int[] num = new int[N];
        for(int i=0;i<N;i++){
            long M;
            if(i != minc){
                if(Color[i].Length == 0 || min + Color[i][0] > Y){
                    continue;
                }
                M = Math.Max(Y-min,X-Color[i][0]);
            }
            else{
                if(Color[i].Length == 0 || min2 + Color[i][0] > Y){
                    continue;
                }
                M = Math.Max(Y-min2,X-Color[i][0]);
            }
            int c = 0;
            for(int p=0;p<Color[i].Length;p++){
                if(Color[i][p] <= M){
                    c++;
                }
            }
            num[i] = c;
            count += c;
        }
        Fact F = new Fact(count);
        long ans = 1;
        for(int i=0;i<N;i++){
            ans = ans * F.GetConv(count,num[i]) % Define.mod;
            count -= num[i];
        }
        sb.Append(ans+"\n");
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