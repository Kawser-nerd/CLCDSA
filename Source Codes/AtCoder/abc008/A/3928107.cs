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
        string[] inputs = Console.ReadLine().Split();
        Console.WriteLine(int.Parse(inputs[1]) - int.Parse(inputs[0]) + 1);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}