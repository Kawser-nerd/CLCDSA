using System;
using System.Collections.Generic;
using System.Linq;

public static partial class Program
{
    //????????
    public static int ToInt(this string str)
    {
        return int.Parse(str);
    }

    public static long ToLong(this string str)
    {
        return long.Parse(str);
    }
    public static IEnumerable<int> ToInt(this string[] strs)
    {
        return strs.Select(x => x.ToInt());
    }

    public static IEnumerable<long> ToLong(this string[] strs)
    {
        return strs.Select(x => x.ToLong());
    }
    public static IEnumerable<int> SplToInt(this string str, char opr = ' ')
    {
        return str.Split(opr).ToInt();
    }

    public static IEnumerable<long> SplToLong(this string str, char opr = ' ')
    {
        return str.Split(opr).ToLong();
    }
    public static string CRL()
    {
        return Console.ReadLine();
    }
    public static void CWL(object obj)
    {
        Console.WriteLine(obj);
    }
    public static int Diff(int a, int b)
    {
        return Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    }
    public static long Diff(long a, long b)
    {
        return Math.Abs(Math.Max(a, b) - Math.Min(a, b));
    }
    public static int Sign(this int i)
    {
        return Math.Sign(i);
    }
    //????????
}

public static partial class Program
{
    static void Main()
    {
        var str = CRL();
        var k = CRL().ToLong();
        var len = Math.Min(str.Length, k);
        for (int i = 0; i < len; i++)
        {
            if (str[i] != '1')
            {
                CWL(str[i]);
                return;
            }
        }

        CWL(1);
    }
}