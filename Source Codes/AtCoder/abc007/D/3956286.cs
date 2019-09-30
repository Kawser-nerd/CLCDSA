using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    static int NumConvert(char c)
    {
        if(c == '9')
            return 7;
        if(c >= '4')
            return c - '0' - 1;
        else
            return c - '0';
    }
    static int NgNumCount(char c)
    {
        if(c == '9')
            return 10 - 2;
        if(c >= '4')
            return 10 - 2;
        else
            return 10 - 20;
    }
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        string a = (long.Parse(inputs[0]) - 1).ToString();
        string b = inputs[1];
        long aCount =
            long.Parse(a)
            - a
            .Select((x, i) => a.Take(i).Contains('4') || a.Take(i).Contains('9') ? 7 : NumConvert(x))
            .Aggregate(0L, (sum, x) => sum * 8 + x);
        long bCount =
            long.Parse(b)
            - b
            .Select((x, i) => b.Take(i).Contains('4') || b.Take(i).Contains('9') ? 7 : NumConvert(x))
            .Aggregate(0L, (sum, x) => sum * 8 + x);
        //Console.WriteLine($"{a} {b}");
        //Console.WriteLine(aCount);
        //Console.WriteLine(bCount);
        Console.WriteLine(bCount - aCount);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}