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
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\DownLoads\AAA.txt");

    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            sw.WriteLine("Case #{0}: {1}", i + 1, res);
        }//for i
        sw.Close();
        sr.Close();
    }

    private string Solve()
    {
        long[] tmp = longSplit(' ');
        long r = tmp[0];
        long t = tmp[1];
        long high = int.MaxValue; //be careful OutOfRange
        long low = 0;
        while (high - low > 0)
        {
            long mid = (high & low) + ((high ^ low) + 1 >> 1);  //round up
            if (C(mid,r,t)) //mid or lower is true
                low = mid;
            else
                high = mid - 1;
        }//while
        return low.ToString();    //low = high
    }

    private bool C(BigInteger k, BigInteger r, BigInteger t)
    {
        BigInteger cur = 2 * r * k - 3 * k + 2 * k * (k + 1);
        return cur <= t;
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