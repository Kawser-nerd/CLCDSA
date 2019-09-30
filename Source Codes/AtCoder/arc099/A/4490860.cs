using System;
using System.Collections.Generic;
using System.Linq;
//using System.Numerics;
class Program
{       
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int k = int.Parse(inputs[1]);
        int indexOfOne = Array.IndexOf(Console.ReadLine().Split(), "1");
        int count = (indexOfOne - 1) / (k - 1);
        count += (n - (count * (k - 1) + k) + (k - 2)) / (k - 1) + 1;
        System.Console.WriteLine(count);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}