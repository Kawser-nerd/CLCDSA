using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Numerics;
using System.Linq;


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

        char[] c = sr.ReadLine().ToCharArray();


        int g = -1;
        for (int i = 1; i < c.Length; i++)
        {
            if (c[i] < c[i - 1])
            {
                g = i - 1;
                break;
            }
        }
        if (g == -1)
        {
            string x = "";
            foreach (var item in c)
            {
                x += item;
            }
            return x;
        }

        if (c[g] == '1')
        {
            string x = "";
            for (int i = 0; i < c.Length - 1; i++)
            {
                x += "9";
            }
            return x;
        }

        c[g]--;
        while (g > 0 && c[g - 1] > c[g]) { g--; c[g]--; }

        for (int i = g + 1; i < c.Length; i++)
        {
            c[i] = '9';
        }
        {
            string x = "";
            foreach (var item in c)
            {
                x += item;
            }
            return x;
        }

    }
}