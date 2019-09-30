using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var nmxy = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var xs = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var ys = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

        for (int z = nmxy[2] + 1; z < nmxy[3]; z++)
        {
            if (xs.All(x => x < z) && ys.All(x => x >= z))
            {
                Console.WriteLine("No War");
                return;
            }
        }

        Console.WriteLine("War");
    }
}