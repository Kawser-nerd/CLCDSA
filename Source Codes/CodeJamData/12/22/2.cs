using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class B
{
    static void Main()
    {
        int T = ReadInt();
        for (int t = 1; t <= T; t++)
        {
            int[] tmp = ReadInts();
            int H = tmp[0], N = tmp[1], M = tmp[2];
            int[][] ceiling = new int[N][], floor = new int[N][];
            for (int i = 0; i < N; i++)
                ceiling[i] = ReadInts();
            for (int i = 0; i < N; i++)
                floor[i] = ReadInts();
            double?[,] earliest = new double?[N, M];
            earliest[0, 0] = 0;
            K k = new K(0, 0, 0);
            SortedList<K, K> q = new SortedList<K, K>();
            q.Add(k, k);
            while (q.Count > 0)
            {
                k = q.First().Key;
                q.Remove(k);
                if (k.X == M - 1 && k.Y == N - 1)
                    break;

                if (k.X > 0)
                {
                    int minc = Math.Min(ceiling[k.Y][k.X], ceiling[k.Y][k.X - 1]);
                    int maxf = Math.Max(floor[k.Y][k.X], floor[k.Y][k.X - 1]);
                    if (minc >= maxf + 50)
                    {
                        double time = (H - minc + 50) / 10.0;
                        if (time < k.Time) time = k.Time;
			int mv = 10;
			if (H - time * 10 - 20 >= floor[k.Y][k.X]) mv = 1;
			if (time == 0) mv = 0;
			time += mv;
                        if (time < (earliest[k.Y, k.X - 1] ?? (time + 1)))
                        {
                            K k2 = new K(k.X - 1, k.Y, earliest[k.Y, k.X - 1] ?? -1);
                            if (k2.Time >= 0)
                                q.Remove(k2);
                            k2.Time = time;
                            earliest[k.Y, k.X - 1] = time;
                            q.Add(k2, k2);
                        }
                    }
                }
                if (k.Y > 0)
                {
                    int minc = Math.Min(ceiling[k.Y][k.X], ceiling[k.Y - 1][k.X]);
                    int maxf = Math.Max(floor[k.Y][k.X], floor[k.Y - 1][k.X]);
                    if (minc >= maxf + 50)
                    {
                        double time = (H - minc + 50) / 10.0;
                        if (time < k.Time) time = k.Time;
			int mv = 10;
			if (H - time * 10 - 20 >= floor[k.Y][k.X]) mv = 1;
			if (time == 0) mv = 0;
			time += mv;
                        if (time < (earliest[k.Y - 1, k.X] ?? (time + 1)))
                        {
                            K k2 = new K(k.X, k.Y - 1, earliest[k.Y - 1, k.X] ?? -1);
                            if (k2.Time >= 0)
                                q.Remove(k2);
                            k2.Time = time;
                            earliest[k.Y - 1, k.X] = time;
                            q.Add(k2, k2);
                        }
                    }
                }
                if (k.X < M - 1)
                {
                    int minc = Math.Min(ceiling[k.Y][k.X], ceiling[k.Y][k.X + 1]);
                    int maxf = Math.Max(floor[k.Y][k.X], floor[k.Y][k.X + 1]);
                    if (minc >= maxf + 50)
                    {
                        double time = (H - minc + 50) / 10.0;
                        if (time < k.Time) time = k.Time;
			int mv = 10;
			if (H - time * 10 - 20 >= floor[k.Y][k.X]) mv = 1;
			if (time == 0) mv = 0;
			time += mv;
                        if (time < (earliest[k.Y, k.X + 1] ?? (time + 1)))
                        {
                            K k2 = new K(k.X + 1, k.Y, earliest[k.Y, k.X + 1] ?? -1);
                            if (k2.Time >= 0)
                                q.Remove(k2);
                            k2.Time = time;
                            earliest[k.Y, k.X + 1] = time;
                            q.Add(k2, k2);
                        }
                    }
                }
                if (k.Y < N - 1)
                {
                    int minc = Math.Min(ceiling[k.Y][k.X], ceiling[k.Y + 1][k.X]);
                    int maxf = Math.Max(floor[k.Y][k.X], floor[k.Y + 1][k.X]);
                    if (minc >= maxf + 50)
                    {
                        double time = (H - minc + 50) / 10.0;
                        if (time < k.Time) time = k.Time;
			int mv = 10;
			if (H - time * 10 - 20 >= floor[k.Y][k.X]) mv = 1;
			if (time == 0) mv = 0;
			time += mv;
                        if (time < (earliest[k.Y + 1, k.X] ?? (time + 1)))
                        {
                            K k2 = new K(k.X, k.Y + 1, earliest[k.Y + 1, k.X] ?? -1);
                            if (k2.Time >= 0)
                                q.Remove(k2);
                            k2.Time = time;
                            earliest[k.Y + 1, k.X] = time;
                            q.Add(k2, k2);
                        }
                    }
                }
            }
            Console.WriteLine("Case #{0}: {1:0.000000}", t, earliest[N-1, M-1]);
        }
    }

    class K : IComparable<K>
    {
        public double Time;
        public int X, Y;
        public K(int x, int y, double t)
        {
            X = x;
            Y = y;
            Time = t;
        }
        public int CompareTo(K k)
        {
            if (k.Time == Time)
            {
                if (k.Y == Y) return X.CompareTo(k.X);
                return Y.CompareTo(k.Y);
            }
            return Time.CompareTo(k.Time);
        }
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static decimal ReadDecimal()
    {
        return decimal.Parse(ReadLine());
    }

    static decimal[] ReadDecimals()
    {
        return Array.ConvertAll(ReadWords(), decimal.Parse);
    }

    #endregion
}
