using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    const string inputName = @"A-small-attempt0.in";
    StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\" + inputName);
    StreamWriter sw = new StreamWriter(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\A.txt");

    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    private string Solve()
    {
        var split = longSplit('/');
        BigInteger P = split[0];
        BigInteger Q = split[1];
        BigInteger cur = 1;
        BigInteger big = BigInteger.Pow(2, 40);
        for (int i = 0; i <= 40; i++)
        {
            BigInteger num = P * cur - Q;
            BigInteger den = Q * cur;
            if (num>=0)
            {
                if (num==0)
                {
                    return i.ToString();
                }//if
                BigInteger gcd = BigInteger.GreatestCommonDivisor(num, den);
                num /= gcd;
                den /= gcd;
                if (big % Q == 0)
                {
                    return i.ToString();
                }//if
            }//if
            cur *= 2;
        }//for i
        return "impossible";
    }


    void Write(string str)
    {
        Console.WriteLine(str);
        sw.WriteLine(str);
    }

    string strRead()
    {
        return sr.ReadLine();
    }

    int intRead()
    {
        return int.Parse(sr.ReadLine());
    }

    long longRead()
    {
        return long.Parse(sr.ReadLine());
    }

    double doubleRead()
    {
        return double.Parse(sr.ReadLine());
    }

    string[] strSplit(char c)
    {
        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
    }

    int[] intSplit(char c)
    {
        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
    }

    long[] longSplit(char r)
    {
        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
    }

    double[] doubleSplit(char c)
    {
        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
    }

}//ClassName