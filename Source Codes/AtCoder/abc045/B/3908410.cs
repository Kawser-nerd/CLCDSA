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
        var a = Console.ReadLine();
        var b = Console.ReadLine();
        var c = Console.ReadLine();
        var before = "a";
        while (true)
        {
            {
                if (before == "a")
                {
                    if (a.Length == 0)
                    {
                        Console.WriteLine("A");
                        break;
                    }
                    before = a[0].ToString();

                    a = a.Remove(0, 1);
                }
                else if (before == "b")
                {
                    if (b.Length == 0)
                    {
                        Console.WriteLine("B");
                        break;
                    }
                    before = b[0].ToString();

                    b = b.Remove(0, 1);
                }
                else
                {
                    if (c.Length == 0)
                    {
                        Console.WriteLine("C");
                        break;
                    }
                    before = c[0].ToString();

                    c = c.Remove(0, 1);

                }
            }
        }

        Console.ReadLine();
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