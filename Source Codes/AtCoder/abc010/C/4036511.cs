using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int[] cin = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();
        int[] ta = { cin[0], cin[1] };
        int[] tb = { cin[2], cin[3] };
        int t = cin[4];
        int v = cin[5];
        int n = int.Parse(Console.ReadLine());
        var flag = false;
        for (int i = 0; i < n; i++)
        {
            cin = Console.ReadLine().Split().Select(j => int.Parse(j)).ToArray();
            int x = cin[0];
            int y = cin[1];
            if (Math.Sqrt(Math.Pow(x - ta[0], 2) + Math.Pow(y - ta[1], 2)) + Math.Sqrt(Math.Pow(tb[0] - x, 2) + Math.Pow(tb[1] - y, 2)) <= t * v)
            {
                flag = true;
                break;
            }
        }
        if (flag) Console.WriteLine("YES");
        else Console.WriteLine("NO");
    }
}