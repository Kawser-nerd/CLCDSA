using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
class Solve{
    long[] A;
    int N;
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
        N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        A = new long[N];
        for(int i=0;i<N;i++){
            A[i] = long.Parse(str[i]);
        }
        long bf = 0;
        long bl = 510000000000000000/N;
        while(bf != bl){
            long bc = (bf+bl)/2;
            if(check(bc*N)){
                bl = bc;
            }
            else{
                bf = bc+1;
            }
        }
        if(bf == 0){
            sb.Append("0\n");
            return;
        }
        for(long bc=(bf-1000)*N+1;bc<=bf*N;bc++){
            if(bc >= 0 && check(bc)){
                sb.Append(bc+"\n");
                return;
            }
        }
    }
    bool check(long bc){
        long count = 0;
        for(int i=0;i<N;i++){
            long X = A[i]+bc;
            if(X < N){
                continue;
            }
            if((X-N+1) % (N+1) == 0){
                count += (X-N+1) / (N+1);
            }
            else{
                count += (X-N+1) / (N+1) + 1;
            }
        }
        return count <= bc;
    }
}