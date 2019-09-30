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
        int n = int.Parse(Console.ReadLine());
        Console.WriteLine(n % 12 + 1);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}