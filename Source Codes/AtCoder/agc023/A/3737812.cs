using System;
using System.Linq;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var a = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);
        var sum = new List<long>();
        long temp = 0;
        for (int i = 0; i < a.Length; i++)
        {
            temp += a[i];
            sum.Add(temp);
        }
        sum = sum.OrderBy(f => f).ToList();
        long ans = 0;
        long cont = 1;
        for (int i = 0; i < sum.Count() - 1; i++)
        {
            if (sum[i] == sum[i + 1])
            {
                cont++;
            }
            else
            {
                ans += cont * (cont - 1) / 2;
                cont = 1;
            }
        }
        ans += cont * (cont - 1) / 2;
        ans += sum.Count(f => f == 0);
        Console.WriteLine(ans);
    }
}