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

        var NK = Console.ReadLine().SplittedStringToInt32List();
        var N = NK[0];
        var K = NK[1];

        var An = Console.ReadLine().SplittedStringToInt32List();

        var maxAn = An.Max();
        if (K > maxAn)
        {
            Console.WriteLine("IMPOSSIBLE");
        }
        else if (K == maxAn)
        {
            Console.WriteLine("POSSIBLE");
        }
        else
        {
            var isok = false;
            for (int i = 1; i < An.Count; i++)
            {
                if (Gcd(An[i -1],An[i]) == 1)
                {
                    isok = true;
                    break;
                }
            }
            if (!isok)
            {
               
                for (int i = 1; i < An.Count; i++)
                {
                    var num = Gcd(An[i - 1], An[i]);
                    
                    if (K % num == 0)
                    {
                        isok = true;
                        break;
                    }
                    
                }
            }
            Console.WriteLine(isok ? "POSSIBLE" : "IMPOSSIBLE");
        }

        Console.ReadLine();
    }

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
    
  
  

    public static void PrintArray(int[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < array.GetLength(1); j++)
            {
                sb.Append(array[i, j]).Append(" ");
            }
            Console.WriteLine(sb.ToString());
        }
    }

    #endregion
}