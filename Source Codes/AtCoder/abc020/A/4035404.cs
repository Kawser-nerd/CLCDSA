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
        string[] ans = new string[]
        {
            "ABC",
            "chokudai",
        };
        int n = int.Parse(Console.ReadLine()) - 1;
        Console.WriteLine(ans[n]);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}