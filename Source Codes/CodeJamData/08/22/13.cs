using System;
using System.IO;

public class Round1BB
{
    static void Main(string[] args)
    {
        int a, b, i, j, k, mode, max, p, sum, t, z1, z2;
        StreamReader sr;
        StreamWriter sw;
        bool flag, flag2;
        string line;
        string[] ss;
        int[] group;
        bool[] f;

        sr = new StreamReader("B-small-attempt0.in");
        sw = File.CreateText("B-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);

        max = 1000;
        f = new bool[max + 1];
        group = new int[max + 1];
        i = 1;
        while (i < max)
        {
            i++;
            if (!f[i])
            {
                j = i + i;
                while (j <= max)
                {
                    f[j] = true;
                    j += i;
                }
            }
        }

        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            ss = line.Split(' ');
            a = Int32.Parse(ss[0]);
            b = Int32.Parse(ss[1]);
            p = Int32.Parse(ss[2]);

            for (i = a; i <= b; i++)
            {
                group[i] = i;
            }
            flag = true;
            sum = b - a + 1;
            while (flag)
            {
                flag = false;
                for (i = a; i < b; i++)
                {
                    for (j = i + 1; j <= b; j++)
                    {
                        if (group[i] != group[j])
                        {
                            flag2 = false;
                            for (k = p; k <= i; k++)
                            {
                                if (i % k == 0 && j % k == 0 && !f[k])
                                {
                                    flag2 = true;
                                    break;
                                }
                            }
                            if (flag2)
                            {
                                z1 = Math.Min(group[i], group[j]);
                                z2 = Math.Max(group[i], group[j]);
                                sum--;
                                flag = true;
                                for (k = a; k <= b; k++)
                                {
                                    if (group[k] == z2)
                                    {
                                        group[k] = z1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            sw.WriteLine("Case #{0}: {1}", mode + 1, sum);
        }
        sw.Close();
    }
}