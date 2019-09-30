using System;
using System.Collections.Generic;
using System.Text;

namespace codejamcs
{
    internal class Portal
    {
        private static int C;
        private static int ccc;

        private static int[] dx = new int[] {0, 1, 0, -1};
        private static int[] dy = new int[] {1, 0, -1, 0};
        private static int[,] go = new int[255,4];
        private static string[] map;
        private static int N;
        private static int[] op = new int[] {2, 3, 0, 1};
        private static Queue<State> q = new Queue<State>();
        private static int R;
        private static int res;
        private static string smap;
        private static byte[,,,] used = new byte[256,256,256,16];

        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            N = int.Parse(s.Trim());
            int cases = 0;
            map = new string[16];
            StringBuilder sb;
            while (N-- > 0)
            {
                s = Console.ReadLine();
                string[] l = s.Trim().Split(' ');
                R = int.Parse(l[0]);
                C = int.Parse(l[1]);
                sb = new StringBuilder();
                sb.Append(' ', 16 - C);
                for (int i = 0; i < R; i++)
                    map[i] = Console.ReadLine().Trim() + sb.ToString();
                sb.Append(' ', C);
                for (int i = 0; i < 16 - R; i++)
                    map[R + i] = sb.ToString();
                cases++;
                Process();
                Console.WriteLine("Case #{0}: {1}", cases, res == -1 ? "THE CAKE IS A LIE" : res.ToString());
                Console.Error.WriteLine("States: {0}", ccc);
            }
        }

        private static void Process()
        {
            smap = string.Join("", map);
            int p = smap.IndexOf("O");
            int x = p >> 4;
            int y = p%16;

            makego();

            Array.Clear(used, 0, 256*256*256*16);

            q.Clear();
            for (int d1 = 0; d1 < 4; d1++)
                for (int d2 = 0; d2 < 4; d2++)
                    if (d1 != d2)
                    {
                        used[p, go[p, d1], go[p, d2], op[d1]*4 + op[d2]] = 1;
                        q.Enqueue(new State((byte) p, (byte) go[p, d1], (byte) go[p, d2], (byte) (op[d1]*4 + op[d2])));
                    }

            res = -1;
            ccc = 0;
            while (q.Count > 0)
            {
                State s = q.Dequeue();
                ccc++;

                for (int d = 0; d < 4; d++)
                {
                    x = s.pos/16;
                    y = s.pos%16;
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if (s.pos == s.p1)
                    {
                        if (op[d] == s.d12/4)
                        {
                            nx = s.p2/16;
                            ny = s.p2%16;
                        }
                    }
                    if (s.pos == s.p2)
                    {
                        if (op[d] == s.d12%4)
                        {
                            nx = s.p1/16;
                            ny = s.p1%16;
                        }
                    }

                    if (checkbound(nx, ny))
                    {
                        if (map[nx][ny] == 'X')
                        {
//                            Console.WriteLine("{0} {1}, p1 {2} {3}, p2 {4} {5}, d {6}", x, y, s.p1/16, s.p1%16, s.p2/16, s.p2%16, d);
                            res = used[s.pos, s.p1, s.p2, s.d12];
                            return;
                        }

                        if (map[nx][ny] != '#')
                        {
                            byte now = (byte) (used[s.pos, s.p1, s.p2, s.d12] + 1);
                            byte np = (byte) (nx*16 + ny);
                            for (int d1 = 0; d1 < 5; d1++)
                                for (int d2 = 0; d2 < 5; d2++)
                                {
                                    int nd1 = d1;
                                    int nd2 = d2;
                                    int np1;
                                    int np2;
                                    if (nd1 == 4)
                                    {
                                        nd1 = s.d12/4;
                                        np1 = s.p1;
                                    }
                                    else np1 = go[np, nd1];
//                                    Console.WriteLine(nd2);
                                    if (nd2 == 4)
                                    {
                                        nd2 = s.d12%4;
                                        np2 = s.p2;
                                    }
                                    else np2 = go[np, nd2];
                                    if (!((np1 == np2) && (nd1 == nd2)) && used[np, np1, np2, nd1*4 + nd2] == 0)
                                    {
                                        used[np, np1, np2, nd1*4 + nd2] = now;
                                        q.Enqueue(new State(np, (byte) np1, (byte) np2, (byte) (nd1*4 + nd2)));
                                    }
                                }
                        }
                    }
                }
            }
        }

        private static void makego()
        {
            for (int x = 0; x < R; x++)
                for (int y = 0; y < C; y++)
                    if (map[x][y] != '#')
                        for (int d = 0; d < 4; d++)
                        {
                            int nx = x;
                            int ny = y;
                            while (checkbound(nx, ny))
                            {
                                if (map[nx][ny] == '#') break;
                                nx += dx[d];
                                ny += dy[d];
                            }
                            nx -= dx[d];
                            ny -= dy[d];
                            go[x*16 + y, d] = nx*16 + ny;
                        }
        }

        private static bool checkbound(int nx, int ny)
        {
            return (nx >= 0) && (nx < R) && (ny >= 0) && (ny < C);
        }

        #region Nested type: State

        private struct State
        {
            public byte d12;
            public byte p1;
            public byte p2;
            public byte pos;

            public State(byte pos, byte p1, byte p2, byte d12)
            {
                this.pos = pos;
                this.p1 = p1;
                this.p2 = p2;
                this.d12 = d12;
            }
        }

        #endregion
    }
}