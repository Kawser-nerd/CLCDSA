using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace NotFounds
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
            var c = new int[N, M];

            const int START   = -1;
            const int GOAL    = -2;
            const int INVALID = -3;

            var sx = 0;
            var sy = 0;
            for (int i = 0; i < N; ++i)
            {
                var l = cin.Read();
                for (int j = 0; j < M; ++j)
                {
                    if (l[j] == 's')
                    {
                        sx = j;
                        sy = i;
                        c[i, j] = START;
                    }
                    else if (l[j] == 'g') c[i, j] = GOAL;
                    else if (l[j] == '#') c[i, j] = INVALID;
                    else                  c[i, j] = l[j] - '0';
                }
            }

            var table = new double[10, N * M + 1];
            for (int i = 0; i <= N * M; ++i)
            {
                var brightness = Math.Pow(0.99, i);
                for (int j = 1; j < 10; ++j)
                    table[j, i] = brightness * j;
            }

            var dxy = new int[] {0, 1, 0, -1, 0};
            Func<double, bool> bfs = (bright) => {
                var visited = new bool[M, N];
                var pos = new Pair<Pair<int, int>, Pair<int, double>>(new Pair<int, int>(sx, sy), new Pair<int, double>(0, 10));
                var q = new Queue<Pair<Pair<int, int>, Pair<int, double>>>();
                q.Enqueue(pos);

                while (q.Any())
                {
                    var now = q.Dequeue();
                    var x = now.First.First;
                    var y = now.First.Second;
                    var t = now.Second.First;
                    var m = now.Second.Second;

                    if (m < bright) continue;

                    if (visited[x, y]) continue;
                    else visited[x, y] = true;

                    if (c[y, x] == GOAL) return true;
                    if (c[y, x] == INVALID) continue;

                    for (int i = 0; i < 4; ++i)
                    {
                        int nx = x + dxy[i];
                        int ny = y + dxy[i + 1];
                        if (nx < 0 || nx >= M) continue;
                        if (ny < 0 || ny >= N) continue;

                        double min = (c[y, x] == START) ? 10 : Math.Min(m, table[c[y, x], t]);
                        var next = new Pair<Pair<int, int>, Pair<int, double>>(new Pair<int, int>(nx, ny), new Pair<int, double>(t + 1, min));
                        q.Enqueue(next);
                    }
                }
                return false;
            };

            if (!bfs(0))
            {
                WriteLine("-1");
                return;
            }

            double a = 0;
            double b = 10;
            while (Math.Abs(a - b) > 1e-10)
            //for (int i = 0; i < 50; ++i)
            {
                double mid = (a + b) / 2.0;
                if (bfs(mid))
                {
                    a = mid;
                }
                else
                {
                    b = mid;
                }
            }
            Console.WriteLine(a.ToString("F10"));
        }
    }

    public class Pair<T1, T2>
    {
        public T1 First;
        public T2 Second;
        public Pair() { First = default(T1); Second = default(T2); }
        public Pair(T1 f, T2 s) { First = f; Second = s; }
        public override string ToString() { return "(" + First + ", " + Second + ")"; }
        public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj)) return true;
            else if (obj == null) return false;
            var tmp = obj as Pair<T1, T2>;
            return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
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
            string[] tmp = Console.ReadLine().Trim().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine() => Console.ReadLine();
        public int ReadInt() => int.Parse(Read());
        public long ReadLong() => long.Parse(Read());
        public double ReadDouble() => double.Parse(Read());
        public string r() => Read();
        public int ri() => ReadInt();
        public long rl() => ReadLong();
        public double rd() => ReadDouble();
    }
}