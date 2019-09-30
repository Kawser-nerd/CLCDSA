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

            //high speed;

            /*
            string[] ans = new string[T];
            Parallel.For(0, T, i =>
            {
                ans[i] = SV[i].calc();
            });

            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}:\n{1}", i + 1, ans[i]);
            }
            */

            //low speed
            
            for (int i = 0; i < T; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                SV[i].calc();
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
            int N;
            int[] A, B;


            public void input()
            {
                H = cin.nextInt();
                W = cin.nextInt();
                N = H + W;
                A = new int[N];
                B = new int[N];
                for (int i = 0; i < N; i++)
                {
                    A[i] = cin.nextInt();
                    B[i] = cin.nextInt();
                    if (A[i] > B[i]) swap(ref A[i], ref B[i]);
                }
            }

            string memo = "//\\";
            bool[] ok;
            int nokori;

            int[,] box;

            public void calc()
            {
                Console.WriteLine();
                ok = new bool[N];
                nokori = 2 * N;
                bool ng = false;

                box = new int[H, W];

                BIT bit = new BIT(nokori + 2);
                for (int i = 0; i < nokori; i++)
                {
                    bit.bitUpdate(i + 1, 1);
                }
                
                while (nokori > 0)
                {
                    bool flag = false;
                    for (int i = 0; i < N; i++)
                    {
                        if (ok[i]) continue;
                        int count = bit.bitCal(B[i], A[i]);
                        //Console.WriteLine("count " + i + " " + count);
                        if(count == 2)
                        {
                            //Console.WriteLine("start " + i);
                            //時計周り
                            if (!connect(A[i], B[i]))
                            {
                                ng = true;
                                break;
                            }
                            nokori -= 2;
                            bit.bitUpdate(A[i], -1);
                            bit.bitUpdate(B[i], -1);
                            flag = true;
                            ok[i] = true;
                            //Console.WriteLine("OK " + i);
                        }
                        else if(count == nokori)
                        {
                            //Console.WriteLine("start " + i);
                            //反時計周り
                            if (!connect(B[i], A[i]))
                            {
                                ng = true;
                                break;
                            }
                            nokori -= 2;
                            bit.bitUpdate(A[i], -1);
                            bit.bitUpdate(B[i], -1);
                            flag = true;
                            ok[i] = true;
                            //Console.WriteLine("OK " + i);
                        }
                    }

                    if (!flag || ng)
                    {
                        Console.WriteLine("IMPOSSIBLE");
                        return;
                    }
                }
                for (int i = 0; i < H; i++)
                {
                    for (int j = 0; j < W; j++)
                    {
                        Console.Write(memo[box[i,j]]);
                    }
                    Console.WriteLine();
                }
            }

            //swap
            void swap<T>(ref T a, ref T b)
            {
                T c = a;
                a = b;
                b = c;
            }


            int sy, sx, sk;
            int gy, gx, gk;

            bool connect(int s, int g)
            {
                pos(s, out sy, out sx, out sk);
                pos(g, out gy, out gx, out gk);

                if(gk == 0)
                {
                    gk = 2;
                    gy--;
                }
                else if(gk == 1)
                {
                    gk = 3;
                    gx++;
                }
                else if(gk == 2)
                {
                    gk = 0;
                    gy++;
                }
                else if(gk == 3)
                {
                    gk = 1;
                    gx--;
                }

                return go(sy, sx, sk);
            }

            bool go(int y, int x, int k)
            {
                //Console.WriteLine("now: " + y + " " + x + " " + k);
                if(!inside(y, x))
                {
                    //Console.WriteLine(gy + " " + gx + " " + gk);
                    if (y == gy && x == gx && k == gk) return true;
                    else return false;
                }

                int ny, nx, nk;

                if (box[y, x] != 0)
                {
                    if (((box[y, x] - 1) ^ (k % 2)) == 0)
                    {
                        goback(y, x, k, out ny, out nx, out nk);
                    }
                    else
                    {
                        gonext(y, x, k, out ny, out nx, out nk);
                    }
                }
                else
                {
                    box[y, x] = 2 - k % 2;
                    gonext(y, x, k, out ny, out nx, out nk);
                }

                return go(ny, nx, nk);
            }

            bool inside(int y, int x)
            {
                return y >= 0 && x >= 0 && y < H && x < W;
            }

            int[] vyb = { 0, -1, 0, 1 };
            int[] vxb = { -1, 0, 1, 0 };
            int[] vkb = { 1, 2, 3, 0 };

            void goback(int y, int x, int k, out int ny, out int nx, out int nk)
            {
                ny = y + vyb[k];
                nx = x + vxb[k];
                nk = vkb[k];
            }

            int[] vyn = { 0, 1, 0, -1 };
            int[] vxn = { 1, 0, -1, 0 };
            int[] vkn = { 3, 0, 1, 2 };

            void gonext(int y, int x, int k, out int ny, out int nx, out int nk)
            {
                ny = y + vyn[k];
                nx = x + vxn[k];
                nk = vkn[k];
            }



            void pos(int T, out int y, out int x, out int k)
            {
                T -= 1;

                if(T < W)
                {
                    y = 0;
                    x = T;
                    k = 0;
                    return;
                }
                T -= W;

                if (T < H)
                {
                    y = T;
                    x = W - 1;
                    k = 1;
                    return;
                }
                T -= H;

                if (T < W)
                {
                    y = H - 1;
                    x = W - 1 - T;
                    k = 2;
                    return;
                }
                T -= W;

                if (true)
                {
                    y = H - 1 - T;
                    x = 0;
                    k = 3;
                    return;
                }
            }


            class BIT
            {
                int bitA;
                int[] bit;
                const int INF = int.MaxValue - 10;

                public BIT(int maxa)
                {
                    bitA = maxa;
                    bit = new int[bitA + 1];
                    for (int i = 0; i < bitA; i++)
                    {
                        bit[i] = 0;
                    }
                }

                public void bitUpdate(int a, int val)
                {
                    for (int i = a; i <= bitA; i += i & -i)
                    {
                        bit[i] += val;
                    }
                }

                public int bitCal(int max, int min)
                {
                    return bitCal(max) - bitCal(min - 1);
                }

                public int bitCal(int a)
                {
                    int ret = 0;
                    for (int i = a; i > 0; i &= i - 1)
                    {
                        ret += bit[i];
                    }
                    return ret;
                }
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
