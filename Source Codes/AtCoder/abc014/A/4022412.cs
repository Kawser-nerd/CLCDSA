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
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int mod = a % b;
        if(mod == 0)
            Console.WriteLine(0);
        else
            Console.WriteLine(b - mod);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}