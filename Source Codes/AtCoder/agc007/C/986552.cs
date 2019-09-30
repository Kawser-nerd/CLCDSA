using System;
using System.Collections.Generic;
class Solve{
    int N;
    int D;
    int X;
    public Solve(){}
    public static int Main(){
        new Solve().Calc();
        return 0;
    }
    void Calc(){
        getinput();
        double sum = 0;
        double l = D;
        double r = D+(2*N-1)*X;
        double x = X;
        int n = N;
        while(n > 0){
            sum += (l+r)/2;
            l += (2*l+5*x)/(2*n);
            r += (2*r-5*x)/(2*n);
            n--;
            x = (r-l)/(2*n);
        }
        Console.WriteLine(sum);
    }
    void getinput(){
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        D = int.Parse(str[1]);
        X = int.Parse(str[2]);
    }    
}