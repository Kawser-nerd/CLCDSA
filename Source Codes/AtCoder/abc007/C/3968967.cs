using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static Scanner cin = new Scanner();

    struct point {
        public int x, y;
        public point(int X, int Y) {
            x = X;
            y = Y;
        }
    }

    static void Main(string[] args) {
        const int INF = (int)1e9;
        int R = cin.Int();
        int C = cin.Int();
        int sy = cin.Int() - 1;
        int sx = cin.Int() - 1;
        int gy = cin.Int() - 1;
        int gx = cin.Int() - 1;

        var c = Enumerable.Repeat(0, R).Select(x => Console.ReadLine()).ToArray();
        var d = new int[R, C];
        var dx = new int[]{ 1, -1, 0, 0 };
        var dy = new int[]{ 0, 0, 1, -1 };
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                d[i, j] = INF;
            }
        }

        var que = new Queue<point>();
        que.Enqueue(new point(sx, sy));
        d[sy, sx] = 0;
        while(que.Count > 0) {
            point point = que.Dequeue();
            if (point.x == gx && point.y == gy) break;
            for (int i = 0; i < 4; i++) {
                int nx = point.x + dx[i];
                int ny = point.y + dy[i];
                if(0 <= nx && nx < C && 0 <= ny && ny < R && c[ny][nx] != '#' && d[ny, nx] == INF) {
                    que.Enqueue(new point(nx, ny));
                    d[ny, nx] = d[point.y, point.x] + 1;
                }
            }
        }

        Console.WriteLine(d[gy, gx]);
        Console.ReadLine();
    }
}

class Scanner //????
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

    public int Int()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Long() + add;
        }
        return Array;
    }

    public double Double()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Double() + add;
        }
        return Array;
    }
}