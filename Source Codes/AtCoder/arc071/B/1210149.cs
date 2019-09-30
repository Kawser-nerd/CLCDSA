#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
// Do not use: System.Numerics;

public class Test
{
    public static void Main()
    {
        long MOD = 1;
        for (int i = 0; i < 9; i++)
        {
            MOD *= 10;
        }
        MOD += 7;

        var line0 = Console.ReadLine().Split(' ').Select(x => Int32.Parse(x)).ToArray();
        long n = line0[0];
        long m = line0[1];

        var x_i = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        var y_i = Console.ReadLine().Split(' ').Select(x => Int64.Parse(x)).ToArray();
        
        long temp = n - 1;
        long sum = 0;

        long x_sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            sum = (sum + temp + MOD) % MOD;
            long multiplier = sum;
            //Console.WriteLine(multiplier);
            temp -= 2;

            long length = x_i[i + 1] - x_i[i];

            x_sum = (x_sum + multiplier * length + MOD) % MOD;
        }

        long y_sum = 0;
        temp = m - 1;
        sum = 0;
        for (int i = 0; i < m - 1; i++)
        {
            sum = (sum + temp + MOD) % MOD;
            long multiplier = sum;
            //Console.WriteLine(multiplier);
            temp -= 2;

            long length = y_i[i + 1] - y_i[i];

            y_sum = (y_sum + multiplier * length + MOD) % MOD;
        }

        long result = (y_sum * x_sum) % MOD;

        Console.WriteLine(result);
    }
}