using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var nt = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var cost = int.MaxValue;
        for (int i = 0; i < nt[0]; i++)
        {
            var route = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            if (nt[1] >= route[1])
            {
                cost = Math.Min(cost, route[0]);
            }
        }

        if (cost == int.MaxValue)
        {
            Console.WriteLine("TLE");
        }
        else
        {
            Console.WriteLine(cost);
        }
    }
}