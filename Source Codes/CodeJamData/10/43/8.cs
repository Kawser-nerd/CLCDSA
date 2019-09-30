/*
    State: Accepted
*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Utility;

namespace GCJ2010Round2
{
    public class C_Bacteria
    {
        const int Modulus = 100003;
        int Inter(int a1, int a2, int b1, int b2)
        {
            if (a2 < b1 || b2 < a1)
                return -1;
            int a = Math.Max(a1, b1);
            int b = Math.Min(a2, b2);
            if (a == b)
                return 0;
            else
                return 1;
        }
        int[] parent;
        int FindParent(int x)
        {
            if (parent[x] == -1)
                return x;
            else
                return parent[x] = FindParent(parent[x]);
        }
        void Merge(int x, int y)
        {
            x = FindParent(x);
            y = FindParent(y);
            if (x == y)
                return;
            parent[x] = y;
        }
        public void Solve(TextReader input, TextWriter output)
        {
            var scanner = new StreamTokenizer(input);
            int testNum = scanner.NextInt();
            Random rnd = new Random();
            foreach (int caseId in Enumerable.Range(1, testNum))
            {
                int n = scanner.NextInt();
                var x1 = new int[n];
                var y1 = new int[n];
                var x2 = new int[n];
                var y2 = new int[n];
                var parent = Enumerable.Repeat(-1, n).ToArray();
                var map = new int[101, 101];
                for (int i = 0; i < n; i++)
                {
                    x1[i] = scanner.NextInt();
                    y1[i] = scanner.NextInt();
                    x2[i] = scanner.NextInt();
                    y2[i] = scanner.NextInt();
                    for (int x = x1[i]; x <= x2[i]; x++)
                        for (int y = y1[i]; y <= y2[i]; y++)
                            map[x, y] = 1;
                }
                int answer = 0;
                while (true)
                {
                    int cnt = 0;
                    for (int x = 100; x > 0; x--)
                        for (int y = 100; y > 0; y--)
                        {
                            if (map[x, y] == 1)
                                cnt++;
                        }
                    if (cnt == 0)
                        break;
                    for (int x = 100; x > 0; x--)
                    {
                        for (int y = 100; y > 0; y--)
                            if (map[x, y] == 0 && map[x, y - 1] == 1 && map[x - 1, y] == 1)
                            {
                                map[x, y] = 1;
                            }
                            else if (map[x, y] == 1 && map[x, y - 1] == 0 && map[x - 1, y] == 0)
                            {
                                map[x, y] = 0;
                            }
                    }
                    answer++;
                }
                /*
                for (int i = 0; i < n; i++)
                    for (int j = i + 1; j < n; j++)
                {
                    int t = Inter(x1[i], x2[i], x1[j], x2[j]);
                    int t2 = Inter(y1[i], y2[i], y1[j], y2[j]);
                    if ((t > 0 && t2 > 0)
                    || (t > 0 && t2 == 0)
                      || (t2 > 0 && t == 0))
                    {
                        Merge(i, j);
                    }
                }
                

                
                for (int j = 1; j < n; j++)
                    answer += f[n, j];
                answer %= Modulus;
                 */
                output.WriteLine("Case #{0}: {1}", caseId, answer);
            }
            output.Close();
        }

        static void Main(string[] args)
        {
            //new C_Bacteria().Solve(Console.In, Console.Out);
            new C_Bacteria().Solve(new StreamReader("C-small-attempt0.in"), new StreamWriter("C-small.out"));
            //new C_Bacteria().Solve(new StreamReader("C-large.in"), new StreamWriter("C-large.out"));
        }

    }
}
