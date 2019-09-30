using System;
using System.Collections.Generic;

public class CSharp
{
    public static void Main()
    {
        Kyopuro chokudai = new Kyopuro();
        chokudai.AtCoder();
    }
}

public class Kyopuro
{
    public void AtCoder()
    {
        int n = int.Parse(Console.ReadLine());
        int m = n;
        int ans = 0;
        if (n % 2 == 1)
        {
            m--;
            ans = (m - 2) * m / 2 + m;
        } else
        {
            ans = (m - 2) * m / 2;
        }
        Console.WriteLine(ans);

        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= m; j++)
            {
                if (i != j && i + j != m + 1)
                {
                    Console.WriteLine(i + " " + j);
                }
            }
        }
        if (n % 2 == 1)
        {
            for(int i = 1; i < n; i++)
            {
                Console.WriteLine(i + " " + n);
            }
        }
    }
    public static void DebugWL(object x) { System.Diagnostics.Debug.WriteLine(x); }
}