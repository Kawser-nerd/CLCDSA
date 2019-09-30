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
        var xy = Console.ReadLine().SplittedStringToInt32List();
        var A = xy[0];
        var B = xy[1];
        var paliolist = new List<int>();
        for (int i = A; i <= B; i++)
        {
            var str = i.ToString();
            if (str[0] == str[4] && str[1] == str[3])
            {
                paliolist.Add(i);
            }
        }
        Console.WriteLine(paliolist.Count);
        Console.ReadLine();
    }


    //// s??????????????????????Bellman-Ford

    //public static void Initialize(int N)
    //{

    //}

    //public static int N;

    //public class Edge
    //{
    //    public int From;
    //    public int To;
    //    public int Cost;
    //}

    //public static List[N Edges;

    //public static List<int> ShortestDistances;

    
    
    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    #endregion
}