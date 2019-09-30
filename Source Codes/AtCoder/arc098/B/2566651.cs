using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
using static System.Math;

class P
{
    static void Main()
    {
        int max = int.MaxValue;
        //sum
        //A:0011
        //B:0101
        //  0110
        //XOR?????
        //Sum->
        //A:0011
        //B:0101
        //  0110(1)
        //?????????????
        //0????????????????0?????????? ?????20????
        int n = int.Parse(Console.ReadLine());
        long[] a = Console.ReadLine().Split().Select(long.Parse).ToArray();
        List<long> list = new List<long>();
        long zeroCount = 0;
        long res = 0;
        for (int i = 0; i < a.Length; i++)
        {
            if(a[i] != 0)
            {
                list.Add(-zeroCount);
                res += (zeroCount * (zeroCount + 1)) / 2;
                zeroCount = 0;
                list.Add(a[i]);
            }
            else
            {
                zeroCount++;
            }
        }
        list.Add(-zeroCount);
        res += (zeroCount * (zeroCount + 1)) / 2;
        zeroCount = 0;
        a = list.ToArray();

        n = (list.Count - 1) / 2;
        //0102030405060
        for (int i = 0; i < n; i++)
        {
            long sum = 0;
            long xor = 0;
            for (int j = i; j < n; j++)
            {
                sum += a[j * 2 + 1];
                xor ^= a[j * 2 + 1];
                if (sum == xor) res += ((-a[i * 2]) + 1) * ((-a[j * 2 + 2]) + 1);
                else break;
            }
        }
        Console.WriteLine(res);
    }
}