using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        int k = int.Parse(inputs[1]);
        double rate = 
            Console.ReadLine().Split()
            .Select(int.Parse)
            .OrderByDescending(x => x)
            .Take(k)
            .Reverse()
            .Aggregate(0.0, (sum, x) => (sum + x) / 2.0);
        Console.WriteLine(rate);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}