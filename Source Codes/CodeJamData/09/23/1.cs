using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1C
{
    class Heap<U> : List<U> where U : IComparable
    {
        public int Push(U data)
        {
            Add(data);
            int n = Count - 1;
            int p = (n - 1) / 2;
            while (p >= 0 && this[p].CompareTo(data) > 0)
            {
                U q = this[p];
                this[p] = this[n];
                this[n] = q;
                n = p;
                p = (n - 1) / 2;
            }
            return n;
        }

        public bool IsEmpty()
        {
            return Count == 0;
        }

        public U Peek()
        {
            return this[0];
        }

        public U Pop()
        {
            U peek = this[0];
            this[0] = this[Count - 1];
            RemoveAt(Count - 1);
            int n = 0, p;
            while (2 * n + 1 < Count)
            {
                p = n;
                if (this[2 * n + 1].CompareTo(this[n]) < 0) p = 2 * n + 1;
                if (2 * n + 2 < Count && this[2 * n + 2].CompareTo(this[p]) < 0)
                    p = 2 * n + 2;
                if (p != n)
                {
                    U tmp = this[p];
                    this[p] = this[n];
                    this[n] = tmp;
                    n = p;
                } else n = Count;
            }
            return peek;
        }

        public void Decreased(int position)
        {
            int n = position;
            int p = (n - 1) / 2;
            while (n != 0 && p >= 0 && this[p].CompareTo(this[n]) > 0)
            {
                U tmp = this[p];
                this[p] = this[n];
                this[n] = tmp;
                n = p;
                p = (n - 1) / 2;
            }
        }

        public void Increased(int position)
        {
            int n = position;
            while (2 * n + 1 < Count)
            {
                int p = n;
                if (this[2 * n + 1].CompareTo(this[p]) < 0)
                    p = 2 * n + 1;
                if (2 * n + 2 < Count && this[2 * n + 2].CompareTo(this[p]) < 0)
                    p = 2 * n + 2;
                if (p != n)
                {
                    U tmp = this[p];
                    this[p] = this[n];
                    this[n] = tmp;
                    n = p;
                } else n = Count;
            }
        }

    }

    class Reader
    {
        static string buf;
        static bool empty = true;

        private static string WordDelims = " \t";

        public static int ReadInt()
        {
            Fill();
            string token = getToken(WordDelims);
            return int.Parse(token);
        }

        public static double ReadDouble()
        {
            Fill();
            string token = getToken(WordDelims);
            return double.Parse(token);
        }

        public static string ReadWord()
        {
            Fill();
            return getToken(WordDelims);
        }

        public static string ReadLine()
        {
            Fill();
            return getRest();
        }

        private static void Fill()
        {
            if (empty)
            {
                empty = false;
                buf = Console.ReadLine();
            }
        }

        private static string getToken(string ends)
        {
            int i = 0;
            while (i < buf.Length && !ends.Contains(buf[i]))
                i++;
            string output = buf.Substring(0, i);
            while (i < buf.Length && ends.Contains(buf[i]))
                i++;
            if (i < buf.Length)
            {
                buf = buf.Substring(i);
            } else
            {
                buf = "";
                empty = true;
            }
            return output;
        }

        private static string getRest()
        {
            string output = buf;
            empty = true;
            buf = "";
            return output;
        }
    }


    class Program
    {
        static List<string> map;
        static Dictionary<int, string> solutions;
        static Dictionary<int, string>[,] data; //please don't read this, you would laugh :P

        static int W;

        struct IdiotPos {
            public int x; public int y; public int p;
        }


        static void Main(string[] args)
        {
            int T = Reader.ReadInt();

            for (int i = 1; i <= T; i++)
            {
                W = Reader.ReadInt();
                int Q = Reader.ReadInt();
                map = new List<string>();
                for (int j = 1; j <= W; j++)
                    map.Add(Reader.ReadLine());
                solutions = new Dictionary<int, string>();
                data = new Dictionary<int, string>[W, W];
                for(int x = 0; x < W; x++)
                    for (int y = 0; y < W; y++)
                    {
                        data[x, y] = new Dictionary<int, string>();
                        if (map[y][x] >= '0' && map[y][x] <= '9')
                        {
                            data[x, y][(int)(map[y][x] - '0')] = map[y][x].ToString();
                            solutions[(int)(map[y][x] - '0')] = map[y][x].ToString();
                        }
                    }
                idpos.Clear();
                for (int x = 0; x < W; x++)
                    for (int y = 0; y < W; y++)
                    {
                        if (map[y][x] >= '0' && map[y][x] <= '9')
                        {
                            idpos.Enqueue(new IdiotPos() { x = x, y = y, p = (int) (map[y][x] - '0')});
                        }
                    }
                while (idpos.Count > 0)
                {
                    IdiotPos pos = idpos.Dequeue();
                    Idiot(pos.x, pos.y, pos.p);
                }
                Console.WriteLine("Case #{0}:", i);
                for (int k = 0; k < Q; k++)
                {
                    Console.WriteLine(solutions[Reader.ReadInt()]);
                }
            }
        }

        static int[] dx = new int[]{-1, 0, 0, 1};
        static int[] dy = new int[]{0, -1, 1, 0};

        static Queue<IdiotPos> idpos = new Queue<IdiotPos>();

        private static void Idiot(int x, int y, int p)
        {
            for (int d1 = 0; d1 < 4; d1++)
            {
                int nx = x + dx[d1];
                int ny = y + dy[d1];
                if (nx >= 0 && nx < W && ny >= 0 && ny < W)
                {
                    int k = (map[ny][nx] == '+')? 1 : -1;

                    for (int d2 = 0; d2 < 4; d2++)
                    {
                        int n2x = nx + dx[d2];
                        int n2y = ny + dy[d2];
                        if (n2x >= 0 && n2x < W && n2y >= 0 && n2y < W &&
                            Char.IsDigit(map[n2x][n2y]))
                        {
                            int t = (int) (map[n2y][n2x] - '0');
                            int v = p + k * t;
                            if (v < -18 || v > 360) continue;
                            if (!data[n2x, n2y].ContainsKey(v) ||
                                (
                                    data[n2x, n2y][v].CompareTo(data[x, y][p] + map[ny][nx] + map[n2y][n2x]) > 0
                                     &&
                                    data[n2x, n2y][v].Length == (data[x, y][p] + map[ny][nx] + map[n2y][n2x]).Length
                                )
                               )
                            {
                                data[n2x, n2y][v] = (data[x, y][p] + map[ny][nx] + map[n2y][n2x]);
                                idpos.Enqueue(new IdiotPos() { x = n2x, y = n2y, p = v });
                                if (!solutions.ContainsKey(v) ||
                                    (solutions[v].Length == data[n2x, n2y][v].Length &&
                                     solutions[v].CompareTo(data[n2x, n2y][v]) > 0))
                                {
                                    solutions[v] = data[n2x, n2y][v];
                                }
                            }

                        }
                    }
                }
            }
        }
    }
}
