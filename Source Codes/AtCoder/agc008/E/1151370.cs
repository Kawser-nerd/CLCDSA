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
        int N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] A = new int[N];
        List<int>[] R = new List<int>[N];
        for(int i=0;i<N;i++){
            R[i] = new List<int>();
        }
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i])-1;
            R[int.Parse(str[i])-1].Add(i);
        }
        int[] round = new int[N+1];
        long count = 1;
        bool[] b = new bool[N];
        for(int i=0;i<N;i++){
            if(count == 0){
                break;
            }
            if(!b[i]){
                int c = 1;
                int t = -1;
                int ne = A[i];
                if(R[i].Count > 2){
                    count = 0;
                }
                if(R[i].Count == 2){
                    t = i;
                }
                while(ne != i && t == -1){
                    c++;
                    b[ne] = true;
                    if(R[ne].Count > 2){
                        count = 0;
                    }
                    if(R[ne].Count == 2){
                        t = ne;
                    }
                    ne = A[ne];
                }
                if(count == 0){
                    break;
                }
                if(t == -1){
                    round[c]++;
                }
                else{
                    bool o = true;
                    for(int j=t;j != t || o;j = A[j]){
                        o = false;
                        b[j] = true;
                        if(R[j].Count == 2){
                            int p = R[j][0];
                            int q = R[j][1];
                            while(R[p].Count != 0 && R[q].Count != 0){
                                if(R[p].Count >= 2 || R[q].Count >= 2){
                                    count = 0;
                                    break;
                                }
                                b[p] = true;
                                p = R[p][0];
                                b[q] = true;
                                q = R[q][0];
                            }
                            b[p] = true;
                            b[q] = true;
                            if(R[p].Count > 2 || R[q].Count > 2){
                                count = 0;
                            }
                            if(count == 0){
                                break;
                            }
                            if(R[p].Count == 1 || R[q].Count == 1){
                                count = count*2%Define.mod;
                            }
                        }
                        else if(R[j].Count > 2){
                            count = 0;
                            break;
                        }
                    }
                }
            }
        }
        long[] po = new long[N+1];
        po[0] = 1; 
        for(int i=1;i<=N;i++){
            po[i] = po[i-1]*2%Define.mod;
        }
        Fact f = new Fact(N);
        for(int i=0;i<=N;i++){
            long c = 0;
            int n = round[i];
            long c2 = 1;
            for(int j=0;2*j<=n;j++){
                c = (c + c2*f.rf[j]%Define.mod*(i%2 == 0 || i == 1 ? 1 : po[n-2*j]))%Define.mod;
                c2 = c2*((long)(n-2*j)*(long)(n-2*j-1)/2%Define.mod)%Define.mod*i%Define.mod;
            }
            count = count*c%Define.mod;
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