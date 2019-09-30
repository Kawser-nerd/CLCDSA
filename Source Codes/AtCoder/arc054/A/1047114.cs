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
        double L = int.Parse(str[0]);
        double X = int.Parse(str[1]);
        double Y = int.Parse(str[2]);
        double S = int.Parse(str[3]);
        double D = int.Parse(str[4]);
        double p = (D < S ? L : 0) + D-S;
        double r = L - p;
        if(Y > X){
            sb.Append(Math.Min(p/(X+Y),r/(Y-X))+"\n");
        }
        else{
            sb.Append(p/(X+Y)+"\n");
        }
    }
}