using System;
using System.Collections.Generic;

class Myon
{
    int input()
    {
        return int.Parse(Console.ReadLine());
    }

    int[] inputarray()
    {
        string[] s = Console.ReadLine().Split(' ');
        int[] ret = new int[s.Length];
        for (int i = 0; i < s.Length; i++) ret[i] = int.Parse(s[i]);
        return ret;
    }

    Myon() { }
    public static void Main()
    {
        new Myon().malti();
    }

    void malti()
    {
        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            
            Console.Write("Case #{0}:", lll);
            calc();
        }
    }

    void calc()
    {
        int n = input();
        string[] board = new string[n];
        double[] WP = new double[n];
        int[] win = new int[n];
        int[] lose = new int[n];
        double[] OWP = new double[n];
        double[] OOWP = new double[n];
        int i, j;
        for (i = 0; i < n; i++) board[i] = Console.ReadLine();
        for (i = 0; i < n; i++)
        {
            int count = 0;
            double sum = 0;
            for (j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    count++;
                    if (board[i][j] == '1') { sum += 1; win[i]++; }
                    else { lose[i]++; }
                }
            }
            WP[i] = sum / count;
        }
        for (i = 0; i < n; i++)
        {
            int count = 0;
            double sum = 0;
            for (j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    count++;
                    int num = lose[j] + win[j] - 1;
                    int w = win[j];
                    if (board[i][j] == '0')
                    {
                        w--;
                    }
                    sum += (double)w / num;
                }
            }
            OWP[i] = sum / count;
        }
        for (i = 0; i < n; i++)
        {
            int count = 0;
            double sum = 0;
            for (j = 0; j < n; j++)
            {
                if (board[i][j] != '.')
                {
                    count++;
                    sum += OWP[j];
                }
            }
            OOWP[i] = sum / count;
        }
        Console.WriteLine();
        for (i = 0; i < n; i++)
        {
            double score = WP[i] * 0.25 + OWP[i] * 0.5 + OOWP[i] * 0.25;
            Console.WriteLine(score);
        }
    }
}