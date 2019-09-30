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
        string n = Console.ReadLine();
        bool result = n.Contains("3") || int.Parse(n) % 3 == 0;
        Console.WriteLine(result ? "YES" : "NO");
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}