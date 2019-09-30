using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyonAAA
{
    StreamReader sr;
    StreamWriter sw;

    static void Main()
    {
        new MyonAAA().EntryAAA();
    }


    void SolveAAA()
    {
        int len = intRead();
        long[] a = new long[len];
        long[] d = new long[len];
        for (int i = 0; i < len; i++)
        {
            int[] array = Array.ConvertAll<string, int>(stringRead().ToString().Split(' '), int.Parse);
            d[i] = array[0];
            a[i] = array[1];
        }//for i
        long D = longRead();

        long[] dp = new long[len];
        for (int i = 0; i < len; i++)
        {
            dp[i] = -1;
        }//fore i
        dp[0] = d[0];
        bool flg = false;
        for (int i = 0; i < len; i++)
        {
            if (d[i] + dp[i] >= D)
            {
                flg = true;
                break;
            }
            if(dp[i] <=0)
                continue;
            for (int j = i+1; j < len; j++)
            {
                if (d[i] + dp[i] < d[j])
                    break;
                dp[j] = Math.Max(dp[j], Math.Min(d[j] - d[i], a[j]));
            }//for j
        }//for i

        WriteLine((flg?"YES":"NO"));
    }


    void EntryAAA()
    {
        sr = new StreamReader(@"C:\Users\user1\Downloads\A-large.in");
        sw = new StreamWriter(@"C:\Users\user1\Downloads\WriteAAA.txt");

        int rep = intRead();
        for (int i = 0; i < rep; i++)
        {
            sw.Write("Case #{0}: ", i + 1);
            Console.Write("Case #{0}: ", i + 1);
            SolveAAA();
        }//for i

        sw.Close();
        sr.Close();
    }

    string stringRead()
    { return sr.ReadLine(); }

    int intRead()
    { return int.Parse(sr.ReadLine()); }

    long longRead()
    { return long.Parse(sr.ReadLine()); }

    string[] stringSplit(char a)
    { return sr.ReadLine().Split(a); }

    int[] intSplit(char a)
    { return Array.ConvertAll<string, int>(sr.ReadLine().Split(a), int.Parse); }

    long[] longSplit(char a)
    { return Array.ConvertAll<string, long>(sr.ReadLine().Split(a), long.Parse); }

    void WriteLine<T>(T str)
    {
        Console.WriteLine(str.ToString());
        sw.WriteLine(str.ToString());
    }

}