using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    StreamReader sr = new StreamReader(@"C:\Users\user1\Downloads\A-large.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\Documents\Visual Studio 2012\Projects\GCJ\GCJ\A.txt");


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
        int n = intRead();
        var num = intSplit(' ');
        int max = 0;
        int a = 0;
        for (int i = 0; i < num.Length-1; i++)
        {
            a += Math.Max(0, num[i] - num[i + 1]);
            max = Math.Max(max, Math.Max(0, num[i] - num[i + 1]));
        }//for i
        int b = 0;
        for (int i = 0; i < num.Length-1; i++)
        {
            b += Math.Min(num[i], max);
        }//for i
        return a + " " + b;
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