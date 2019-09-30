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
        int mid = inputs.Select(int.Parse).OrderBy(x => x).ToArray()[1];
        Console.WriteLine(mid);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}