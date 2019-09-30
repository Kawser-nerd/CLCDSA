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
        int n = int.Parse(inputs[0]);
        int h = int.Parse(inputs[1]);
        inputs = Console.ReadLine().Split();
        int a = int.Parse(inputs[0]);
        int b = int.Parse(inputs[1]);
        int c = int.Parse(inputs[2]);
        int d = int.Parse(inputs[3]);
        int e = int.Parse(inputs[4]);

        long cost = c * (long)n;
        long satiety = h + d * (long)n;
        long min = cost;
        int frugality = n;
            //Console.WriteLine($"{cost} {satiety}");
        foreach(int i in Enumerable.Range(0, n))
        {
            satiety -= d + e;
            cost    -= c;
            frugality--;
            while(satiety <= 0)
            {
                satiety += b - d;
                cost += a - c;
                frugality--;
            }
            if(frugality < 0)
                break;
            //Console.WriteLine($"{cost} {satiety}");
            min = Math.Min(min, cost);
        }
        Console.WriteLine(min);
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}