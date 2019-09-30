using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
using System.Numerics;

public class Program
{
    public static void Main(string[] args)
    {
        string[] line = Console.ReadLine().Split(' ');
        int n = int.Parse(line[0]);
        int t = int.Parse(line[1]);

        var ct = new CostTime[n];
        for (int i = 0; i < ct.Length; i++)
        {
            line = Console.ReadLine().Split(' ');
            ct[i] = new CostTime(int.Parse(line[0]), int.Parse(line[1]));
        }
        var ict = ct.Where(v => v.time <= t);

        Console.WriteLine(ict.Any() ? ict.Min(v => v.cost).ToString() : "TLE");
        Console.ReadLine();
    }

    public struct CostTime
    {
        public int cost;
        public int time;

        public CostTime(int cost, int time)
        {
            this.cost = cost;
            this.time = time;
        }
    }
}