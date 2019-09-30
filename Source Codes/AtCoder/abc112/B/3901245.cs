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
        int n = inputs[0];
        int limitTime = inputs[1];
        int minCost = int.MaxValue;
        foreach(int i in Enumerable.Range(0, n))
        {
            inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int cost = inputs[0];
            int time = inputs[1];
            if(time <= limitTime && 
                minCost > cost)
                minCost = cost;
        }
        Console.WriteLine(minCost == int.MaxValue ? "TLE" : minCost.ToString());

    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}