using System;
using System.Collections.Generic;
using System.IO;


public class QualC
{
    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;

        si = new StreamReader("C-large.in");
        sw = new StreamWriter("C-large.out");
        string pattern = "welcome to code jam";

        int i, j, k, l, n, total;
        int[,] sum = new int[500, 19];

        line = si.ReadLine().Trim();

        n = Int32.Parse(line);

        for (i = 0; i < n; i++)
        {
            line = si.ReadLine().Trim();
            for (j = 0; j < line.Length; j++)
            {
                for (k = 0; k < 19; k++)
                {
                    sum[j, k] = 0;
                }
            }
            for (j = 0; j < line.Length; j++)
            {
                for (k = 0; k < 19; k++)
                {
                    if (line[j] == pattern[k] && j >= k)
                    {
                        if (k == 0)
                        {
                            sum[j, k] = 1;
                        }
                        else
                        {
                            for (l = k - 1; l < j; l++)
                            {
                                sum[j, k] = (sum[j, k] + sum[l, k - 1]) % 10000;
                            }
                        }
                    }
                }
            }
            total = 0;
            for (j = 0; j < line.Length; j++)
            {
                total = (total + sum[j, 18]) % 10000;
            }
            sw.WriteLine("Case #{0}: {1}", i + 1, string.Format("{0:D4}", total));
        }
        sw.Close();
    }
}