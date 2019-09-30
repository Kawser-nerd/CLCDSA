using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace _1
{
    class Solver
    {
        public string Solve(int n, int m, int[][] X, int[][] Y)
        {
            int[] res = new int[n];
            int[,] a = new int[m, n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    a[i, j] = -1;

            int cur = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < X[i].Length; j++)
                {
                    int x = X[i][j];
                    if (a[cur, X[i][j] - 1] != -1 && a[cur, X[i][j] - 1] != Y[i][j])
                    {
                        cur--;
                        break;
                    }
                    a[cur, X[i][j] - 1] = Y[i][j];
                }
                cur++;
            }

            m = cur;

            {
                int[] c0 = new int[m];
                int[] i1 = new int[m];
                for (int i = 0; i < m; i++)
                    i1[i] = -1;
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                    {
                        if (a[i, j] == 1)
                            i1[i] = j;
                        else if (a[i, j] == 0)
                            c0[i]++;
                    }

                int[] bIndices = new int[m];
                for (int i = 0; i < m; i++)
                    bIndices[i] = i;


                int[] indices;
                bool done = false;
                int[] tc0;
                while (!done)
                {
                    done = true;
                    tc0 = (int[])c0.Clone();
                    indices = (int[])bIndices.Clone();
                    Array.Sort(tc0, indices);

                    for (int i = 0; i < m; i++)
                    {
                        if (tc0[i] > 0)
                            break;
                        int ind = i1[indices[i]];
                        if (ind == -1)
                            return "IMPOSSIBLE";

                        if (res[ind] == 1)
                            continue;
                        done = false;
                        res[ind] = 1;
                        for (int j = 0; j < m; j++)
                            if (a[j, ind] == 0)
                                c0[j]--;
                    }
                }
            }
            /*bool done = false;
            fix = new bool[m];
            while (!done)
            {
                done = true;
                for (int i = 0; i < m; i++)
                {
                    if (fix[i])
                        continue;
                    int c0 = 0;
                    int i1 = -1;
                    for (int j = 0; j < n; j++)
                    {
                        if (a[i, j] == 0 && res[j] == 0)
                            c0++;
                        if (a[i, j] == 1)
                            i1 = j;
                    }
                    if (i1 == -1)
                        continue;
                    if (res[i1] == 0 && c0 == 0)
                    {
                        fix[i] = true;
                        res[i1] = 1;
                        done = false;
                    }
                    else if (res[i1] == 1)
                    {
                        fix[i] = true;
                    }
                }
            }*/


            for (int i = 0; i < m; i++)
            {
                int c0 = 0;
                int i1 = -1;
                for (int j = 0; j < n; j++)
                {
                    if (a[i, j] == 0 && res[j] == 0)
                        c0++;
                    if (a[i, j] == 1)
                        i1 = j;
                }
                if (c0 == 0 && i1 == -1)
                {
                    return "IMPOSSIBLE";
                }
            }

            return string.Join(" ", res.Select(x => x.ToString()).ToArray());
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int nCases = int.Parse(Console.ReadLine());
            for (int i = 1; i <= nCases; i++)
            {
                int n = int.Parse(Console.ReadLine());
                int m = int.Parse(Console.ReadLine());

                int[][] custX = new int[m][];
                int[][] custY = new int[m][];

                for (int j = 0; j < m; j++)
                {
                    int[] arr = Console.ReadLine().Split().Select(s => int.Parse(s)).ToArray();
                    custX[j] = new int[arr[0]];
                    custY[j] = new int[arr[0]];
                    for (int k = 0; k < arr[0]; k++)
                    {
                        custX[j][k] = arr[1 + k * 2];
                        custY[j][k] = arr[2 + k * 2];
                    }
                }


                Solver solver = new Solver();

                string solv_res = solver.Solve(n, m, custX, custY);

                Console.WriteLine("Case #" + i.ToString() + ": " +
                                    solv_res
                                  );
            }
        }
    }
}
