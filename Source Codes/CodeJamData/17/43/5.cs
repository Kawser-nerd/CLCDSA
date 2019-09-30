using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Numerics;

namespace GoogleCodeJam
{
    class Program
    {
        static Scanner cin;
        static void Main(string[] args)
        {
            cin = new Scanner();
            Solve.cin = cin;
            int T = cin.nextInt();
            Solve.init();
            Solve[] SV = new Solve[T];
            for (int i = 0; i < T; i++)
            {
                SV[i] = new Solve();
                SV[i].input();
            }

            Solve.init();
            string[] ans = new string[T];


            bool highspeed = false;

            //high speed;
            if (highspeed)
            {
                Parallel.For(0, T, i =>
                {
                    ans[i] = SV[i].calc();
                    SV[i] = null;
                });
            }

            //low speed
            if (!highspeed)
            {
                for (int i = 0; i < T; i++)
                {
                    ans[i] = SV[i].calc();
                    SV[i] = null;
                }
            }

            for (int i = 0; i < T; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                Console.WriteLine(ans[i]);
            }


        }


        public class XRand
        {
            uint x, y, z, w;


            public XRand()
            {
                init();
            }

            public XRand(uint s)
            {
                init();
                init_xor128(s);
            }

            void init()
            {
                x = 314159265; y = 358979323; z = 846264338; w = 327950288;

            }

            public void init_xor128(uint s)
            {
                z ^= s;
                z ^= z >> 21; z ^= z << 35; z ^= z >> 4;
                z *= 736338717;
            }

            uint next()
            {
                uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
            }

            public long nextLong(long m)
            {
                return (long)((((ulong)next() << 32) + next()) % (ulong)m);
            }

            public int nextInt(int m)
            {
                return (int)(next() % m);
            }

            public int nextInt(int min, int max)
            {
                return min + nextInt(max - min + 1);
            }

            public int nextIntP(int a)
            {
                return (int)Math.Pow(a, nextDouble());
            }

            public int nextIntP(int min, int max)
            {
                int diff = max - min;
                return min + nextIntP(diff + 2) - 1;
            }

            public double nextDouble()
            {
                return (double)next() / uint.MaxValue;
            }

            public double nextDoubleP(double a)
            {
                return Math.Pow(a, nextDouble());
            }
        }



        class Solve
        {
            public Solve() { }

            public static Scanner cin;

            

            public static void init()
            {

            }



            int H, W;
            string[] board;
            public void input()
            {
                H = cin.nextInt();
                W = cin.nextInt();
                board = new string[H];
                for (int i = 0; i < H; i++)
                {
                    board[i] = cin.next();
                }
            }

            List<int> Lx, Ly;
            List<int> Px, Py;
            int[,] ID;

            int[] vy = { 1, 0, -1, 0 };
            int[] vx = { 0, 1, 0, -1 };

            int[] vs = { 3, 2, 1, 0 };
            int[] ve = { 1, 0, 3, 2 };

            List<int>[] Connect;
            bool[,] OKcheck;
            List<int>[,] Target;


            List<int> memoL;

            bool dfs(int y, int x, int v)
            {
                if (!inside(y, x)) return true;
                if (ID[y, x] < 0) return false;
                if (board[y][x] == '#') return true;
                if (ID[y, x] > 0) memoL.Add(ID[y, x]);
                int nv = v;
                if (board[y][x] == '/')
                {
                    nv = vs[v];
                }
                else if (board[y][x] == '\\')
                {
                    nv = ve[v];
                }
                return dfs(y + vy[nv], x + vx[nv], nv);
            }

            bool inside(int y, int x)
            {
                return y >= 0 && x >= 0 && y < H && x < W;
            }

            int[] usedID;

            public string calc()
            {
                string ans = "IMPOSSIBLE";
                ID = new int[H, W];
                Lx = new List<int>();
                Ly = new List<int>();
                Px = new List<int>();
                Py = new List<int>();

                for (int i = 0; i < H; i++)
                {
                    for (int j = 0; j < W; j++)
                    {
                        if (board[i][j] == '.')
                        {
                            Py.Add(i);
                            Px.Add(j);
                            ID[i, j] = Py.Count;
                        }
                        else if (board[i][j] == '-' || board[i][j] == '|')
                        {
                            Ly.Add(i);
                            Lx.Add(j);
                            ID[i, j] = -Ly.Count;
                        }
                    }
                }

                usedID = new int[H * W + 3];
                int idcnt = 1;

                OKcheck = new bool[Lx.Count, 2];
                Target = new List<int>[Lx.Count, 2];
                Connect = new List<int>[Px.Count];

                int[] nokori = new int[Px.Count];
                bool[] used = new bool[Px.Count];

                for (int i = 0; i < Px.Count; i++)
                {
                    Connect[i] = new List<int>();
                }
                for (int i = 0; i < Lx.Count; i++)
                {
                    int y = Ly[i];
                    int x = Lx[i];
                    bool flag = false;
                    for (int k = 0; k < 2; k++)
                    {
                        idcnt++;
                        List<int> memo = new List<int>();
                        bool ok = true;
                        for (int j = 0; j < 2; j++)
                        {
                            int beam = k + j * 2;
                            memoL = new List<int>();
                            if (dfs(y + vy[beam], x + vx[beam], beam))
                            {
                                foreach (var now in memoL)
                                {
                                    if (usedID[now - 1] != idcnt)
                                    {
                                        memo.Add(now - 1);
                                        usedID[now - 1] = idcnt;
                                    }
                                }
                            }
                            else
                            {
                                memo = new List<int>();
                                ok = false;
                                break;
                            }
                        }
                        if (ok)
                        {
                            flag = true;
                        }
                        OKcheck[i, k] = ok;
                        Target[i, k] = new List<int>();
                        foreach (var now in memo)
                        {
                            Connect[now].Add(i * 2 + k);
                            nokori[now]++;
                            Target[i, k].Add(now);
                        }
                    }
                    if (!flag) return ans;
                }

                int[] color = new int[Lx.Count];
                for (int i = 0; i < Lx.Count; i++)
                {
                    color[i] = -1;
                }
                
                while (true)
                {
                    int id = -1;
                    int idscore = 99999999;
                    for (int i = 0; i < Px.Count; i++)
                    {
                        if (used[i]) continue;
                        if(idscore > nokori[i])
                        {
                            id = i;
                            idscore = nokori[i];
                        }
                    }
                    if (id == -1) break;
                    int beam = -1;
                    foreach (var next in Connect[id])
                    {
                        int b = next / 2;
                        if(color[b] == -1)
                        {
                            beam = next;
                            break;
                        }
                    }
                    if (beam == -1) return ans;
                    int choose = beam % 2;
                    beam /= 2;
                    color[beam] = choose;

                    foreach (var item in Target[beam, choose])
                    {
                        used[item] = true;
                    }

                    foreach (var item in Target[beam, 1 - choose])
                    {
                        nokori[item]--;
                    }
                }

                for (int i = 0; i < Lx.Count; i++)
                {
                    if(color[i] == -1)
                    {
                        if (OKcheck[i, 0]) color[i] = 0;
                        else color[i] = 1;
                    }
                }
                

                StringBuilder sb = new StringBuilder();
                sb.Append("POSSIBLE\n");
                char[,] ansBoard = new char[H, W];
                for (int i = 0; i < H; i++)
                {
                    for (int j = 0; j < W; j++)
                    {
                        if (ID[i, j] >= 0) ansBoard[i, j] = board[i][j];
                        else
                        {
                            if (color[-ID[i, j] - 1] == 0) ansBoard[i, j] = '|';
                            else ansBoard[i, j] = '-';
                        }
                    }
                }
                for (int i = 0; i < H; i++)
                {
                    for (int j = 0; j < W; j++)
                    {
                        sb.Append(ansBoard[i, j]);
                    }
                    if(i != H - 1 )sb.Append('\n');
                }

                return sb.ToString();
            }
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
}
