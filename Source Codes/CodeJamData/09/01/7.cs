using System;
using System.Collections.Generic;
using System.IO;


public class QualA
{
    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;

        si = new StreamReader("A-large.in");
        sw = new StreamWriter("A-large.out");

        int d, i, j, k, l, n, sum, w;
        bool flag;
        string[] ss;
        string[] word = new string[5000];
        string[] pattern = new string[15];

        line = si.ReadLine().Trim();
        ss = line.Split(' ');

        l = Int32.Parse(ss[0]);
        d = Int32.Parse(ss[1]);
        n = Int32.Parse(ss[2]);

        for (i = 0; i < d; i++)
        {
            word[i] = si.ReadLine().Trim();
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < l; j++)
            {
                pattern[j] = "";
            }
            line = si.ReadLine().Trim();
            flag = true;
            w = 0;
            for (j = 0; j < line.Length; j++)
            {
                if (line[j] == '(')
                {
                    flag = false;
                }
                else if (line[j] == ')')
                {
                    flag = true;
                    w++;
                }
                else
                {
                    pattern[w] += line[j];
                    if (flag)
                    {
                        w++;
                    }
                }
            }
            sum = 0;
            for (j = 0; j < d; j++)
            {
                flag = true;
                for (k = 0; k < l; k++)
                {
                    if (pattern[k].IndexOf(word[j][k]) < 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag) sum++;
            }
            sw.WriteLine("Case #{0}: {1}", i + 1, sum);
        }
        sw.Close();
    }
}