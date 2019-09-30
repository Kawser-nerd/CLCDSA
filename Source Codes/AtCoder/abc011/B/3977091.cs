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
        string output = string.Join("", input
            .Select((x, i) => i == 0 ? x.ToString().ToUpper() : x.ToString().ToLower())
            );
        Console.WriteLine(output);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}