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
        int n = int.Parse(Console.ReadLine());
        var stars =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split())
            .Select(x => new {X = long.Parse(x[0]), Y = long.Parse(x[1]) })
            .ToArray();
        var center =
            new {X = stars.Average(x => x.X), Y = stars.Average(x => x.Y)};
            
        double maxDisA =
            stars
            .Max(x => Math.Sqrt(
                Math.Pow(x.X - center.X, 2) + Math.Pow(x.Y - center.Y, 2)));
        stars =
            Enumerable.Range(0, n)
            .Select(x => Console.ReadLine().Split())
            .Select(x => new {X = long.Parse(x[0]), Y = long.Parse(x[1]) }).ToArray();
        center =
            new {X = stars.Average(x => x.X), Y = stars.Average(x => x.Y)};
            
        double maxDisB =
            stars
            .Max(x => Math.Sqrt(
                Math.Pow(x.X - center.X, 2) + Math.Pow(x.Y - center.Y, 2)));
        Console.WriteLine(maxDisB / maxDisA);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}