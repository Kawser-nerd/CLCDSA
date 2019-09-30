using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Int32;

class Program
{
    static bool IsSosu(int num)
    {
        var max = Math.Sqrt(num);
        for(int i = 2; i <= max; ++i)
        {
            if (num % i == 0) return false;
        }
        return true;
    }

    static void Main(string[] args)
    {
        label:
        int count = Parse(ReadLine());
        var list = new List<string>();
        for(int num=2; ; num += 5)
        {
            if (IsSosu(num))
            {
                list.Add(num.ToString());
                if (list.Count == count) break;
            }
        }
        WriteLine(string.Join(" ", list));
    }
}