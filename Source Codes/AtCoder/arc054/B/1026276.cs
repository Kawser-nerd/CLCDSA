using System;
using System.Text;
using System.Collections.Generic;
class Solve{
    double P;
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
        P = double.Parse(Console.ReadLine());
        double f = 0;
        double l = P;
        while(l - f >= 0.000000001){
            double c1 = (2*f+l)/3;
            double c2 = (f+2*l)/3;
            if(check(c1) >= check(c2)){
                f = c1;
            }
            if(check(c1) <= check(c2)){
                l = c2;
            }
        }
        sb.Append(check((l+f)/2)+"\n");
    }
    double check(double d){
        return d + P/Math.Pow(2,d/1.5);
    }
}