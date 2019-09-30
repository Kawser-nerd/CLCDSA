using System;
using System.Linq;
using static System.Console;
using static System.Convert;

class Program
{
    struct P
    {
        public int index;
        public int t;
        public P(int index,int t)
        {
            this.index = index;
            this.t = t;
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ps = new P[num];
        for (var i = 0; i < num; i++)
            ps[i] = new P(i + 1, ar[i]);
        ps = ps.OrderByDescending(v => v.t).ToArray();
        for (var i = 0; i < num; i++)
            WriteLine(ps[i].index);
    }
}