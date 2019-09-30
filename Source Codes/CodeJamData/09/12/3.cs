using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;
using System.Collections;

namespace QuestionB
{
    class Program
    {
        static void Main(string[] args)
        {
            string casename = "B-large";
            // string casename = "example1";
            using (StreamReader reader = new StreamReader(casename + ".in"))
            {
                IOStream input = new IOStream(reader);
                using (StreamWriter writer = new StreamWriter(casename + ".out"))
                {
                    int C = input.ReadInt();
                    for (int c = 0; c != C; ++c)
                    {
                        // parse test case
                        N = input.ReadInt();
                        M = input.ReadInt();
                        S = new long[M, N];
                        W = new long[M, N];
                        T = new long[M, N];
                        
                        for (int n = 0; n != N; ++n)
                        {
                            for (int m = 0; m != M; ++m)
                            {
                                S[m, N - (1 + n)] = input.ReadLong();
                                W[m, N - (1 + n)] = input.ReadLong();
                                T[m, N - (1 + n)] = input.ReadLong();
                            }
                        }

                        fastest = new long[2 * M, 2 * N];
                        for (int n = 0; n != 2 * M; ++n)
                        {
                            for (int m = 0; m != 2 * N; ++m)
                            {
                                fastest[n, m] = long.MaxValue;
                            }
                        }

                        // solve
                        long solution = Solve();

                        Console.WriteLine("Case #{0}: {1}", c + 1, solution);
                        writer.WriteLine("Case #{0}: {1}", c + 1, solution);
                    }
                }
            }
        }

        private static long Solve()
        {
            fastest[0, 0] = 0;
            Queue<Square> open = new Queue<Square>();
            open.Enqueue(new Square { X = 0, Y = 0 });

            bool[,] inQueue = new bool[2 * M, 2 * N];
            inQueue[0, 0] = true;

            while (open.Count > 0)
            {
                Square s = open.Dequeue();
                inQueue[s.X, s.Y] = false;
                long time = fastest[s.X, s.Y];

                foreach (Square adj in Adjacent(s))
                {
                    long newTime = GetTime(s, adj, time);
                    if (newTime < fastest[adj.X, adj.Y])
                    {
                        fastest[adj.X, adj.Y] = newTime;
                        if (!inQueue[adj.X, adj.Y])
                        {
                            open.Enqueue(adj);
                            inQueue[adj.X, adj.Y] = true;
                        }
                    }
                }
            }

            return fastest[2 * M - 1, 2 * N - 1];
        }

        // compute time to arrive at square 'to' if you're on 'from' at 'time'
        // and just go there directly.
        private static long GetTime(Square from, Square to, long time)
        {
            // Horizontal movement
            if (from.X != to.X)
            {
                if ((from.X % 2 == 0) == (to.X < from.X))
                {
                    return time + 2;
                }
                else
                {
                    // wait for traffic light
                    long w = W[from.X / 2, from.Y / 2];
                    long s = S[from.X / 2, from.Y / 2];
                    long t = T[from.X / 2, from.Y / 2];

                    return NextGreenTime(time, s, w, t + s) + 1;
                }
            }

            // Vertical movement
            if ((from.Y % 2 == 0) == (to.Y < from.Y))
            {
                return time + 2;
            }
            else
            {
                long w = W[from.X / 2, from.Y / 2];
                long s = S[from.X / 2, from.Y / 2];
                long t = T[from.X / 2, from.Y / 2];

                return NextGreenTime(time, w, s, t) + 1;
            }
        }

        private static long NextGreenTime(long time, long redFor, long greenFor, long cycleStart)
        {
            long t0 = time;
            long cycleLength = redFor + greenFor;
            time = (time - cycleStart) % cycleLength;

            if (time >= greenFor)
            {
                return t0 + (cycleLength - time);
            }
            else if (time < 0 && time >= -redFor)
            {
                return t0 - time;
            }
            else
            {
                // already green
                return t0;
            }
        }

        static IEnumerable<Square> Adjacent(Square s)
        {
            if (s.X > 0) yield return new Square { X = s.X - 1, Y = s.Y };
            if (s.Y > 0) yield return new Square { X = s.X, Y = s.Y - 1 };
            if (s.X + 1 < 2 * M) yield return new Square { X = s.X + 1, Y = s.Y };
            if (s.Y + 1 < 2 * N) yield return new Square { X = s.X, Y = s.Y + 1 };
        }

        static int N;
        static int M;
        static long[,] S;
        static long[,] W;
        static long[,] T;
        static long[,] fastest;
    }

    class Square
    {
        public int X { get; set; }
        public int Y { get; set; }
    }

    class IOStream
    {
        public IOStream(StreamReader reader)
        {
            this.reader = reader;
        }

        public int ReadInt()
        {
            return int.Parse(ReadString());
        }

        public long ReadLong()
        {
            return long.Parse(ReadString());
        }

        public string ReadString()
        {
            if (parts == null || partNum >= parts.Length)
            {
                ReadMore();
            }
            string rtn = parts[partNum];
            ++partNum;
            return rtn;
        }

        private void ReadMore()
        {
            parts = reader.ReadLine().Split(' ');
            partNum = 0;
        }

        StreamReader reader;
        string[] parts;
        int partNum;
    }
}
