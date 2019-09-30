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
        string[] inputs = Console.ReadLine().Split();
        int a = int.Parse(inputs[0]);
        int b = int.Parse(inputs[1]);
        int q = int.Parse(Console.ReadLine());
        int[] route = Console.ReadLine().Split().Select(int.Parse).ToArray();
        bool judge = 
            route.Length == route.Distinct().Count(x => x != a && x != b);


        Console.WriteLine(judge ? "YES" : "NO");

    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}