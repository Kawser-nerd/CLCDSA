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

        var s = Console.ReadLine();
        var t = Console.ReadLine();
        var dic = new Dictionary<char, char>();
        var isok = true;
        for (int i = 0; i < s.Length; i++)
        {
            if (dic.ContainsKey(s[i]))
            {
                if (dic[s[i]] != t[i])
                {
                    isok = false;
                    break;
                }
            }
            else
            {
                dic.Add(s[i], t[i]);
            }
        }
        dic.Clear();
        for (int i = 0; i < s.Length; i++)
        {
            if (dic.ContainsKey(t[i]))
            {
                if (dic[t[i]] != s[i])
                {
                    isok = false;
                    break;
                }
            }
            else
            {
                dic.Add(t[i], s[i]);
            }
        }
        Console.WriteLine(isok ? "Yes" : "No");

        Console.ReadLine();
    }
    
    

    #region ?????
    public static long ToInt64(this string str) => long.Parse(str);
    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
    public static List<long> SplittedStringToInt64List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => long.Parse(x)).ToList();
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    public const int INF = int.MaxValue / 2;
    public const long LONGINF = long.MaxValue / 2;


    public static void PrintArray(bool[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j] ? "#" : ".").Append("");
            }
            Console.WriteLine(sb.ToString());
        }
    }

    #endregion
}