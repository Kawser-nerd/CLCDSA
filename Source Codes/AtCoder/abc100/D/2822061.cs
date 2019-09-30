using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;

class Program
{
    static void Main(string[] args)
    {
        var array = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        var N = array[0];
        var M = (int)array[1];
        var scores = new List<Score>();
        for (int i = 0; i < N; i++)
        {
            var line = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
            var s = new Score(line[0], line[1], line[2]);
            scores.Add(s);
        }
        var values = new List<long>();
        values.Add(scores.Select(x => x.Sum(true, true, true)).OrderByDescending(x=>x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(true, true, false)).OrderByDescending(x=>x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(true, false, true)).OrderByDescending(x => x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(true, false, false)).OrderByDescending(x => x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(false, true, true)).OrderByDescending(x => x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(false, true, false)).OrderByDescending(x => x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(false, false, true)).OrderByDescending(x => x).Take(M).Sum());
        values.Add(scores.Select(x => x.Sum(false, false, false)).OrderByDescending(x => x).Take(M).Sum());
        WriteLine(values.Max());
    }
    public struct Score
    {
        public Score(long x, long y, long z)
        {
            X = x;
            Y = y;
            Z = z;
        }
        public long X, Y, Z;
        public long Sum(bool x, bool y, bool z)
        {
            return (x?X:-X) + (y ? Y : -Y) + (z ? Z : -Z);
        }
    }
}