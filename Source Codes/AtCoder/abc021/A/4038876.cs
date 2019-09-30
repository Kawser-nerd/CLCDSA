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
        int[] result =
            Enumerable.Range(0, 4)
            .Where(x => (n >> x & 1) == 1)
            .Select(x => 1 << x)
            .ToArray();
        Console.WriteLine(result.Length);
        Console.WriteLine(string.Join("\n", result));
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}