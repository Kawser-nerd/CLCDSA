using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Prog
{
    public Prog() { }
    public static int Main()
    {
        new Prog().calc();
        return 0;
    }

    Scanner cin;

    public void calc()
    {
        cin = new Scanner();
        int H = cin.nextInt();
        int W = cin.nextInt();

        string[] S = new string[H];

        for (int i = 0; i < H; i++)
        {
            S[i] = cin.next();
        }

        char[,] ret = new char[H, W];

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                bool flg = true;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (0 <= i + r && i + r < H && 0 <= j + c && j + c < W)
                        {
                            if (S[i + r][j + c] == '.')
                            {
                                flg = false;
                                goto nuke;
                            }
                        }
                    }
                }
                nuke:

                ret[i, j] = flg ? '#' : '.';
            }
        }

        char[,] back = new char[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                char p = ret[i, j] == '#' ? '#' : '.';
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (0 <= i + r && i + r < H && 0 <= j + c && j + c < W)
                        {
                            back[i + r, j + c] = back[i + r, j + c] == '#' ? '#' : p;
                        }
                    }
                }
            }
        }

        bool flg2 = true;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (S[i][j] != back[i, j])
                {
                    flg2 = false;
                    goto nuke2;
                }
            }
        }

        nuke2:
        if (flg2)
        {
            Console.WriteLine("possible");
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Console.Write(ret[i, j].ToString());
                }
                Console.WriteLine();
            }
        }
        else { Console.WriteLine("impossible"); }
        Console.Read();

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
        return s[i++];
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