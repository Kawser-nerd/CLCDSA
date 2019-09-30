using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Int32;
using static System.Math;
 
class Program
{
    class Bngm : IComparable<Bngm>
    {
        public int Start;
        public int End;
        public int Channel;

        public int CompareTo(Bngm other)
        {
            if (Start != other.Start) return Start - other.Start;
            if (End != other.End) return End - other.End;
            return Channel - other.Channel;
        }
    }

    static void Main(string[] args)
    {
        label:
        var sp = ReadLine().Split();
        int n = Parse(sp[0]);
        var set = new SortedSet<Bngm>();
        var endChDic = new Dictionary<KeyValuePair<int, int>, Bngm>();
        for(int i = 0; i < n; ++i)
        {
            sp = ReadLine().Split();
            var bngm = new Bngm();
            bngm.Start = Parse(sp[0]);
            bngm.End = Parse(sp[1]);
            bngm.Channel = Parse(sp[2]);
            var pair = new KeyValuePair<int, int>(bngm.Start, bngm.Channel);
            if (endChDic.ContainsKey(pair))
            {
                var prev = endChDic[pair];
                prev.End = bngm.End;
                endChDic.Remove(pair);
                endChDic[new KeyValuePair<int, int>(prev.End, prev.Channel)] = prev;
            }
            else
            {
                set.Add(bngm);
                endChDic[new KeyValuePair<int, int>(bngm.End, bngm.Channel)] = bngm;
            }
        }
        var list = new List<Bngm>();
        foreach(var bngm in set)
        {
            int i = 0;
            for (; i < list.Count; ++i)
            {
                var last = list[i];
                if (last.End < bngm.Start)
                {
                    list[i] = bngm;
                    break;
                }
                else if (last.End == bngm.Start && last.Channel == bngm.Channel)
                {
                    list[i] = bngm;
                    break;
                }
            }
            if (i == list.Count) list.Add(bngm);
            //WriteLine($"{bngm.Start} {bngm.End} {bngm.Channel}");
        }
        WriteLine(list.Count);
    }
}