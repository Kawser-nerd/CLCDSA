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
        string[] s = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
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
            Console.Write("Case #{0}: ", lll);
            calc();
        }
    }


    void calc()
    {
        int R, C;
        int[] ar = inputarray();
        int i, j;
        R = ar[0]; C = ar[1];
        int len = R * C;

        string[] s = new string[R];
        for (i = 0; i < R; i++) s[i] = Console.ReadLine();

        int[,] sum = new int[R, C];
        bool[,] moved = new bool[R, C];
        bool[,] check = new bool[R, C];
        bool flag = true;
        Queue<int> q = new Queue<int>();

        long res = 1;
        long mod = 1000003;

        for (i = 0; i < R; i++)
        {
            for (j = 0; j < C; j++)
            {
                char c = s[i][j];
                if (c == '|')
                {
                    sum[(i + 1) % R, (j) % C]++;
                    sum[(i + R - 1) % R, (j) % C]++;

                }
                else if (c == '-')
                {
                    sum[(i) % R, (j + 1) % C]++;
                    sum[(i) % R, (j + C - 1) % C]++;
                }
                else if (c == '/')
                {
                    sum[(i + 1) % R, (j + C - 1) % C]++;
                    sum[(i + R - 1) % R, (j + 1) % C]++;
                }
                else
                {
                    sum[(i + 1) % R, (j + 1) % C]++;
                    sum[(i + R - 1) % R, (j + C - 1) % C]++;
                }
            }
        }

        while (flag)
        {
            for (i = 0; i < R; i++)
            {
                for (j = 0; j < C; j++)
                {
                    if (!check[i, j] && sum[i, j] == 1)
                    {
                        q.Enqueue(i * C + j);
                        check[i, j] = true;
                    }
                    else if (sum[i, j] == 0) { Console.WriteLine(0); return; }
                }
            }
            while (q.Count != 0)
            {
                int now = q.Dequeue();
                int ii = now / C;
                int jj = now % C;
                bool f = false;
                for (int vi = -1; vi <= 1; vi++)
                {
                    for (int vj = -1; vj <= 1; vj++)
                    {
                        if (f) break;
                        if (vi == 0 && vj == 0) continue;
                        i = (ii + vi + R) % R;
                        j = (jj + vj + C) % C;
                        if (moved[i, j]) continue;
                        char c = s[i][j];
                        if (c == '|')
                        {
                            if ((i + 1) % R == ii && (j) % C == jj)
                            {
                                sum[(i + R - 1) % R, (j) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                            else if ((i + R - 1) % R == ii && (j) % C == jj)
                            {
                                sum[(i + 1) % R, (j) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }

                        }
                        else if (c == '-')
                        {
                            if ((i) % R == ii && (j + 1) % C == jj)
                            {
                                sum[(i) % R, (j + C - 1) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                            else if ((i) % R == ii && (j + C - 1) % C == jj)
                            {
                                sum[(i) % R, (j + 1) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                        }
                        else if (c == '/')
                        {
                            if ((i + 1) % R == ii && (j + C - 1) % C == jj)
                            {
                                sum[(i + R - 1) % R, (j + 1) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                            if ((i + R - 1) % R == ii && (j + 1) % C == jj)
                            {
                                sum[(i + 1) % R, (j + C - 1) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                        }
                        else
                        {
                            if ((i + 1) % R == ii && (j + 1) % C == jj)
                            {
                                sum[(i + R - 1) % R, (j + C - 1) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                            if ((i + R - 1) % R == ii && (j + C - 1) % C == jj)
                            {
                                sum[(i + 1) % R, (j + 1) % C]--;
                                moved[i, j] = true;
                                f = true;
                            }
                        }
                        if (f)
                        {
                            for (int vvi = -1; vvi <= 1; vvi++)
                            {
                                for (int vvj = -1; vvj <= 1; vvj++)
                                {
                                    int ni = (i + vvi + R) % R;
                                    int nj = (j + vvj + C) % C;
                                    if (!check[ni, nj] && sum[ni, nj] == 1)
                                    {
                                        check[ni, nj] = true;
                                        q.Enqueue(ni * C + nj);
                                    }
                                    else if (sum[ni, nj] == 0)
                                    {
                                        Console.WriteLine(0);
                                        return;
                                    }
                                }
                            }
                            break;
                        }

                    }
                    if (f) break;
                }
                if (!flag)
                {
                    Console.Error.WriteLine("??");
                }
            }

            flag = false;
            for (i = 0; i < R; i++)
            {
                for (j = 0; j < C; j++)
                {
                    if (!moved[i, j])
                    {
                        moved[i, j] = true;
                        res *= 2;
                        res %= mod;
                        flag = true;

                        char c = s[i][j];
                        if (c == '|')
                        {
                            sum[(i + 1) % R, (j) % C]--;

                        }
                        else if (c == '-')
                        {
                            sum[(i) % R, (j + 1) % C]--;
                        }
                        else if (c == '/')
                        {
                            sum[(i + 1) % R, (j + C - 1) % C]--;
                        }
                        else
                        {
                            sum[(i + 1) % R, (j + 1) % C]--;
                        }
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
        }
        
        
        Console.WriteLine(res);

        
    }

}