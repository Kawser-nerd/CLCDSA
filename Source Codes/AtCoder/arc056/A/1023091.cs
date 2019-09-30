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
        long A = long.Parse(str[0]);
        long B = long.Parse(str[1]);
        long K = long.Parse(str[2]);
        long L = long.Parse(str[3]);
        sb.Append((K/L*B+(K%L*A > B ? B : K%L*A))+"\n");
    }
}