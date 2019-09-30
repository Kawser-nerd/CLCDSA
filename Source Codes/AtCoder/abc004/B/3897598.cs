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
        var grid = new char[4, 4];
        var newnewgrid = new char[4, 4];
        for (int i = 0; i < 4; i++)
        {
            var str = Console.ReadLine().SplittedStringToList();
            for (int j = 0; j < 4; j++)
            {
                grid[i, j] = str[j].ToCharArray()[0];
            }
        }
        var newgrid = new char[4, 4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                newgrid[i, j] = grid[j, i];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                // newgrid[i, j] = grid[(i + 3) % 4, ((j + 3) % 4)];
                newnewgrid[i, j] = newgrid[j, i];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            var sb = new StringBuilder();
            for (int j = 0; j < 4; j++)
            {
                sb.Append(newnewgrid[3 - i, 3 - j] + " ");
            }

            Console.WriteLine(sb.ToString().Remove(sb.ToString().Length - 1));
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