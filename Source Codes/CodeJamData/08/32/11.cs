using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader(@"..\..\input.txt");
        StreamWriter sw = new StreamWriter(@"..\..\output.txt");
        int N = int.Parse(sr.ReadLine());
        string[] lines = new string[N];
        for (int i = 0; i < N; i++)
        {
            lines[i] = sr.ReadLine();
            int Y = work(N, lines[i]);

            sw.WriteLine("Case #{0}: {1}", i + 1, Y);
        }
        sw.Close();
    }

    static string line;
    static int[] sign;
    private static int work(int N, string l)
    {
        line = l;
        sign = new int[line.Length - 1];
        return go(0);
    }

    private static int go(int idx)
    {
        if (idx == sign.Length)
        {
            int op = 1;
            long res = 0;
            long val = line[0] - '0';
            for (int i = 0; i < sign.Length; i++)
            {
                if (sign[i] == 0)
                {
                    val = 10 * val + line[i + 1] - '0';
                }
                else
                {
                    if (op == 1)
                        res += val;
                    else
                        res -= val;
                    op = sign[i];
                    val = line[i + 1] - '0';
                }
            }
            if (op == 1)
                res += val;
            else
                res -= val;

            return (res % 2 == 0 || res % 3 == 0 || res % 5 == 0 || res % 7 == 0) ? 1 : 0;
        }

        int ret = 0;
        for (int i = 0; i < 3; i++)
        {
            sign[idx] = i;
            ret += go(idx + 1);
        }
        return ret;
    }
}