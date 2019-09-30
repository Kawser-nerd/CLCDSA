using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D2
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = Convert.ToInt32(Console.ReadLine());
            for (int iT = 0; iT < T; iT++)
            {
                string[] constraints = Console.ReadLine().Split();
                int N = Convert.ToInt32(constraints[0]);
                int C = Convert.ToInt32(constraints[1]);
                bool[,] p = new bool[N, N];
                bool[,] x = new bool[N, N];
                bool[,] p2 = new bool[N, N];
                bool[,] x2 = new bool[N, N];
                int i, j;
                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        p[i, j] = false;
                        x[i, j] = false;
                        p2[i, j] = false;
                        x2[i, j] = false;
                    }
                }
                int c;
                for (c = 0; c < C; c++)
                {
                    string[] piece = Console.ReadLine().Split();
                    i = Convert.ToInt32(piece[1]) - 1;
                    j = Convert.ToInt32(piece[2]) - 1;
                    if (piece[0].CompareTo("x") != 0)
                    {
                        p[i, j] = true;
                        p2[i, j] = true;
                    }
                    if (piece[0].CompareTo("+") != 0)
                    {
                        x[i, j] = true;
                        x2[i, j] = true;
                    }
                }

                if (N > 1)
                {

                    //Solve for *

                    int[] rows = new int[N];
                    int[] cols = new int[N];
                    int cc;

                    cc = 0;
                    for (i = 0; i < N; i++)
                    {
                        bool fr = true;
                        for (j = 0; j < N; j++)
                        {
                            if (x[i, j])
                            {
                                fr = false;
                                break;
                            }
                        }
                        if (fr)
                        {
                            rows[cc] = i;
                            cc++;
                        }
                    }

                    cc = 0;
                    for (j = 0; j < N; j++)
                    {
                        bool fr = true;
                        for (i = 0; i < N; i++)
                        {
                            if (x[i, j])
                            {
                                fr = false;
                                break;
                            }
                        }
                        if (fr)
                        {
                            cols[cc] = j;
                            cc++;
                        }
                    }

                    for (i = 0; i < cc; i++)
                    {
                        x2[rows[i], cols[i]] = true;
                    }

                    //Solve for +

                    int[] u = new int[2 * N];
                    int[] v = new int[2 * N];
                    int[] pp = new int[2 * N];
                    int[] way = new int[2 * N];
                    for (int q = 0; q < 2 * N; q++)
                    {
                        u[q] = 0; v[q] = 0; pp[q] = 0; way[q] = 0;
                    }

                    int[,] a = new int[2 * N, 2 * N];
                    for (i = 0; i < 2 * N; i++)
                    {
                        for (j = 0; j < 2 * N; j++)
                        {
                            a[i, j] = 0;
                        }
                    }

                    for (i = 0; i < N; i++)
                    {
                        for (j = 0; j < N; j++)
                        {
                            bool fr = true;

                            if (p[i, j])
                            {
                                fr = false;
                            }

                            int dx, dy;
                            for (dx = -1; dx <= 1; dx += 2)
                            {
                                for (dy = -1; dy <= 1; dy += 2)
                                {
                                    int xx = i;
                                    int yy = j;
                                    while (true)
                                    {
                                        xx += dx;
                                        yy += dy;
                                        if ((xx < 0) || (xx >= N) || (yy < 0) || (yy >= N))
                                        {
                                            break;
                                        }
                                        if (p[xx, yy])
                                        {
                                            fr = false;
                                            break;
                                        }
                                    }
                                }
                                if (!fr)
                                {
                                    break;
                                }
                            }

                            if (fr)
                            {
                                a[i + j + 1, i - j + N] = -1;
                            }
                        }
                    }

                    int n = 2 * N - 1;
                    int MYINF = 1000000000;
                    for (i = 1; i <= n; ++i)
                    {
                        pp[0] = i;
                        int j0 = 0;
                        int[] minv = new int[n + 1];
                        bool[] used = new bool[n + 1];
                        for (int q = 0; q < n + 1; q++)
                        {
                            minv[q] = MYINF;
                            used[q] = false;
                        }
                        do
                        {
                            used[j0] = true;
                            int i0 = pp[j0];
                            int delta = MYINF;
                            int j1 = 0;
                            for (j = 1; j <= n; ++j)
                            {
                                if (!used[j])
                                {
                                    int cur = a[i0, j] - u[i0] - v[j];
                                    if (cur < minv[j])
                                    {
                                        minv[j] = cur;
                                        way[j] = j0;
                                    }
                                    if (minv[j] < delta)
                                    {
                                        delta = minv[j];
                                        j1 = j;
                                    }
                                }
                            }
                            for (j = 0; j <= n; ++j)
                            {
                                if (used[j])
                                {
                                    u[pp[j]] += delta;
                                    v[j] -= delta;
                                }
                                else
                                {
                                    minv[j] -= delta;
                                }
                            }
                            j0 = j1;
                        } while (pp[j0] != 0);
                        do
                        {
                            int j1 = way[j0];
                            pp[j0] = pp[j1];
                            j0 = j1;
                        } while (j0 != 0);
                    }

                    for (int z = 1; z <= n; ++z)
                    {
                        //(pp[z], z)
                        i = (pp[z] - 1 + z - N) / 2;
                        j = (pp[z] - 1 - z + N) / 2;
                        if ((i >= 0) && (i < N) && (j >= 0) && (j < N) && (a[pp[z], z] == -1))
                        {
                            p2[i, j] = true;
                        }
                    }
                }
                else
                {
                    p2[0, 0] = true;
                    x2[0, 0] = true;
                }

                //Calculate the result

                int score = 0;
                int changes = 0;
                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        if (p2[i, j])
                        {
                            score++;
                        }
                        if (x2[i, j])
                        {
                            score++;
                        }
                        if ((p[i, j] != p2[i, j]) || (x[i, j] != x2[i, j]))
                        {
                            changes++;
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1} {2}", iT+1, score, changes);

                for (i = 0; i < N; i++)
                {
                    for (j = 0; j < N; j++)
                    {
                        if ((p[i, j] != p2[i, j]) || (x[i, j] != x2[i, j]))
                        {
                            string output;
                            if ((p2[i, j]) && (x2[i, j]))
                            {
                                output = "o";
                            }
                            else if (p2[i, j])
                            {
                                output = "+";
                            }
                            else
                            {
                                output = "x";
                            }
                            Console.WriteLine("{0} {1} {2}", output, i + 1, j + 1);
                        }
                    }
                }
            }
        }
    }
}
