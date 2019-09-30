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
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ":");
            Solution(sr, sw);
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }



    static void Solution(StreamReader sr, StreamWriter sw)
    {
        int N = int.Parse(sr.ReadLine());

        int[] x = new int[N];
        int[] y = new int[N];

        for (int i = 0; i < N; i++)
        {
            string[] t = sr.ReadLine().Split(' ');
            x[i] = int.Parse(t[0]);
            y[i] = int.Parse(t[1]);
        }

        for (int i = 0; i < N; i++)
        {
            List<double> d = new List<double>();
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    double v = Math.Atan2(y[j] - y[i], x[j] - x[i]);
                    d.Add(v);
                    if (v < 0)
                        d.Add(v + Math.PI * 2);
                }
            }
            d.Sort();

            int min = 33000;
            for (int j = 0; j < d.Count; j++)
            {
                if (d[j] < Math.PI + 1e-10)
                {
                    int e = d.BinarySearch(d[j] + Math.PI - 1e-10);
                    if (e < 0)
                        e = ~e;
                    min = Math.Min(min, e - j);
                }
            }
            if (min == 33000)
                min = 1;
            sw.WriteLine(min - 1);
        }

    }
}