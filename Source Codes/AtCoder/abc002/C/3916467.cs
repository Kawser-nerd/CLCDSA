using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class Program
{     
    public Program()
    {
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        inputs = inputs.Select((x, i) => x - inputs[i & 1]).ToArray();
        double a = Math.Sqrt(Math.Pow(inputs[2] - inputs[4], 2) + Math.Pow(inputs[3] - inputs[5], 2));
        double b = Math.Sqrt(Math.Pow(inputs[2], 2) + Math.Pow(inputs[3], 2));
        double c = Math.Sqrt(Math.Pow(inputs[4], 2) + Math.Pow(inputs[5], 2));
        double s = (a + b + c) / 2;
        Console.WriteLine(Math.Sqrt(s * (s - a) * (s - b) * (s - c)));
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}