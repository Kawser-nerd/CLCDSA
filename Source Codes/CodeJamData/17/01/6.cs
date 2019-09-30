using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Numerics;



class Program
{

    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("D:\\in.in");
        StreamWriter sw = new StreamWriter("D:\\out.out");

        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }




    static string Solution(StreamReader sr)
    {
        string[] t = sr.ReadLine().Split(' ');

        char[] c = t[0].ToCharArray();
        int K = int.Parse(t[1]);

        int r = 0;

        for (int i = 0; i < c.Length - K + 1; i++)
        {
            if (c[i] == '-')
            {
                r++;
                for (int j = 0; j < K; j++)
                {
                    if (c[i + j] == '-')
                        c[i + j] = '+';
                    else
                        c[i + j] = '-';
                }
            }
        }
        bool good = true;
        for (int i = c.Length - K + 1; i < c.Length; i++)
        {
            if (c[i] != '+')
                good = false;
        }
        if (!good)
            return "IMPOSSIBLE";
        return r.ToString();
    }
}