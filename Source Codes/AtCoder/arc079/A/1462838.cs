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
        int M = int.Parse(str[1]);
        bool[] b = new bool[N];
        bool[] c = new bool[N];
        for(int i=0;i<M;i++){
            str = Console.ReadLine().Split(' ');
            int a = int.Parse(str[0]) - 1;
            int d = int.Parse(str[1]) - 1;
            if(a == 0){
                b[d] = true;
            }
            if(d == N-1){
                c[a] = true;
            }
        }
        bool ans = false;
        for(int i=1;i<N-1;i++){
            ans |= b[i] && c[i];
        }
        if(ans){
            sb.Append("POSSIBLE\n");
        }
        else{
            sb.Append("IMPOSSIBLE\n");
        }
    }
}