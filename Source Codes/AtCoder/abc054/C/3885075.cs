#pragma warning disable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;
using System.Collections;
using System.Timers;

static class MainClass
{
    public static void Main(string[] args)
    {
        var NM = Console.ReadLine().SplittedStringToInt32List();
        var N = NM[0];
        var M = NM[1];
        var edges = new List<Edge>();
        for (int i = 0; i < M; i++)
        {
            var item = Console.ReadLine().SplittedStringToInt32List();
            var ed = new Edge() {  From = item[0], To = item[1] };

            edges.Add(ed);
        }
        var ls = new List<int>();
        for (int i = 1; i <= N; i++)
        {
            ls.Add(i);
        }
        var nums = ls.Perm().Select(x => x.ToArray()).Where(x => x[0] == 1);

        var count = 0;
        foreach (var item in nums)
        {
            var isok = true;
            var before = -1;
            foreach (var item2 in item)
            {
                if (before == -1)
                {
                    before = item2;
                    continue;
                }
                if (edges.Where(x => (x.From == item2 && x.To == before) || (x.To == item2 && x.From == before)).Count() <= 0)
                {
                    isok = false;
                    break;
                }
                before = item2;
            }
            if (isok)
            {
                count++;
            }
        }
        Console.WriteLine(count);

        Console.ReadLine();

    }
    public static IEnumerable<IEnumerable<T>> Perm<T>(this IEnumerable<T> items, int? k = null)
    {
        if (k == null)
            k = items.Count();

        if (k == 0)
        {
            yield return Enumerable.Empty<T>();
        }
        else
        {
            var i = 0;
            foreach (var x in items)
            {
                var xs = items.Where((_, index) => i != index);
                foreach (var c in Perm(xs, k - 1))
                    yield return c.Before(x);

                i++;
            }
        }
    }

    // ????????????????????
    public static IEnumerable<T> Before<T>(this IEnumerable<T> items, T first)
    {
        yield return first;

        foreach (var i in items)
            yield return i;
    }
    class Edge
    {
        public int From;
        public int To;
    }



    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();

    public const int INF = int.MaxValue / 2;
    #endregion
}