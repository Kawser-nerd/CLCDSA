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

        var l = Koubai_Lcm(s.Length, t.Length);
        var x = new Dictionary<long, char>();

        var lSl = l / s.Length;
        for (int i = 0; i < s.Length; i++)
        {
            var pos = i * lSl + 1;
            x[pos] = s[i];
        }


        var lTl = l / t.Length;
        for (int i = 0; i < t.Length; i++)
        {
            var pos = i * lTl + 1;
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



    /// <summary>
    /// ????? least common multiple
    /// a????????????b??????????????????????
    /// </summary>
    public static long Koubai_Lcm(int a, int b)
    {
        //a,b 2????????????????   a * b = gcd * lcm
        return (long)a * b / Kouyaku_Gcd(a, b);    //????????????????long????????
    }


    /// <summary>
    /// ????? Greatest Common Measure
    /// ??????a??????b????????????????
    /// ??????????
    /// </summary>
    public static long Kouyaku_Gcd(int a, int b)
    {
        if (a < b) return Kouyaku_Gcd(b, a); // ??????????????

        while (b != 0)
        {
            var temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

}     // Class