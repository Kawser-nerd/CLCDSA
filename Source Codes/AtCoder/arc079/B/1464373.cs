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
        long K = long.Parse(Console.ReadLine());
        sb.Append("50\n");
        long[] A = new long[50];
        for(int i=0;i<50;i++){
            A[i] = K/50+49;
        }
        for(int i=0;i<K%50;i++){
            A[i] += 51; 
        }
        for(int i=0;i<50;i++){
            A[i] -= K%50;
        }
        for(int i=0;i<50;i++){
            sb.Append(A[i]);
            if(i == 49){
                sb.Append("\n");
            }
            else{
                sb.Append(" ");
            }
        }
    }
}