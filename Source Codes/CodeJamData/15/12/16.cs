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
        var tmp = intSplit(' ');
        int b = tmp[0];
        int n = tmp[1];
        var num = intSplit(' ');
        long high = (long)1e16;
        long low = 0;
        while (high - low > 0)
        {
            long mid = (high & low) + ((high ^ low) >> 1);  //round down
            if (C(mid,b,n,num)) //mid or higher is true
                high = mid;
            else
                low = mid + 1;
        }//while
        long rank = n;
        var index = new List<int>();
        for(int i=0;i<b;i++)
        {
            long item = num[i];
            if (high%item==0)
            {
                index.Add(i+1);
            }//if
            rank-= (high + item - 1) / item;
        }//foreach item
        return index[(int)rank - 1].ToString();
    }

    private bool C(long mid, int b, int n, int[] num)
    {
        long sum = 0;
        foreach (var item in num)
        {
            sum += ((mid + 1) + item - 1) / item;
            if (sum>=n)
            {
                return true;
            }//if
        }//foreach item
        return sum >= n;
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