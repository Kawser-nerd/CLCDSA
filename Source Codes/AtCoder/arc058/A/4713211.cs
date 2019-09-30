using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N, K;
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        K = int.Parse(str[1]);
        str = Console.ReadLine().Split(' ');
        char[] p = new char[str.Length];
        for (int i = 0; i < str.Length; i++)
            p[i] = str[i][0];
        for (int i = N; ; i++)
        {
            string d = i.ToString();
            bool t = true;
            for(int j = 0; j < d.Length; j++)
            {
                for (int k = 0;k < p.Length; k++)
                {
                    if (d[j]==p[k])
                    {
                        t = false;
                        break;
                    }
                }
                if (!t)
                    break;
            }
            if (t)
            {
                Console.WriteLine(i);
                break;
            }
        }
    }
}