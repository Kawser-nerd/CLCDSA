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
        long L = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        DPfunction D = new DPfunction(L,N,int.Parse(str[0]));
        for(int i=1;i<N;i++){
            sb.Append(D.Get()/L+"\n");
            str = Console.ReadLine().Split(' ');
            D.Set(int.Parse(str[0]),int.Parse(str[1]));
        }
        sb.Append(D.Get()/L+"\n");
    }
    class DPfunction{
        double L;
        double TS;
        double VS;
        int p,q;
        double[] T;
        double[] V;
        public DPfunction(long L0,int N,long t){
            L = L0;
            TS = 0;
            VS = 0;
            T = new double[N+1];
            V = new double[N+1];
            p = N-1;
            q = N;
            T[N] = t*L;
            V[N] = L;
        }
        public double Get(){
            return T[q]+TS;
        }
        public void Set(long t,long v){
            while(V[q-1] + VS + v > L){
                q--;
            }
            T[q] = ((V[q] - L + VS + v)*T[q-1] + (L - VS - v - V[q-1])*T[q])/(V[q] - V[q-1]);
            V[q] = L - VS - v;
            TS += t*v;
            VS += v;
            p--;
            while(p+1 < q){
                if(((V[p+2] - V[p+1])*(-TS) + (V[p+1] + VS)*(T[p+2]))/(V[p+2] + VS) > T[p+1]){
                    p++;
                }
                else{
                    break;
                }
            }
            T[p] = -TS;
            V[p] = -VS;
        }
    }
}