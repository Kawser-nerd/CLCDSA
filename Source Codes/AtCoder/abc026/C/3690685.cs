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
        public List<int> did;
        public P(int index)
        {
            this.index = index;
            did = new List<int>();
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var sup = new int[num - 1];
        var p = new long[num+1];
        var gu = new P[num];
        for (var i = 0; i < num; i++)
            gu[i] = new P(i + 1);
        for (var i = 0; i < num - 1; i++)
        {
            sup[i] = ToInt32(ReadLine());
            gu[sup[i]-1].did.Add(i + 2);
        }
        Get(p, 1, gu);
        WriteLine(p[1]);

    }
    private static void Get(long[] p, int index, P[] gu)
    {
        if (gu[index-1].did.Count == 0) { p[index] = 1; return; }
        foreach (var g in gu[index-1].did)
        {
            Get(p, g, gu);
        }
        var max = 0L;
        var min = long.MaxValue;
        foreach(var g in gu[index-1].did)
        {
            max = Max(max, p[g]);
            min = Min(min, p[g]);
        }
        p[index] = max + min + 1;
    }
    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}