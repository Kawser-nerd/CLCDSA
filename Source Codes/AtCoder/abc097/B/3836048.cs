//#pragma warning disable

//using System;
//using System.Collections.Generic;
//using System.IO;
//using System.Linq;
//using System.Runtime.Serialization.Formatters.Binary;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Diagnostics;
//using System.Numerics;
//using System.Collections;
//using System.Timers;
//using System.Threading;

//static class MainClass
//{
//    public static void Main(string[] args)
//    {
//        var s = Console.ReadLine();
//        var K = Console.ReadLine().ToInt32();
//    }


//    #region ?????
//    public static long ToInt64(this string str) => long.Parse(str);
//    public static int ToInt32(this string str) => int.Parse(str);
//    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
//    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
//    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();
//    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
//    #endregion
//}


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
using System.Threading;

static class MainClass
{
    public static void Main(string[] args)
    {
        var X = Console.ReadLine().ToInt32();
        var ls = new List<int>();
        for (int i = 1; i * i <= 1000; i++)
        {
            ls.Add(i * i);
        }
        for (int i = 2; i <= 1000; i++)
        {
            ls.Add(i * i * i);
        }
        for (int i = 2; i <= 1000; i++)
        {
            ls.Add(i * i * i * i);
        }
        for (int i = 2; i <= 1000; i++)
        {
            ls.Add(i * i * i * i * i);
        }
        for (int i = 2; i <= 1000; i++)
        {
            ls.Add(i * i * i * i * i * i);
        }
        ls.AddRange(new int[]{ 128,256,512,1024 });
        Console.WriteLine(ls.Where(x => x <= X).Max());
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
    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    #endregion
}