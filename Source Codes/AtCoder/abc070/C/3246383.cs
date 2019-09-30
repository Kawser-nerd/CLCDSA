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
        var n = Console.ReadLine().ToInt32();
        BigInteger before = 1;
        for (int i = 0; i < n; i++)
        {
            var t = Console.ReadLine().ToBigInteger();
            before = (t * before) / Gcd(t, before);
        }
        Console.WriteLine(before);
        Console.ReadLine();
    }

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

    public static int Gcd(int a,int b)
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

    #endregion

}