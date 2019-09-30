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



    static long F(long a, long b, long N)
    {
        Dictionary<long, long> d = new Dictionary<long, long>();

        Stack<long> s = new Stack<long>();
        s.Push(N);

        while (s.Count > 0)
        {
            long v = s.Peek();
            if (d.ContainsKey(v))
            {
                s.Pop();
                continue;
            }

            long left = (v - 1) / 2;
            long right = (v - 1 - left);

            if (left < a || right < b)
            {
                s.Pop();
                d.Add(v, 0);
                continue;
            }

            bool has = true;
            if (!d.ContainsKey(left))
            {
                has = false;
                s.Push(left);
            }
            if (!d.ContainsKey(right) && right != left)
            {
                has = false;
                s.Push(right);
            }
            if (has)
            {
                s.Pop();
                d.Add(v, 1 + d[left] + d[right]);
            }
        }
        return d[N];

    }


    static string Solution(StreamReader sr)
    {
        string[] t = sr.ReadLine().Split(' ');

        long N = long.Parse(t[0]);
        long K = long.Parse(t[1]);


        long l = 0, h = N;

        while (l < h)
        {
            long mid = (l + h + 1) / 2;
            if (F(mid, mid, N) >= K)
                l = mid;
            else
                h = mid - 1;
        }
        if (F(l, l + 1, N) >= K)
            return string.Format("{0} {1}", l + 1, l);
        return string.Format("{0} {1}", l, l);

    }
}