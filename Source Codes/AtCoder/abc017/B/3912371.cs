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
        var X = Console.ReadLine();
        var before = X;
        while (true)
        {
            before = X;
            if (X.Length == 0)
            {
                Console.WriteLine("YES");

                Console.ReadLine();
                return;
            }
            if (X[X.Length - 1] == 'o' || X[X.Length - 1] == 'k' || X[X.Length - 1] == 'u')
            {
                X = X.Remove(X.Length - 1, 1);
            }
            else if (X.Length >= 2 && (X[X.Length - 2] == 'c' && X[X.Length - 1] == 'h'))
            {
                X = X.Remove(X.Length - 2, 2);

            }
            else
            {
                Console.WriteLine("NO");

                Console.ReadLine();
                return;
            }
        }
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

        //}
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