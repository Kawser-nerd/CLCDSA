using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main(string[] args)
    {
        var XY = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

        Console.WriteLine(Math.Abs(XY[0] - XY[1]) <= 1 ? "Brown" : "Alice");
    }
}