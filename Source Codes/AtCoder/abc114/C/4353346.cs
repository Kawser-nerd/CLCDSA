using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    private static int _limit;

    private readonly static string[] targets = new string[] {"3", "5", "7"};

    static void Main()
    {
        _limit = int.Parse(Console.ReadLine());
        
        Console.WriteLine(Search(0));
    }

    static long Search(long num)
    {
        if (num > _limit)
        {
            return 0;
        }

        var str = num.ToString();
        long count = 0;

        if (str.Contains("3") && str.Contains("5") && str.Contains("7"))
        {
            count++;
        }
        
        foreach (var target in targets)
        {
            count += Search(long.Parse(str + target));
        }

        return count;
    }
}