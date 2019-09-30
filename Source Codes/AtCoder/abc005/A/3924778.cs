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
        int x = int.Parse(inputs[0]);
        int y = int.Parse(inputs[1]);
        Console.WriteLine(y / x);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}