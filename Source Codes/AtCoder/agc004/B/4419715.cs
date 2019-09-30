using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
class Program
{       
    public void Slove()
    {
        var inputs = Console.ReadLine().Split();
        int n = int.Parse(inputs[0]);
        long shiftCost = long.Parse(inputs[1]);
        long[] costs = Console.ReadLine().Split().Select(long.Parse).ToArray();
        long minSum = costs.Sum();
        foreach(int i in Enumerable.Range(1, n))
        {
            long temp = costs[n - 1];
            foreach(int j in Enumerable.Range(1, n - 1).Reverse())
            {
                costs[j] = Math.Min(costs[j], costs[j - 1]);
            }
            costs[0] = Math.Min(costs[0], temp);
            minSum = Math.Min(minSum, costs.Sum() + shiftCost * i);
        }
        System.Console.WriteLine(minSum);
    }
    
    static void Main(string[] args)
    {
        new Program().Slove();
    }
}