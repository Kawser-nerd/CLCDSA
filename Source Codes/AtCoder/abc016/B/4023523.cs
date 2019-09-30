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
        int a = int.Parse(inputs[0]);
        int b = int.Parse(inputs[1]);
        int c = int.Parse(inputs[2]);
        bool[] judge = new bool[]
        {
            a + b == c,
            a - b == c,
        };
        if(judge.All(x => x))
            Console.WriteLine("?");
        else if(judge[0])
            Console.WriteLine("+");
        else if(judge[1])
            Console.WriteLine("-");
        else
            Console.WriteLine("!");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}