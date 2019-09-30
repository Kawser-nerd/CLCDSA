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
        Array.Sort(A);
        int count = 0;
        for(int i=1;i<N;i++){
            if(A[i] == A[i-1]){
                count++;
            }
        }
        count = N - count;
        if(count % 2 == 0){
            count--;
        }
        sb.Append(count+"\n");
    }
}