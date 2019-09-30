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
        int sX = int.Parse(inputs[0]);
        int sY = int.Parse(inputs[1]);
        int eX = int.Parse(inputs[2]);
        int eY = int.Parse(inputs[3]);
        int time = int.Parse(inputs[4]);
        int velocity = int.Parse(inputs[5]);
        int distance = time * velocity;
        int n = int.Parse(Console.ReadLine());
        bool judge =
            Enumerable.Range(0, n)
            .Select(x => 
                Console.ReadLine().Split()
                .Select(int.Parse)
                .ToArray()
            )
            .Select(x => 
                Math.Sqrt(Math.Pow(x[0] - sX, 2) + Math.Pow(x[1] - sY, 2))
                + Math.Sqrt(Math.Pow(x[0] - eX, 2) + Math.Pow(x[1] - eY, 2)))
            .Any(x => 
                x <= distance);
        Console.WriteLine(judge ? "YES" : "NO");
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}