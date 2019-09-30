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
        long T = int.Parse(str[2]);
        long count = 0;
        long[] P = new long[N];
        for(int i=0;i<N;i++){
            str = Console.ReadLine().Split(' ');
            long X = int.Parse(str[0]);
            if(int.Parse(str[1]) == 1){
                P[i] = (X+T)%L;
                count += (X+T)/L;
            }
            else{
                P[i] = (X+T*L-T)%L;
                if(X < T){
                    count -= (T-X-1)/L+1;
                }
            }
        }
        Array.Sort(P);
        if(count >= 0){
            count %= N;
        }
        else{
            count = -count;
            count %= N;
            count = N-count;
            count %= N;
        }
        int c = (int)count;
        for(int i=c;i<N;i++){
            sb.Append(P[i]+"\n");
        }
        for(int i=0;i<c;i++){
            sb.Append(P[i]+"\n");
        }
    }
}