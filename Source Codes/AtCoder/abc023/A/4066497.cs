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
        string input = Console.ReadLine();
        int a = int.Parse(input[0].ToString());
        int b = int.Parse(input[1].ToString());
        Console.WriteLine(a + b);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}