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
        int N = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] A = new int[N];
        for(int i=0;i<N;i++){
            A[i] = int.Parse(str[i]);
        }
        int[] B = new int[N];
        int rest = N;
        int p = N;
        bool b = true;
        for(int i=N-1;i>=0;i--){
            if(b){
                p -= rest;
            }
            else{
                p += rest;
            }
            b = !b;
            B[p] = A[i];
            rest--;
        }
        for(int i=0;i<N;i++){
            sb.Append(B[i]);
            if(i != N-1){
                sb.Append(" ");
            }
            else{
                sb.Append("\n");
            }
        }
    }
}