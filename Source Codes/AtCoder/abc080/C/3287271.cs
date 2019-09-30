using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Int32;
using static System.Math;
 
class Program
{
    static bool[] n2b(int n)
    {
        var result = new bool[10];
        int i = 0;
        while (0 < n)
        {
            result[i++] = (n % 2) == 1;
            n = n >> 1;
        }
        return result;
    }

    static int GetAndCount(bool[] lhs, bool[] rhs)
    {
        int result = 0;
        for(int i = 0; i < lhs.Length; ++i)
        {
            if (lhs[i] && rhs[i]) ++result;
        }
        return result;
    }

    static void Main(string[] args)
    {
        label:
        int n = Parse(ReadLine());
        var f = new bool[n][];
        var p = new int[n][];
        for(int i = 0; i < n; ++i)
        {
            f[i] = new bool[10];
            var sp = ReadLine().Split();
            for(int j = 0; j < sp.Length; ++j)
            {
                if (sp[j] == "1") f[i][j] = true;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            p[i] = ReadLine().Split().Select(Parse).ToArray();
        }
        int result = MinValue;
        for (int i = 1; i < 1024; ++i)
        {
            var array = n2b(i);
            int tmp = 0;
            for (int j = 0; j < f.Length; ++j)
            {
                tmp += p[j][GetAndCount(f[j], array)];
            }
            result = Max(result, tmp);
        }
        WriteLine(result);
    }
}