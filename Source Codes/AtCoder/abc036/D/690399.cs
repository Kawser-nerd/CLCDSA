using System;
using System.Collections.Generic;

static class Program
{
    class Recursion
    {
        UInt64?[] whitememo;
        UInt64?[] blackmemo;
        public Recursion(int N)
        {
            whitememo = new UInt64?[N];
            blackmemo = new UInt64?[N];
        }

        UInt64 whiteCheck(List<int>[] data, int start,int before)
        {
            if (whitememo[start].HasValue)
                return whitememo[start].Value;
            UInt64 ret = 1;
            foreach(var v in data[start])
            {
                if (v == before)
                    continue;
                ret *= Check(data, v, start);
                ret %= 1000000007;
            }
            whitememo[start] = ret;
            return ret;
        }

        UInt64 blackCheck(List<int>[] data, int start, int before)
        {
            if (blackmemo[start].HasValue)
                return blackmemo[start].Value;
            UInt64 ret = 1;
            foreach (var v in data[start])
            {
                if (v == before)
                    continue;
                ret *= whiteCheck(data, v, start);
                ret %= 1000000007;
            }
            blackmemo[start] = ret;
            return ret;
        }

        UInt64 Check(List<int>[]data,int start,int before)
        {
            return whiteCheck(data, start, before) + blackCheck(data, start, before);
        }

        public UInt64 Check(List<int>[]data,int start)
        {
            return Check(data, start, data.Length);
        }
    }

    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        Recursion recur = new Recursion(N);
        List<int>[] data = new List<int>[N];
        for (int i = 0; i < N; ++i)
        {
            data[i] = new List<int>();
        }
        for (int i = 1; i < N; ++i)
        {
            var str = Console.ReadLine().Split(' ');
            var a = int.Parse(str[0]);
            var b = int.Parse(str[1]);
            data[a - 1].Add(b - 1);
            data[b - 1].Add(a - 1);
        }
        Console.WriteLine(recur.Check(data, 0) % 1000000007);
    }
}