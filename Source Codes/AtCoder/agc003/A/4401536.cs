using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{   
    
    public void Slove()
    {
        var plans = Console.ReadLine().Distinct().ToArray();
        bool judge = 
            plans.Contains('N') == plans.Contains('S') &&
            plans.Contains('W') == plans.Contains('E');
        System.Console.WriteLine(judge ? "Yes" : "No");
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}