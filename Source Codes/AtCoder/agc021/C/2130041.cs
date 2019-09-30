using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }


    Scanner cin;

    char[,] ans;
    string retS = "<>^v";

    void calc()
    {
        cin = new Scanner();

        int H = cin.nextInt();
        int W = cin.nextInt();
        int A = cin.nextInt(); //yoko
        int B = cin.nextInt(); //tate
        ans = new char[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                ans[i, j] = '.';
            }
        }

        if(H % 2 == 1)
        {
            for (int i = W % 2; i < W - 1; i += 2)
            {
                if(A >= 1)
                {
                    A--;
                    ans[0, i] = retS[0];
                    ans[0, i + 1] = retS[1];
                }
            }
        }
        if (W % 2 == 1)
        {
            for (int i = H % 2; i < H - 1; i += 2)
            {
                if (B >= 1)
                {
                    B--;
                    ans[i, 0] = retS[2];
                    ans[i + 1, 0] = retS[3];
                }
            }
        }

        for (int i = H - 2; i >= 0; i-= 2)
        {
            for (int j = W - 2; j >= 0; j -= 2)
            {
                if (A >= 2)
                {
                    A -= 2;
                    ans[i, j] = retS[0];
                    ans[i, j + 1] = retS[1];
                    ans[i + 1, j] = retS[0];
                    ans[i + 1, j + 1] = retS[1];
                }
                else if(B >= 2)
                {
                    B -= 2;
                    ans[i, j] = retS[2];
                    ans[i, j + 1] = retS[2];
                    ans[i + 1, j] = retS[3];
                    ans[i + 1, j + 1] = retS[3];
                }
                else if(i == 1 && j == 1 && A >= 1 && B >= 1)
                {
                    A--;
                    B--;
                    ans[0, 0] = ans[1, 0];
                    ans[1, 0] = ans[2, 0];
                    ans[2, 0] = '<';
                    ans[2, 1] = '>';
                    ans[1, 2] = '^';
                    ans[2, 2] = 'v';
                }
                else if(A == 1)
                {
                    A -= 1;
                    ans[i, j] = retS[0];
                    ans[i, j + 1] = retS[1];
                }
                else if(B == 1)
                {
                    B -= 1;
                    ans[i, j] = retS[2];
                    ans[i + 1, j] = retS[3];
                }
            }
        }
        if(A > 0 || B > 0)
        {
            Console.WriteLine("NO");
            return;
        }

        Console.WriteLine("YES");
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                Console.Write(ans[i,j]);
            }
            Console.WriteLine();
        }
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}