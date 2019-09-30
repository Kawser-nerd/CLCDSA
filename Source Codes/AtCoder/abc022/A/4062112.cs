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
        string[] inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        int s = int.Parse(inputs[1]);
        int t = int.Parse(inputs[2]);
        int weight = 0;
        int count =
            Enumerable.Range(0, n)
            .Select(x => int.Parse(Console.ReadLine()))
            .Select(x => weight += x)
            .Count(x => s <= x && x <= t);
        Console.WriteLine(count);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}