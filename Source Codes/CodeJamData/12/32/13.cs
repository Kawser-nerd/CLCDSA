using System;
using System.Collections.Generic;
using System.Text;
using System.Globalization;
using System.Threading;

class B
{
    static double go(double D, double a, double[][] G)
    {
        double v = 0;
        double t = 0;
        double s = 0;
        for (int i = 0; i < G.Length-1; i++)
        {
            double t1 = G[i][0];
            double s1 = G[i][1];
            if(s1 >= D)
                break;
            double t2 = G[i+1][0];
            double s2 = G[i+1][1];
            double td = t2-t1;
            double sd = s2-s1;
            double v1 = sd / td;
            if (s2 > D)
            {
                s2 = D;
                sd = s2 - s1;
                t2 = t1 + sd / v1;
                td = t2 - t1;
            }
            double Disc = Math.Pow(2 * v - 2 * v1, 2) - 4 * a * (2 * s - 2 * s1);
            double tt1 = (-(2*v-2*v1) + Math.Sqrt(Disc)) / (2*a);
            double tt2 = (-(2*v-2*v1) - Math.Sqrt(Disc)) / (2*a);
            double tt = Math.Max(tt1, tt2);
            if (t1 + tt <= t2) // they will meet
            {
                v = v1;
                t = t2;
                s = s2;
            }
            else // they wont meet
            {
                v += a * td;
                t += td;
                s += 0.5 * a * Math.Pow(td, 2);
            }
        }
        if (s < D)
        {
            double Disc = Math.Pow(2 * v, 2) - 4 * a * (2 * s - 2 * D);
            double tt1 = (-(2 * v) + Math.Sqrt(Disc)) / (2 * a);
            double tt2 = (-(2 * v) - Math.Sqrt(Disc)) / (2 * a);
            double tt = Math.Max(tt1, tt2);
            t += tt;
        }
        return t;
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            string[] tokens = ReadWords();
            double D = double.Parse(tokens[0]);
            int N = int.Parse(tokens[1]);
            double[][] G = new double[N][];
            for (int i = 0; i < N; i++)
            {
                G[i] = ReadDoubles();
            }
            double[] A = ReadDoubles();
            Console.WriteLine("Case #{0}:", t);
            foreach (double a in A)
            {
                Console.WriteLine("{0}", go(D, a, G));
            }
        }
    }

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static long ReadLong()
    {
        return long.Parse(ReadLine());
    }

    static double ReadDouble()
    {
        return double.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static long[] ReadLongs()
    {
        return Array.ConvertAll(ReadWords(), long.Parse);
    }

    static double[] ReadDoubles()
    {
        return Array.ConvertAll(ReadWords(), double.Parse);
    }
	
	static void WriteList<T>(List<T> col)
    {
        int count = col.Count;
        for (int i = 0; i < count - 1; i++)
            Console.Write(col[i] + " ");
        Console.WriteLine(col[count - 1]);
    }

    static void WriteArray<T>(T[] col)
    {
        int count = col.Length;
        for (int i = 0; i < count - 1; i++)
            Console.Write(col[i] + " ");
        Console.WriteLine(col[count - 1]);
    }
}
