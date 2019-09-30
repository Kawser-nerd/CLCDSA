using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    class P
    {
        public int h;
        public int w;
        public int distance;
        public P(int h,int w)
        {
            this.h = h;
            this.w = w;
            distance = -1;
        }
    }
    static void Main(string[] args)
    {
        var hw = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var gred = new string[hw[0]];
        for (var i = 0; i < hw[0]; i++)
            gred[i] = ReadLine();
        var distance = new P[hw[0], hw[1]];
        for (var i = 0; i < hw[0]; i++)
            for (var j = 0; j < hw[1]; j++)
                distance[i, j] = new P(i, j);
        var queue = new Queue<P>();
        queue.Enqueue(distance[0,0]);
        distance[0, 0].distance = 0;
        while (queue.Count != 0)
        {
            var par = queue.Dequeue();
            for(var i = 0; i < 4; i++)
            {
                var h = par.h + GREDH[i];
                var w = par.w + GREDW[i];
                if (isMatch(new P(h, w), hw[0], hw[1]))
                {
                    var p = distance[h, w];
                    if (p.distance == -1 && gred[p.h][p.w] != '#')
                    {
                        p.distance = par.distance + 1;
                        queue.Enqueue(p);
                    }
                }
            }
        }
        if (distance[hw[0] - 1, hw[1] - 1].distance == -1)
        {
            WriteLine(-1);
            return;
        }
        var count = gred.Sum(g => g.Count(c => c == '.'));
        WriteLine(count - distance[hw[0] - 1, hw[1] - 1].distance - 1);
    }
    private static bool isMatch(P p,int h,int w)
    {
        return 0 <= p.h && p.h < h && 0 <= p.w && p.w < w;
    }
    private static int[] GREDH = new[] { 0, 0, 1, -1 };
    private static int[] GREDW = new[] { 1, -1, 0, 0 };
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}