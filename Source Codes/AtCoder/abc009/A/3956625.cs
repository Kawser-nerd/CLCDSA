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
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n / 2 + (n & 1));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}