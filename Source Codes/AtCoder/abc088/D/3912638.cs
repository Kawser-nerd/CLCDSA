using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
    

    Scanner cin;

    int H, W;
    string[] board;

    void calc()
    {
        cin = new Scanner();
        H = cin.nextInt();
        W = cin.nextInt();
        board = new string[H];
        for (int i = 0; i < H; i++)
        {
            board[i] = cin.next();
        }

        int[] vy = { 1, 0, -1, 0 };
        int[] vx = { 0, 1, 0, -1 };

        int fy = 0;
        int fx = 0;

        int[,] dist = new int[H, W];
        Queue<Tuple<int, int>> q = new Queue<Tuple<int, int>>();
        dist[fy, fx] = 1;
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
                if (dist[ny, nx] != 0) continue;

                //??????????
                dist[ny, nx] = dist[y, x] + 1;

                q.Enqueue(Tuple.Create(ny, nx));
            }
        }

        int ans = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (board[i][j] == '.') ans++;
            }
        }
        ans -= dist[H - 1, W - 1];

        if (dist[H - 1, W - 1] == 0) Console.WriteLine(-1);
        else  Console.WriteLine(ans);
    }

    bool inside(int y, int x)
    {
        return y >= 0 && x >= 0 && y < H && x < W && board[y][x] != '#';
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