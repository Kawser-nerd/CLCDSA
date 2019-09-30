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
        string[] inputs = Console.ReadLine().Split();
        int month = int.Parse(inputs[0]);
        int day = int.Parse(inputs[1]);
        Console.WriteLine(month % day == 0 ? "YES" : "NO");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}