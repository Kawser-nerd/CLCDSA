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
        string S = Console.ReadLine();
        string T = Console.ReadLine();
        int[] SA = new int[S.Length];
        int[] SB = new int[S.Length];
        for(int i=0;i<S.Length;i++){
            if(S[i] == 'A'){
                SA[i] = i == 0 ? 1 : SA[i-1] + 1;
                SB[i] = i == 0 ? 0 : SB[i-1];
            }
            else{
                SA[i] = i == 0 ? 0 : SA[i-1];
                SB[i] = i == 0 ? 1 : SB[i-1] + 1;
            }
        }
        int[] TA = new int[T.Length];
        int[] TB = new int[T.Length];
        for(int i=0;i<T.Length;i++){
            if(T[i] == 'A'){
                TA[i] = i == 0 ? 1 : TA[i-1] + 1;
                TB[i] = i == 0 ? 0 : TB[i-1];
            }
            else{
                TA[i] = i == 0 ? 0 : TA[i-1];
                TB[i] = i == 0 ? 1 : TB[i-1] + 1;
            }
        }
        int Q = int.Parse(Console.ReadLine());
        for(int q=0;q<Q;q++){
            string[] str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0])-1;
            int b = int.Parse(str[1])-1;
            int c = int.Parse(str[2])-1;
            int d = int.Parse(str[3])-1;
            int s = SA[b] + SB[b]*2 - (a == 0 ? 0 : (SA[a-1] + SB[a-1]*2));
            int t = TA[d] + TB[d]*2 - (c == 0 ? 0 : (TA[c-1] + TB[c-1]*2));
            if(s % 3 == t % 3){
                sb.Append("YES\n");
            }
            else{
                sb.Append("NO\n");
            }
        }
    }
}