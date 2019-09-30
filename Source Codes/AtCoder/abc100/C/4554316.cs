using System;
using System.Linq;
using System.Collections.Generic;

class Cmondai
{
    static void Main()
    {
        var N = Int32.Parse(Console.ReadLine());
        var a = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToList();
        var ans = 0;
        while (0<a.Count())
        {
            for (int i = 0; i < a.Count(); ++i)
            {
                if (a[i] % 2 == 0)
                {
                    ans++;
                    a[i] /= 2;
                }
                else a.RemoveAt(i);
            }
        }
        Console.WriteLine(ans);
    }
}