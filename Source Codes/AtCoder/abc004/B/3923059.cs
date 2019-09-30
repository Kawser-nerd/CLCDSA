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
        string[][] inputs = 
            Enumerable.Range(0, 4)
            .Select(x => Console.ReadLine().Split())
            .ToArray();
        string[] result =
            Enumerable.Range(0, 4)
            .Select(y => string.Join(" ",
                Enumerable.Range(0, 4)
                .Select(x => inputs[3 - y][3 - x])
            ))
            .ToArray();
        Console.WriteLine(string.Join("\n", result));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}