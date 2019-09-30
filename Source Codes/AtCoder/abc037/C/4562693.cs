using System;
using System.Linq;

public class Program
{
    static void Main()
    {
        var nk = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();
        var aArray = Console.ReadLine().Split().Select(x => long.Parse(x)).ToArray();

        long sum = 0;
        long range = nk[0] - nk[1] + 1;
        
        for (int j = 0; j < range; j++)
        {
            sum += aArray[j];
        }

        var buf = sum;
        for (int i = 1; i < nk[0] - range + 1; i++)
        {
            buf = buf - aArray[i - 1] + aArray[i + range - 1];
            sum += buf;
        }

        Console.WriteLine(sum);
    }
}