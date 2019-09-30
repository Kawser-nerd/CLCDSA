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
        string[] inputs =
            Console.ReadLine().Split();
        string join = string.Join("", inputs);
        int n = int.Parse(join) * 2;
        Console.WriteLine(n);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}