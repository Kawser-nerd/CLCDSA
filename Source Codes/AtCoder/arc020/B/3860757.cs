using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    static void Main(string[] args)
    {
        var nc = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var col = new int[nc[0]];
        for(var i=0;i<nc[0];i++)col[i]=ToInt32(ReadLine());
        var price = int.MaxValue;
        for(var i = 1; i <= 10; i++)
        {
            for(var j = 1; j <= 10; j++)
            {
                var p = 0;
                if (i == j) continue;
                for(var h = 0; h < nc[0]; h++)
                {
                    if (h % 2 == 0)
                    {
                        if (col[h] != i) p++;
                    }
                    else
                    {
                        if (col[h] != j) p++;
                    }
                }
                price = Min(price, p * nc[1]);
            }
        }
        WriteLine(price);
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}