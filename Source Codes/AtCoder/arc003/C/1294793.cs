using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;

namespace Program
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
        }

        public void Solve()
        {
            var cin = new MyInputStream();
            var N = cin.ReadInt();
            var M = cin.ReadInt();
            var c = new int[M, N];

            const int START = -1;
            const int GOAL = 0;
            const int IMPENETRABLE = -2;

            Point s = new Point();
            for (int y = 0; y < N; ++y)
            {
                var line = cin.Read();
                for (int x = 0; x < M; ++x)
                {
                    switch (line[x])
                    {
                        case 's':
                            s.X = x;
                            s.Y = y;
                            c[x, y] = START;
                            break;
                        case 'g':
                            c[x, y] = GOAL;
                            break;
                        case '#':
                            c[x, y] = IMPENETRABLE;
                            break;
                        default:
                            c[x, y] = (int)(line[x] - '0');
                            break;
                    }
                }
            }

            var dxy = new[] { -1, 0, 1, 0, -1 };

            // ??????????brightness??????????????
            Func<double, bool> Check = (brightness) =>
            {
                // ?????????????
                var visited = new bool[M, N];

                // bfs?????
                var q = new Queue<Turn>();

                //  Turn( ?????, ??????????????, ?????)
                q.Enqueue(new Turn(time: 1, bright: 10.0, pos: s));
                while (q.Any())
                {
                    var now = q.Dequeue();

                    // ???????????????brightness?????
                    if (now.b < brightness) continue;

                    // ???????
                    if (visited[now.p.X, now.p.Y]) continue;
                    visited[now.p.X, now.p.Y] = true;

                    // ??????4??????
                    for (int i = 0; i < 4; ++i)
                    {
                        var nx = now.p.X + dxy[i];
                        var ny = now.p.Y + dxy[i + 1];
                        // ??????????
                        if (nx < 0 || nx >= M) continue;
                        if (ny < 0 || ny >= N) continue;

                        // ??????????????????????(?????)
                        if (visited[nx, ny]) continue;

                        // ????????????
                        if (c[nx, ny] == GOAL) return true;

                        // ?????????, ???????????????????
                        if (c[nx, ny] < 0) continue;

                        // ?????????????????????
                        var nb = Math.Min(Math.Pow(0.99, now.t) * c[nx, ny], now.b);
                        q.Enqueue(new Turn(now.t + 1, nb, new Point(nx, ny)));
                    }
                }
                return false;
            };

            // ???????????????????
            if (!Check(0))
            {
                WriteLine(-1);
                return;
            }

            // ???(??)????????????????
            var l = 0d;
            var r = 10d;
            for (int i = 0; i < 50; ++i)
            {
                if (Math.Abs(r - l) < 1e-15) break;
                var mid = (l + r) / 2d;
                if (Check(mid)) l = mid;
                else r = mid;
            }
            WriteLine(l);
        }
    }

    struct Turn
    {
        public int t;
        public double b;
        public Point p;
        public Turn(int time, double bright, Point pos) : this()
        {
            this.t = time;
            this.b = bright;
            this.p = pos;
        }
    }

    public class Point
    {
        private Pair<int, int> pos;
        public Point() { pos = new Pair<int, int>(0, 0); }
        public Point(int x, int y) { pos = new Pair<int, int>(x, y); }
        public int X
        {
            get { return pos.First; }
            set { pos.First = value; }
        }
        public int Y
        {
            get { return pos.Second; }
            set { pos.Second = value; }
        }
    }

    public class Pair<T1, T2> : IComparable<Pair<T1, T2>>
        where T1 : IComparable<T1>
        where T2 : IComparable<T2>
    {
        public T1 First { get; set; }
        public T2 Second { get; set; }
        public Pair(T1 x, T2 y)
        {
            First = x;
            Second = y;
        }
        public int CompareTo(Pair<T1, T2> other)
        {
            if (this.Equals(other)) return 0;
            var cmp = First.CompareTo(other.First);
            if (cmp != 0) return cmp;
            else return Second.CompareTo(other.Second);
        }
        public override string ToString()
        {
            return $"({First}, {Second})";
        }

    }

    public class MyInputStream
    {
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(char separator = ' ')
        {
            this.separator = separator;
            inputStream = new Queue<string>();
        }

        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = Console.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                var elem = tmp[i].Trim(separator);
                if (elem == string.Empty) continue;
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine() { return Console.ReadLine(); }
        public int ReadInt() { return int.Parse(Read()); }
        public long ReadLong() { return long.Parse(Read()); }
        public double ReadDouble() { return double.Parse(Read()); }
    }
}