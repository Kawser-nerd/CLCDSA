using System;
using System.Collections.Generic;
using System.Linq;
using static System.Console;
using static System.Convert;
using static System.Math;

class Program
{
    public struct P
    {
        public int index;
        public int rate;
        public int hand;
        public int[] result;
        public P(int index,int rate,int hand)
        {
            this.rate = rate;
            this.hand = hand;
            this.index = index;
            result = new int[3];
        }
    }
    static void Main(string[] args)
    {
        var num = ToInt32(ReadLine());
        var ps = new P[num];
        for(var i = 0; i < num; i++)
        {
            var rh = Array.ConvertAll(ReadLine().Split(' '), int.Parse);
            ps[i] = new P(i,rh[0], rh[1]-1);
        }
        ps = ps.OrderBy(v => v.rate).ToArray();
        for(var i = 0; i < num; i++)
        {
            var lo = LowerBound(ps, ps[i].rate);
            var up = UpperBound(ps, ps[i].rate);
            ps[i].result[0] = lo;
            ps[i].result[1] = num - up + 1;
            var hands = new int[3];
            for(var j = lo; j < up; j++)
            {
                hands[ps[j].hand]++;
                ps[j].result[0] = lo;
                ps[j].result[1]= num - up;
            }
            for (; i < up; i++)
            {
                ps[i].result[0] += hands[(ps[i].hand+1) % 3];
                ps[i].result[1] += hands[ps[i].hand - 1 < 0 ? 2 : ps[i].hand - 1];
                ps[i].result[2] = hands[ps[i].hand] - 1;
            }
            i--;
        }
        ps = ps.OrderBy(v => v.index).ToArray();
        for(var i = 0; i < num; i++)
        {
            WriteLine(string.Join(" ",ps[i].result));
        }
    }

    public static int UpperBound(P[] array, int value)
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].rate > value) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    public static int LowerBound(P[] array, int value)
    {
        var low = 0;
        var high = array.Length;
        while (high > low)
        {
            var mid = (high + low) / 2;
            if (array[mid].rate >= value) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    private const string ALFA = "abcdefghijklmnopqrstuvwxyz";
    private const int MOD = 1000000007;
}