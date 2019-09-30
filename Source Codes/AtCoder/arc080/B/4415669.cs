using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;
//using static System.Globalization.CultureInfo;

class Program
{
    struct P
    {
        public int h;
        public int w;
        public P(int h,int w)
        {
            this.h = h;
            this.w = w;
        }
    }
    static void Main(string[] args)
    {
        var hw = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        
        var res = new int[hw[0]][];
        for (var i = 0; i < hw[0]; i++)
            res[i] = new int[hw[1]];
        var isY = true;
        var h = 0;
        var w = 0;
        var set = new HashSet<P>();
        var index = 0;
        var count = 0;
        var dif = 1;
        while (index != num)
        {
            res[h][w] = index + 1;
            count++;
            set.Add(new P(h, w));
            if (count == ar[index])
            {
                index++;
                count = 0;
            }
            var p = new P(h, w);
            if (isY)
                p.h += dif;
            else p.w += dif;
            if (isY && (p.h < 0 || p.h >= hw[0] || set.Contains(p)))
                isY = !isY;
            else if (!isY && (p.w < 0 || p.w >= hw[1] || set.Contains(p)))
            {
                isY = !isY;
                dif = -dif;
            }
            if (isY)
                h += dif;
            else w += dif;
        }
        WriteLine(string.Join("\n", res.Select(c => string.Join(" ", c))));
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}