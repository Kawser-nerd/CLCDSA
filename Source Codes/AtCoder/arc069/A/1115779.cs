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
        string[] str = Console.ReadLine().Split(' ');
        long N = long.Parse(str[0]);
        long M = long.Parse(str[1]);
        long count;
        if(2*N >= M){
            count = M/2;
        }
        else{
            count = (2*N+M)/4;
        }
        sb.Append(count+"\n");
    }
}