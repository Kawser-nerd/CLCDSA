using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using System.Numerics;

namespace GCJDevKit.Solvers
{
    class B_Brute : AbstractSolver
    {

        int R, C, D;
        int[,] table;

        //counts the center of the 
        bool CountPoint(int x, int y, int N)
        {
            if (x + N >= R || x - N < 0) return false;
            if (y + N >= C || y - N < 0) return false;

            BigInteger sumaX = 0, sumaY = 0;
            for (int i= -N; i<=N; i++)
                for (int j = -N; j <= N; j++)
                {
                    if (Math.Abs(i * j) != N * N)
                    {
                        sumaX += i * (table[x+i, y+j] + D);
                        sumaY += j * (table[x+i, y+j] + D);
                    }
                }
            if (sumaX != 0) return false;
            if (sumaY != 0) return false;
                Console.WriteLine("{0} {1} {2}", x, y, N);
            
            return true;
        }

        bool CountPointSlightlyToTheLeftOf(int x, int y, int N)
        {
            if (x + N > R || x - N < 0) return false;
            if (y + N > C || y - N < 0) return false;

            BigInteger sumaX = 0, sumaY = 0;
            bool tx, ty;

            for (int i = -N; i < N; i++)
            {
                tx = (i == -N || i == N - 1);
                for (int j = -N; j < N; j++)
                {
                    ty = (j == -N || j == N - 1);

                    if (!(ty && tx))
                    {
                        int dx = 2 * i + 1;
                        int dy = 2 * j + 1;
                        sumaX += dx * (table[x + i, y + j] + D);
                        sumaY += dy * (table[x + i, y + j] + D);
                    }
                }
            }
            if (sumaX != 0) return false;
            if (sumaY != 0) return false;
            Console.WriteLine("{0} {1} {2}", x, y, N);

            return true;
        }

        protected override object Solve(System.IO.StreamReader input)
        {
            
            R = NextInt();
            C = NextInt();
            D = NextInt();

            table = new int[R, C];



            for (int i = 0; i < R; i++)
            {
                var s = NextWord();
                for (int j = 0; j < C; j++)
                {
                    table[i, j] = (s[j] - '0');
                }
            }

            int max = 0;
            for (int n = 1; n <= 5; n++)
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                            if (CountPoint(i, j, n))
                            {
                                max = 2*n+1;
                            }
                            if (n >= 2)
                            {
                                if (CountPointSlightlyToTheLeftOf(i, j, n))
                                {
                                    max = Math.Max(max, 2 * n);
                                }
                            }

                    }

                }
            }
            return (max == 0) ? "IMPOSSIBLE" : (max).ToString();
        }
    }
}
