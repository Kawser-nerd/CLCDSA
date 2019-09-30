using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{   
    public void Slove()
    {
        long n = long.Parse(Console.ReadLine());
        long a = 1;
        foreach(long i in Enumerable.Range(1, (int)Math.Sqrt(n)).Reverse())
        {
            if(n % i == 0)
            {
                a = i;
                break;
            }
        }
        long b = n / a;
        int result = Math.Max(a.ToString().Length, b.ToString().Length);
        System.Console.WriteLine(result);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}