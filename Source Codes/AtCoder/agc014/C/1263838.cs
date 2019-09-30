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

    int H, W, K;

    void calc()
    {
        cin = new Scanner();
        H = cin.nextInt();
        W = cin.nextInt();
        K = cin.nextInt();
        string[] board = new string[H];
        for (int i = 0; i < H; i++)
        {
            board[i] = cin.next();
        }

        int fy = -1;
        int fx = -1;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if(board[i][j] == 'S')
                {
                    fy = i;
                    fx = j;
                }
            }
        }

        int[,] dist = new int[H, W];
        int MAX = 99999999;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                dist[i, j] = MAX;
            }
        }

        int[] vy = { 1, 0, -1, 0 };
        int[] vx = { 0, 1, 0, -1 }; 
        Queue<Tuple<int, int>> q = new Queue<Tuple<int, int>>();
        dist[fy, fx] = 0;
        q.Enqueue(Tuple.Create(fy, fx));
        while (q.Count > 0)
        {
            var now = q.Dequeue();
            int y = now.Item1;
            int x = now.Item2;
            for (int k = 0; k < vy.Length; k++)
            {
                int ny = y + vy[k];
                int nx = x + vx[k];
                if (!inside(ny, nx)) continue;
                if (dist[ny, nx] != MAX) continue;
                if (board[ny][nx] == '#') continue;

                dist[ny, nx] = dist[y, x] + 1;

                q.Enqueue(Tuple.Create(ny, nx));
            }
        }

        int ans = MAX;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                int mindist = MAX;
                mindist = Math.Min(mindist, i);
                mindist = Math.Min(mindist, j);
                mindist = Math.Min(mindist, H - 1 - i);
                mindist = Math.Min(mindist, W - 1 - j);
                int first = (dist[i, j] + K - 1) / K;
                if (first == 0) first = 1;
                int second = (mindist + (K - 1)) / K;
                ans = Math.Min(ans, first+ second);
            }
        }
        Console.WriteLine(ans);
    }

    bool inside(int y, int x)
    {
        return y >= 0 && x >= 0 && y < H && x < W;
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