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
        int n = int.Parse(Console.ReadLine());
        int pointA = 1;
        int pointB = 2;
        Console.WriteLine($"? {pointA} {pointB}");
        int max = int.Parse(Console.ReadLine());
        foreach(int next in Enumerable.Range(1, n).Skip(2))
        {
            Console.WriteLine($"? {pointA} {next}");
            int distA = int.Parse(Console.ReadLine());
            Console.WriteLine($"? {pointB} {next}");
            int distB = int.Parse(Console.ReadLine());
            if(distA > max && distA > distB)
            {
                max = distA;
                pointB = next;
            }
            else if(distB > max)
            {
                max = distB;
                pointA = next;
            }
        }

        Console.WriteLine($"! {max}");
    }
    static void Main(string[] args)
    {
        var p = new Program();
        p.Slove();
    }
}