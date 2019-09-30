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
        int[] points =
            Enumerable.Range(0, 3)
            .Select(x => int.Parse(Console.ReadLine()))
            .ToArray();
        int[] rank =
            Enumerable.Range(1, 3)
            .OrderByDescending(x => points[x - 1])
            .ToArray();      
        rank =
            Enumerable.Range(1, 3)
            .OrderBy(x => rank[x - 1])
            .ToArray();
        Console.WriteLine(string.Join("\n", rank));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}