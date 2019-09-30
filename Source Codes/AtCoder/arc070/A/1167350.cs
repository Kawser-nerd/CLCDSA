using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

class Program
{
    static void Main(string[] args)
    {
        long X = long.Parse(Console.ReadLine());
        double t = (Math.Sqrt(X * 8 + 1) - 1) / 2;
        Console.WriteLine((int)Math.Ceiling(t));
    }
}