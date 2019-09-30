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
        string a = Console.ReadLine();
        string b = Console.ReadLine();
        Console.WriteLine(a.Length > b.Length ? a : b);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}