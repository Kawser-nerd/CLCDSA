using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public void Slove()
    {
        char input = Console.ReadLine()[0];
        Console.WriteLine(input - 'A' + 1);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}