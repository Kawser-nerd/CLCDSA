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
        int[] point =
            Enumerable.Range(0, 3)
            .Select(x => 
                Console.ReadLine().Split()
                .Select(int.Parse).ToArray())
            .Select(x => x[0] * x[1] / 10)
            .ToArray();
        Console.WriteLine(point.Sum());
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}