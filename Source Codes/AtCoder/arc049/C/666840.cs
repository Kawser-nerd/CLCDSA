using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;

class Myon
{

    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }

    Scanner cin;

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int A = cin.nextInt();
        int[] x = new int[A];
        int[] y = new int[A];
        for (int i = 0; i < A; i++)
        {
            x[i] = cin.nextInt() - 1;
            y[i] = cin.nextInt() - 1;
        }
        
        int B = cin.nextInt();
        int[] u = new int[B];
        int[] v = new int[B];
        for (int i = 0; i < B; i++)
        {
            u[i] = cin.nextInt() - 1;
            v[i] = cin.nextInt() - 1;
        }

        int ans = 0;

        for (int i = 0; i < (1 << B); i++)
        {
            List<int>[] l = new List<int>[N];
            for (int j = 0; j < N; j++)
            {
                l[j] = new List<int>();
            }

            for (int j = 0; j < A; j++)
            {
                l[x[j]].Add(y[j]);
            }
            bool[] nuranai = new bool[N];
            for (int j = 0; j < B; j++)
            {
                if ((i >> j) % 2 == 0)
                {
                    //???????
                    nuranai[u[j]] = true;
                }
                else
                {
                    //??U???
                    l[v[j]].Add(u[j]);
                }
            }
            bool[] check = new bool[N];
            int temp = 0;
            bool loopflag;
            do
            {
                loopflag = false;
                for (int j = 0; j < N; j++)
                {
                    if (nuranai[j]) continue;
                    if (check[j]) continue;
                    bool nureru = true;
                    foreach (var to in l[j])
                    {
                        if (!check[to])
                        {
                            nureru = false;
                            break;
                        }
                    }
                    if (nureru)
                    {
                        check[j] = true;
                        temp++;
                        loopflag = true;
                    }
                }

            } while (loopflag);
            ans = Math.Max(ans, temp);
        }

        Console.WriteLine(ans);
    }

}
class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return next();
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}