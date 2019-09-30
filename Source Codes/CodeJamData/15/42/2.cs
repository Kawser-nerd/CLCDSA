using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Linq;
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
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }




    class G : IComparable<G>
    {
        public decimal p, R, C;

        public G(StreamReader sr)
        {
            string[] tmp = sr.ReadLine().Split(' ');
            R = decimal.Parse(tmp[0]);
            C = decimal.Parse(tmp[1]);
            p = 1;
        }

        public int CompareTo(G other)
        {
            return this.C.CompareTo(other.C);
        }
    }


    static decimal temp(List<G> m)
    {
        decimal rate = 0;
        decimal rt = 0;
        foreach (var item in m)
        {
            rate += item.p * item.R;
            rt += item.p * item.R * item.C;
        }
        if (rate == 0)
            return (decimal)(-100);
        return rt / rate;
    }

    static decimal eps = ((decimal)1e-10) * ((decimal)1e-10);

    static string BS(List<G> m, int pos, decimal X, decimal V, bool tohot)
    {
        if (m.Count == 1)
            return "IMPOSSIBLE";
        decimal l, h;
        l = 0; h = 1;
        while (l + eps < h)
        {
            decimal u = (l + h) / 2;
            m[pos].p = u;
            if (temp(m) < X == tohot)
                l = u;
            else
                h = u;
        }


        decimal rate = 0;
        foreach (var item in m)
        {
            rate += item.p * item.R;
        }
        return string.Format("{0:0.000000000}", V / rate);
    }


    static string Solution(StreamReader sr)
    {
        string[] tmp = sr.ReadLine().Split(' ');
        int N = int.Parse(tmp[0]);
        decimal V = decimal.Parse(tmp[1]);
        decimal X = decimal.Parse(tmp[2]);

        List<G> m = new List<G>();

        for (int i = 0; i < N; i++)
        {
            m.Add(new G(sr));
        }
        m.Sort();


        while (m.Count() > 0)
        {
            decimal t = temp(m);
            if (t - eps > X)
            {
                m[m.Count - 1].p = 0;
                if (temp(m) + eps > X)
                {
                    m.RemoveAt(m.Count - 1);
                    continue;
                }
                else
                    return BS(m, m.Count - 1, X, V, true);
            }
            else if (t + eps < X)
            {
                m[0].p = 0;
                if (temp(m) - eps < X)
                {
                    m.RemoveAt(0);
                    continue;
                }
                else
                    return BS(m, 0, X, V, false);
            }
            else
            {
                decimal rate = 0;
                foreach (var item in m)
                {
                    rate += item.p * item.R;
                }
                return string.Format("{0:0.000000000}",V / rate);
            }
        }



        return "IMPOSSIBLE";
    }
}