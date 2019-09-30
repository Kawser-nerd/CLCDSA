using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int result = 
            new int[]
            {
                Math.Abs(a - b),
                10 + a - b,
                10 + b - a,
            }
            .Min();
        Console.WriteLine(result);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}