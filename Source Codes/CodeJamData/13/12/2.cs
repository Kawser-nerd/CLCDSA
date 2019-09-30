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
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\DownLoads\BBB.txt");

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
        long E = tmp[0];
        long R = tmp[1];
        R = Math.Min(R, E);
        int N = (int)tmp[2];
        tmp = longSplit(' ');
        BigInteger[] v = new BigInteger[N];
        for (int i = 0; i < N; i++)
            v[i]  = tmp[i];
        BigInteger power = 0;
        BigInteger res = 0;
        for (int i = 0; i < N; i++)
        {
            power += (i == 0 ? E : R);
            power =BigInteger.Min(power, E);
            int next = -1;
            for (int j = i+1; j < N; j++)
            {
                if (v[i] <= v[j])
                {
                    next = j;
                    break;
                }
            }//for j
            if (next == -1)
            {
                res += power * v[i];
                power = 0;
            }
            else
            {
                BigInteger gain = (next - i) * R;
                BigInteger can =BigInteger.Min(power, BigInteger.Max(0,power + gain - E));
                res += can * v[i];
                power -= can;
            }//else
        }//for i
        return res.ToString();
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