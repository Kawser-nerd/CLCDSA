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

    StreamReader sr = new StreamReader(@"C:\Users\user1\Downloads\B-large.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\Documents\Visual Studio 2012\Projects\GCJ\GCJ\B.txt");

    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            //sw.WriteLine("Case #1:\n");
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    private string Solve()
    {
        long[] tmp = longSplit(' ');
        int  n =(int) tmp[0];
        long p = tmp[1];
        long win = Win(n, p);
        long lose = Lose(n, p);
        return lose + " " + win;
    }

    private long Lose(int n, long p)
    {
        long all = 1L << n;
        long high = all-1; //be careful OutOfRange
        long low = 0;
        while (high - low > 0)
        {
            long mid = (high & low) + ((high ^ low) + 1 >> 1);  //round up
            if (CLose(mid,n,p)) //mid or lower is true
                low = mid;
            else
                high = mid - 1;
        }//while
        return low;    //low = high
    }

    private bool CLose(long mid,int n,long p)
    {
        long all = 1L << n;
        long x = mid;
        long y = all - x - 1;
        long sum = 0;
        while (x>0)
        {
            all >>= 1;
            sum += all;
            x = (x - 1) / 2;
            y = (y + 1) / 2;
        }//while
        return p > sum;
    }

    private long Win(int n, long p)
    {
        long all = 1L << n;
        long high = all-1; //be careful OutOfRange
        long low = 0;
        while (high - low > 0)
        {
            long mid = (high & low) + ((high ^ low) + 1 >> 1);  //round up
            if (CWin(mid,n,p)) //mid or lower is true
                low = mid;
            else
                high = mid - 1;
        }//while
        return low;    //low = high
    }

    private bool CWin(long mid, int n, long p)
    {
        long all = 1L << n;
        long x = mid;
        long y = all - x - 1;
        while (y>0)
        {
            x = (x + 1) / 2;
            y = (y - 1) / 2;
        }//while
        return p > x;
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