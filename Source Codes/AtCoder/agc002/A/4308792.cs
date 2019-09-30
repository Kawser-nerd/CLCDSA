using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{    
    
    public void slove()
    {
        var inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int a = inputs[0];
        int b = inputs[1];
        if(a <= 0 && 0 <= b)
            System.Console.WriteLine("Zero");
        else if(0 < a)
            System.Console.WriteLine("Positive");
        else if((Math.Min(b, -1) - a & 1) == 0)
            System.Console.WriteLine("Negative");
        else
            System.Console.WriteLine("Positive");

    }
    
    static void Main(string[] args)
    {
        new Program().slove();
    }
}