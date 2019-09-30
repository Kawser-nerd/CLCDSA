// ARC 006 C ????

using System;
using System.Collections.Generic;

class Program
{
    static int N;
    static List<int> w;

    static void Main()
    {
        /* ??????? */
        N = int.Parse(Console.ReadLine());
        w = new List<int>();
        for (int i = 0; i < N; i++)
            w.Add(int.Parse(Console.ReadLine()));

        /* ????????????????????Top????????? */
        List<int> Top = new List<int>();
        foreach (var wi in w)
        {
            for (int i = 0; i < Top.Count; i++)
            {
                if (Top[i] >= wi)
                {
                    Top[i] = wi;
                    goto END;
                }
            }
            Top.Add(wi);
            END:;
            Top.Sort();
        }

        /* ????? */
        Console.WriteLine(Top.Count);
    }
}