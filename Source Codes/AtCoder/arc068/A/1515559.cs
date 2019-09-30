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
        long N = long.Parse(Console.ReadLine());
        long count;
        if(N % 11 == 0){
            count = N / 11 * 2;
        }
        else if(N % 11 <= 6){
            count = N / 11 * 2 + 1;
        }
        else{
            count = N / 11 * 2 + 2;
        }
        sb.Append(count+"\n");
    }
}