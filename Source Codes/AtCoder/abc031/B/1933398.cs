using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main()
    {
        int[] LH = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = int.Parse(Console.ReadLine());
        string res = "";
        for (int i = 0; i < n; i++)
        {
            int a = int.Parse(Console.ReadLine());
            if (a <= LH[1])
            {
                if (LH[0] > a)
                {
                    res += $"{LH[0] - a}";
                }
                else
                {
                    res += $"0";
                }
            }
            else
            {
                res += "-1";
            }
            res += "\n";
        }
        Console.Write(res);
    }
}