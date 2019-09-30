using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Numerics;

public class Program
{
    public static void Main(string[] args)
    {
        var line = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderByDescending(x => x).ToArray();

        Console.WriteLine((line[0] * 10 + line[1]) + line[2]);
        Console.ReadLine();
    }
}