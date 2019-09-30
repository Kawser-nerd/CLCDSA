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
        var flower =
            Enumerable.Range(0, n)
            .Select(x => int.Parse(Console.ReadLine()))
            .ToArray();
        int count = flower.Length - flower.Distinct().Count();
        Console.WriteLine(count);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}