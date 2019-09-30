using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var dic = new Dictionary<int, int>();
        var prime = new List<int>();
        var bo = new bool[num+1];
        for (var i = 2; i <= num; i++)
            if (!bo[i])
            {
                prime.Add(i);
                for (var j = 2 * i; j <= num; j += i)
                    bo[j] = true;
            }
        for (var i = 2; i <= num; i++)
            foreach (var prim in prime)
            {
                if (i < prim) break;
                if (i % prim == 0)
                {
                    var al = i;
                    while (al%prim==0)
                    {
                        if (dic.ContainsKey(prim)) dic[prim]++;
                        else dic[prim] = 1;
                        al /= prim;
                    }
                }
            }
        var ar = new[] { 74, 24, 14, 4, 2 };
        var uu = new int[ar.Length];
        for (var i = 0; i < ar.Length; i++)
            uu[i] = dic.Values.Count(v => v >= ar[i]);
        var res = 0;
        res += uu[0];
        res += uu[1] * (uu[4] - 1);
        res += uu[2] * (uu[3] - 1);
        res += uu[3] * (uu[3] - 1) * (uu[4] - 2)/2;
        WriteLine(res);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}