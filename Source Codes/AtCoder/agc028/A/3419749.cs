using System;
using System.Collections.Generic;

//https://beta.atcoder.jp/contests/agc028/tasks/agc028_a

public class Program_AGC028_A // ?Class?????
{
    public static void Main(string[] args)
    {
        var st = Console.ReadLine();
        var s = Console.ReadLine();
        var t = Console.ReadLine();

        var l = Lcm(s.Length, t.Length);
        var x = new Dictionary<long, char>();

        for (int i = 0; i < s.Length; i++)
        {
            var pos = i * (l / s.Length) + 1;
            x[pos] = s[i];
        }


        for (int i = 0; i < t.Length; i++)
        {
            var pos = i * (l / t.Length) + 1;
            if (x.ContainsKey(pos))
            {
                if (x[pos] != t[i])
                {
                    Console.WriteLine(-1);
                    return;

                }
            }
        }

        Console.WriteLine(l);
    } // Main



    // ????? least common multiple 
    //public static long Lcm(int a, int b)
    //{
    //    return a * b / Gcd(a, b);
    //}

    // ?????????? 
    //public static int Gcd(int a, int b)
    //{
    //    if (a < b)  return Gcd(b, a); // ??????????????

    //    while (b != 0)
    //    {
    //        var temp = a % b;
    //        a = b;
    //        b = temp;
    //    }

    //    return a;
    //}





    static long Gcd(long a, long b)
    {
        var small = Math.Min(a, b);
        var big = Math.Max(a, b);

        if (small > 0)
        {
            return Gcd(small, big % small);
        }
        else
        {
            return big;
        }


        //if (a < b)
        //{
        //    return Gcd(b, a);
        //}
        //else
        //{
        //    if (b > 0)
        //    {
        //        return Gcd(b, a % b);
        //    }
        //    else
        //    {
        //        return a;
        //    }
        //}

        //return (a < b) ? Gcd(b, a)
        //     : (b > 0) ? Gcd(b, a % b)
        //               : a;
    }

    static long Lcm(long a, long b)
    {
        return a / Gcd(a, b) * b;
    }


    static long gcd(long a, long b)
    {
        long c = Math.Max(a, b) % Math.Min(a, b);
        b = Math.Min(a, b);
        while (c != 0)
        {
            a = b % c;
            b = c;
            c = a;
        }
        return b;
    }

}     // Class