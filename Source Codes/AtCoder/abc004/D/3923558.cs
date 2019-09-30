using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Program
{
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        int rCount = int.Parse(inputs[0]);
        int gCount = int.Parse(inputs[1]);
        int bCount = int.Parse(inputs[2]);
        int min = int.MaxValue;
        int[] result = new int[4];
        int sum = rCount + bCount + gCount;
        foreach(int gStart in Enumerable.Range(-sum, sum * 2))
        //foreach(int gStart in Enumerable.Range(0, gCount))   
        {
            int rStart = -Math.Min(100 - gStart - 1, (rCount - 1) / 2);
            int bStart = -Math.Min(100 - (gCount - gStart), (bCount - 1) / 2);
            int r =  
                Enumerable.Range(rStart, rCount)
                .Select(Math.Abs).Sum();
            int b =  
                Enumerable.Range(bStart, bCount)
                .Select(Math.Abs).Sum();
            int g =  
                Enumerable.Range(-gStart, gCount)
                .Select(Math.Abs).Sum();
            if(min > r + g + b)
            {
                min = r + g + b;
                result[0] = r;
                result[1] = b;
                result[2] = g;
                result[3] = gStart;
            }
            //Console.WriteLine($"{gStart} {rStart} {bStart} {r} {g} {b}");
        }
        //Console.WriteLine(string.Join(",", result));
        Console.WriteLine(min);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}