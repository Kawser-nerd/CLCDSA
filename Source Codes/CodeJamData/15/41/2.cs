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
        string[] tmp = sr.ReadLine().Split(' ');
        int R = int.Parse(tmp[0]);
        int C = int.Parse(tmp[1]);

        int[] miR = new int[R];
        int[] maR = new int[R];
        int[] miC = new int[C];
        int[] maC = new int[C];

        for (int i = 0; i < R; i++)
        {
            miR[i] = 1000;
            maR[i] = -1;
        } for (int i = 0; i < C; i++)
        {
            miC[i] = 1000;
            maC[i] = -1;
        }

        string[] d = new string[R];

        for (int i = 0; i < R; i++)
        {
            d[i] = sr.ReadLine();
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (d[i][j] != '.')
                {
                    miR[i] = Math.Min(miR[i], j);
                    maR[i] = Math.Max(maR[i], j);
                    miC[j] = Math.Min(miC[j], i);
                    maC[j] = Math.Max(maC[j], i);
                }
            }
        }

        int r = 0;

        Func<int, int, bool> ch = (i, j) =>
        {
            return miR[i] < j || maR[i] > j || miC[j] < i || maC[j] > i;
        };


        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (d[i][j] != '.')
                {
                    if (d[i][j] == '>' && maR[i] == j)
                    {
                        if (ch(i, j))
                            r++;
                        else
                            return "IMPOSSIBLE";
                    }
                    if (d[i][j] == '<' && miR[i] == j)
                    {
                        if (ch(i, j))
                            r++;
                        else
                            return "IMPOSSIBLE";
                    }
                    if (d[i][j] == '^' && miC[j] == i)
                    {
                        if (ch(i, j))
                            r++;
                        else
                            return "IMPOSSIBLE";
                    }
                    if (d[i][j] == 'v' && maC[j] == i)
                    {
                        if (ch(i, j))
                            r++;
                        else
                            return "IMPOSSIBLE";
                    }
                }
            }
        }

        return r.ToString();
    }
}