using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var nmc = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
        var bArray = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

        var count = 0;
        for (int i = 0; i < nmc[0]; i++)
        {
            var aArray = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            var val = 0;
            for (int j = 0; j < nmc[1]; j++)
            {
                val += aArray[j] * bArray[j];
            }

            if (val + nmc[2] > 0)
            {
                count++;
            }
        }

        Console.WriteLine(count);
    }
}