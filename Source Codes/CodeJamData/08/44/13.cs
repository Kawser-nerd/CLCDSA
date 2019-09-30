using System;
using System.IO;

public class Round2D
{
    public int i, j, l, k, min, r, sum, w;
    int[] a = new int[100];
    bool[] b = new bool[100];
    string s;
    char[] c = new char[50000];
    
    void code()
    {
        w = 0;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < k; j++)
            {
                c[w] = s[i * k + a[j]];
                w++;
            }
        }
        sum = 1;
        for (i = 1; i < l; i++)
        {
            if (c[i] != c[i - 1])
            {
                sum++;
            }
        }
        min = Math.Min(min, sum);
    }

    void search(int p)
    {
        if (p == k)
        {
            code();
            return;
        }

        a[p] = 0;
        while (a[p] < k)
        {
            if (!b[a[p]])
            {
                b[a[p]] = true;
                search(p + 1);
                b[a[p]] = false;
            }
            a[p]++;
        }
    }

    static void Main(string[] args)
    {
        Round2D inst = new Round2D();
        int i, j, mode, n, t;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;

        sr = new StreamReader("D-small-attempt0.in");
        sw = File.CreateText("D-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            inst.k = Int32.Parse(line);

            line = sr.ReadLine();
            line = line.Trim();
            inst.s = line;
            inst.l = inst.s.Length;
            inst.min = int.MaxValue;
            inst.r = inst.l / inst.k;
            inst.search(0);
            sw.WriteLine("Case #{0}: {1}", mode + 1, inst.min);
        }
        sw.Close();
    }
}