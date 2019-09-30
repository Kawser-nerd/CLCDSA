using System;
using System.Collections.Generic;
class c
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var list = new List<double>();
        for (int i = 0; i < n; i++)
        {
            list.Add(double.Parse(Console.ReadLine()));
        }
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            double cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (list[i] % list[j] == 0) cnt++;
            }
            if (cnt == 1) ans += 1;
            else if (cnt % 2 == 0) ans += 1.0 / 2;
            else ans += (cnt / 2 + 0.5) / cnt;
        }
        Console.WriteLine(ans);
    }
}