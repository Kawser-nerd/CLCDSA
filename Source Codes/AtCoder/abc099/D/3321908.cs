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
        //var data = File.OpenText(@"c:\users\\downloads\02.txt");
        //var sw = new Stopwatch();
        
        //Console.SetIn(data);
        //sw.Start();
        var nc = Console.ReadLine().SplittedStringToInt32List();
        var n = nc[0];
        var c = nc[1];
        // var iwakans = new Dictionary<KeyValuePair<int, int>, int>();
        var iwakansar = new int[c,c];
        var amari1ls = new List<int>();
        var amari0ls = new List<int>();
        var amari2ls = new List<int>();
        var amarilss = new List<int>[3] { amari0ls, amari1ls, amari2ls };
        for (int i = 0; i < c; i++)
        {
            var dc = Console.ReadLine().SplittedStringToInt32List();
            for (int j = 0; j < c; j++)
            {
                // iwakans.Add(new KeyValuePair<int, int>(i, j), dc[j]);
                iwakansar[i, j] = dc[j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            var cn = Console.ReadLine().SplittedStringToInt32List();
            for (int j = 0; j < n; j++)
            {
                amarilss[(i + j) % 3].Add(cn[j]);
            }
        }

        var countsLs = new List<KeyValuePair<int,KeyValuePair<int, int>>>();
        for (int i = 0; i < 3; i++)
        {
            var ls = amarilss[i];
            var sumsLs = new List<KeyValuePair<int,int>>();
            for (int j = 0; j < c; j++)
            {
                var num = 0;
                foreach (var item in ls)
                {
                    //num += iwakans.Where(x => x.Key.Key == item - 1 && x.Key.Value == j).First().Value;
                    num += iwakansar[item - 1, j];
                }
                sumsLs.Add(new KeyValuePair<int, int>(j,num));
            }
            countsLs.AddRange(sumsLs.OrderBy(x => x.Value).Take(3).Select(x => new KeyValuePair<int, KeyValuePair<int, int>>(i,x)).ToList());
        }
        var kkk = new List<int>();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    var aa = countsLs.Where(x => x.Key == 0).ToArray()[i];
                    var bb = countsLs.Where(x => x.Key == 1).ToArray()[j];
                    var cc = countsLs.Where(x => x.Key == 2).ToArray()[k];
                    if (aa.Value.Key != bb.Value.Key && bb.Value.Key != cc.Value.Key && cc.Value.Key != aa.Value.Key)
                    {
                        kkk.Add(aa.Value.Value + bb.Value.Value + cc.Value.Value);
                    }
                }
            }
        }
        Console.WriteLine(kkk.Min());
        //sw.Stop();
        //Console.WriteLine(sw.ElapsedMilliseconds);
        //Console.ReadLine();
    }

    //public class Edge
    //{
    //    public int From;
    //    public int To;
    //    public int Cost;
    //}

    //public static List<KeyValuePair<int, int>> GetShortestPathes(int s, IEnumerable<Edge> edges, int vertices)
    //{
    //    var ls = new KeyValuePair<int, int>[vertices];

    //    return ls.ToList();
    //}


    #region ?????

    #region ?????

    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();

    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    #endregion
    #region DeepClone
    public static T DeepClone<T>(this T src)
    {
        using (var memoryStream = new MemoryStream())
        {
            var binaryFormatter
              = new BinaryFormatter();
            binaryFormatter.Serialize(memoryStream, src);
            memoryStream.Seek(0, SeekOrigin.Begin);
            return (T)binaryFormatter.Deserialize(memoryStream);
        }
    }
    #endregion

    public static int Gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return Gcd(b, a % b);
    }
    public static BigInteger Gcd(BigInteger a, BigInteger b)
    {
        if (b == 0)
            return a;
        return Gcd(b, a % b);
    }


    public static BigInteger Factorial(int n)
    {
        var dp = new BigInteger[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] * (i + 1);
        }
        return dp[n - 1];
    }

    public static List<int> PrimeFactorize(int n)
    {
        var bases = n;
        var num = (int)Math.Pow(n, 0.5);
        var ls = new List<int>();
        for (int i = 2; i <= num; i++)
        {
            if (n % i == 0)
            {
                n = n / i;
                ls.Add(i);
                i--;
                continue;
            }
        }
        var nnn = 1;
        foreach (var item in ls)
        {
            nnn = nnn * item;
        }
        if (nnn != bases)
            ls.Add(n);
        return ls;
    }

    #endregion

}