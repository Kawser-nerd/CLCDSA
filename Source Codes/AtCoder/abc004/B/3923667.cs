using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public Program()
    {
        string[][] result = 
            Enumerable.Range(0, 4)
            .Select(x => Console.ReadLine().Split()
                .Reverse().ToArray())
            .Reverse().ToArray();
        Console.WriteLine(string.Join("\n", result.Select(x => string.Join(" ", x))));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}