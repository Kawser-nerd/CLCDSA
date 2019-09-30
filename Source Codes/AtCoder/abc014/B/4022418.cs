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
        int items = int.Parse(inputs[1]);
        int[] price = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int sum = price.Where((x, i) => ((items >> i) & 1) == 1).Sum();
        Console.WriteLine(sum);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}