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
        long[] A = new long[N];
        bool[] opr = new bool[N-1];
        string[] str = Console.ReadLine().Split(' ');
        for(int i=0;i<2*N-1;i++){
            if(i%2 == 0){
                A[i/2] = int.Parse(str[i]);
            }
            else{
                opr[i/2] = str[i] == "-";
            }
        }
        long[] sum = new long[N];
        sum[0] = A[0];
        for(int i=1;i<N;i++){
            sum[i] = sum[i-1] + A[i];
        }
        long max = 0;
        long minus = 0;
        for(int i=0;i<N-1;i++){
            if(!opr[i]){
                continue;
            }
            long count = 0;
            minus += A[i+1];
            i++;
            for(;i<N-1 && !opr[i];i++){
                count += A[i+1];
            }
            max = Math.Max(max,sum[N-1]-2*minus-2*count);
            i--;
        }
        max = Math.Max(max,sum[N-1]-2*minus);
        sb.Append(max+"\n");
    }
}