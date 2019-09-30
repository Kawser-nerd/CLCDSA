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

static class MainClass
{
    public static void Main(string[] args)
    {
        #region
        //var NAB = Console.ReadLine();
        //var N = NAB[0];
        //var B = NAB[2];
        //var A = NAB[1];

        //var vn = Console.ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => decimal.Parse(x)).ToList();
        //vn.Sort();
        //vn.Reverse();

        //decimal maxave = -1;
        //decimal before = -1;
        //decimal count = 0;
        //for (int i = 0; i < N; i++)
        //{
        //    if (before == vn[i])
        //    {

        //    }
        //    else
        //    {
        //        decimal num = 0;
        //        for (int j = 0; j <= i; j++)
        //        {
        //            num += vn[j];
        //        }
        //        if (maxave < num/(i + 1))
        //        {
        //            maxave = num / (i + 1);
        //            count = 1;
        //        }
        //        else if (maxave == num/(i + 1))
        //        {
        //            count++;
        //        }
        //    }


        //    before = vn[i];
        // 1
        //}
        #endregion
        var N = Console.ReadLine().ToInt32();
        var primes = GeneratePrimes().Take(5133).ToList();
        var firsts = new List<int>();
        var count = 0;

        foreach (var item in primes)
        {
            var tetet = item % 5;
            if (tetet == 1)
            {
                firsts.Add(item);
            }
        }
        var sb = new StringBuilder();
        foreach (var item in firsts.Take(N))
        {
            sb.Append(item + " ");
        }
        Console.WriteLine(sb.ToString().Remove(sb.ToString().Length - 1));
        Console.ReadLine();
    }



    public static IEnumerable<T[]> Enumerate<T>(IEnumerable<T> items, int k, bool withRepetition)
    {
        if (k == 1)
        {
            foreach (var item in items)
                yield return new T[] { item };
            yield break;
        }
        foreach (var item in items)
        {
            var leftside = new T[] { item };

            var unused = withRepetition ? items : items.SkipWhile(e => !e.Equals(item)).Skip(1).ToList();

            foreach (var rightside in Enumerate(unused, k - 1, withRepetition))
            {
                yield return leftside.Concat(rightside).ToArray();
            }
        }
    }
    public class BoundedBoolArray
    {
        private BitArray _array;
        private int _lower;

        public BoundedBoolArray(int lower, int upper)
        {
            _array = new BitArray(upper - lower + 1);
            _lower = lower;
        }

        public bool this[int index]
        {
            get
            {
                return _array[index - _lower];
            }
            set
            {
                _array[index - _lower] = value;
            }
        }
    }
    public static IEnumerable<int> GeneratePrimes()
    {
        var primes = new List<int>() { 2, 3 };
        foreach (var p in primes)
            yield return p;
        int ix = 0;
        while (true)
        {
            var first = primes[ix];
            var second = primes[++ix];
            var lower = first * first;
            var upper = second * second - 1;
            var sieve = new BoundedBoolArray(lower, upper);
            foreach (var prime in primes.Take(ix))
            {
                var start = (int)Math.Ceiling((double)lower / prime) * prime;
                for (int index = start; index <= upper; index += prime)
                    sieve[index] = true;
            }
            for (int i = lower; i <= upper; i++)
            {
                if (sieve[i] == false)
                {
                    primes.Add(i);
                    yield return i;
                }
            }
        }
    }

    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    public const int INF = int.MaxValue / 2;
    public const long LONGINF = long.MaxValue / 2;
    #endregion
}