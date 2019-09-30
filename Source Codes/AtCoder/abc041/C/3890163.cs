using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    struct P
    {
        public int index;
        public int row;
        public P(int index,int row)
        {
            this.index = index;
            this.row = row;
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ar = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
        var ps = new P[num];
        for(var i = 0; i < num; i++)
        {
            ps[i] = new P(i + 1, ar[i]);
        }
        ps = ps.OrderByDescending(v => v.row).ToArray();
        for(var i = 0; i < num; i++)
        {
            WriteLine(ps[i].index);
        }
    }

}