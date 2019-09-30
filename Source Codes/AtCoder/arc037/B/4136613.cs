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
        // ???????????…?Bellman-ford??????????
        var NM = Console.ReadLine().SplittedStringToInt32List();
        var N = NM[0];
        var M = NM[1];
        var connection = new bool[N, N];
        var isvisited = new int[N];
        for (int i = 0; i < N; i++)
        {
            isvisited[i] = -1;
        }

        for (int i = 0; i < M; i++)
        {
            var vn = Console.ReadLine().SplittedStringToInt32List();
            connection[vn[0] - 1, vn[1] - 1] = true;
            connection[vn[1] - 1, vn[0] - 1] = true;
        }
        var hasloops = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if (isvisited[i] != -1)
                continue;
            var stk = new Stack<KeyValuePair<int,int>>();
            stk.Push(new KeyValuePair<int,int>(i,-1));
            while (stk.Count > 0)
            {
                var item = stk.Pop();
                isvisited[item.Key] = i;

                for (int j = 0; j < N; j++)
                {
                    if (connection[item.Key, j] || connection[j,item.Key])
                    {
                        if (item.Value == j)
                        {
                            continue;
                        }
                        if (isvisited[j] == -1)
                        {
                            stk.Push(new KeyValuePair<int,int>(j,item.Key));
                            //connection[item.Key, j] = false;
                            //connection[j, item.Key] = false;
                        }
                        else
                        {
                            hasloops.Add(isvisited[item.Key]);
                        }
                        
                    }
                }
            }
        }
        hasloops = hasloops.Distinct().ToList();
        var counts = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if (!hasloops.Contains(isvisited[i]))
                counts.Add(isvisited[i]);
        }
        Console.WriteLine(counts.Distinct().Count());

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


    public static void PrintArray(char[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j]).Append("");
            }
            Console.WriteLine(sb.ToString());
        }
    }

    #endregion
}