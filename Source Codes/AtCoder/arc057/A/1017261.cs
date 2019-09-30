using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    const long C = 2000000000000;
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
        long A = long.Parse(str[0]);
        int K = int.Parse(str[1]);
        long count;
        if(K == 0){
            count = C - A;
        }
        else{
            count = 0;
            while(A < C){
                count++;
                A += 1 + A*K;
            }
        }
        sb.Append(count+"\n");
    }
}