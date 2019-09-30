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
        long I = int.Parse(str[0]);
        long O = int.Parse(str[1]);
        long J = int.Parse(str[3]);
        long L = int.Parse(str[4]);
        long count = I/2*2 + O + J/2*2 + L/2*2;
        if(I >= 1 && J >= 1 && L >= 1){
            count = Math.Max(count,3+(I-1)/2*2 + O + (J-1)/2*2 + (L-1)/2*2);
        } 
        sb.Append(count+"\n");
    }
}