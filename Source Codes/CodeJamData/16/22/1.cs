using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");
        sw.AutoFlush = true;
        long n = long.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (long i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static void MakeSame(char[] a, char[] b, long f)
    {
        for (long i = 0; i < f; i++)
        {
            if (a[i] == '?')
            {
                if (b[i] == '?')
                    a[i] = b[i] = '0';
                else
                    a[i] = b[i];
            }
            else
            {
                if (b[i] == '?')
                    b[i] = a[i];
                else
                    if (a[i] != b[i])
                        throw new Exception("noe");
            }
        }
    }

    static void S(char[] a, char[] b, long f, ref long C, ref long J)
    {
        MakeSame(a, b, f);
        if (b[f] != '0' && a[f] != '9')
        {
            if (b[f] == '?')
            {
                if (a[f] != '?')
                {
                    b[f] = (char)(a[f] + 1);
                }
                else
                {
                    a[f] = '0';
                    b[f] = '1';
                }
            }
            else
            {
                if (a[f] == '?')
                {
                    a[f] = (char)(b[f] - 1);
                }
            }
        }

        for (long i = f; i < a.Length; i++)
        {
            if (a[i] == '?')
                a[i] = '9';
            if (b[i] == '?')
                b[i] = '0';
        }

        long c = GI(a);
        long j = GI(b);

        if (Math.Abs(C - J) > Math.Abs(c - j))
        {
            C = c; J = j;
        }
        if (Math.Abs(C - J) == Math.Abs(c - j))
        {
            if (c < C)
            {
                C = c; J = j;
            }
            if (c == C && j < J)
            {
                C = c; J = j;
            }
        }

    }

    static long GI(char[] a)
    {
        long r = 0;
        for (long i = 0; i < a.Length; i++)
        {
            r *= 10;
            r += a[i] - '0';
        }
        return r;
    }

    static string Solution(StreamReader sr)
    {
        string[] t = sr.ReadLine().Split(' ');
        long C = 0, J = long.MaxValue / 3;

        try
        {
            char[] a = t[0].ToCharArray();
            char[] b = t[1].ToCharArray();
            MakeSame(a, b, a.Length);
            long r = GI(a);
            return r.ToString("D" + t[0].Length.ToString()) + " " + r.ToString("D" + t[0].Length.ToString());
        }
        catch (Exception e) { }


        for (int i = 0; i < t[0].Length + 1; i++)
        {
            try
            {
                S(t[0].ToCharArray(), t[1].ToCharArray(), i, ref C, ref J);
                S(t[1].ToCharArray(), t[0].ToCharArray(), i, ref J, ref C);
            }
            catch (Exception e) { }
        }

        return C.ToString("D" + t[0].Length.ToString()) + " " + J.ToString("D" + t[0].Length.ToString());
    }
}