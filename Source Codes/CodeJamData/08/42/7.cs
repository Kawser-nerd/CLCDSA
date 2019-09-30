using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ08R2Q2
{
    class ProgramQ2
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int cases = int.Parse(lines[0]);
            int index = 1;
            for (int i = 0; i < cases; i++)
            {
                // Parse
                string[] bits = lines[index].Split(' ');
                index++;
                int N = int.Parse(bits[0]);
                int M = int.Parse(bits[1]);
                int A = int.Parse(bits[2]);
                // Process
                output.Add(string.Format("Case #{0}: {1}", i + 1, Solve(N, M, A)));
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static string Solve(int N, int M, int A)
        {
            if (N * M < A)
                return "IMPOSSIBLE";
            int x1 = 0;
            int y1 = 0;
            for (int i = 0; i <= N; i++)
            {
                int x2 = i;
                for (int j = 0; j <= M; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    int y2 = j;
                    if (j == 0)
                    {
                        if (A % i != 0)
                            continue;
                        int x3 = 0;
                        int y3 = A / i;
                        if (y3 <= M)
                        {
                            Assert(A, x2, y2, x3, y3);
                            return string.Format("{0} {1} {2} {3} {4} {5}", x1, y1, x2, y2, x3, y3);
                        }
                        else
                            continue;
                    }
                    else if (i == 0)
                    {
                        if (A % j != 0)
                            continue;
                        int y3 = 0;
                        int x3 = A / j;
                        if (x3 <= N)
                        {
                            Assert(A, x2, y2, x3, y3);
                            return string.Format("{0} {1} {2} {3} {4} {5}", x1, y1, x2, y2, x3, y3);
                        }
                        else
                            continue;
                    }
                    //-i * y3 + k * j == A
                    int kStart = (A) / j;
                    int kEnd = (A + M * i + j) / j;
                    kStart = Math.Max(0, kStart);
                    kEnd = Math.Min(kEnd, N);
                    int offset = (kStart * j-A) % i;
                    while (offset < 0)
                        offset += i;
                    kStart += offset;
                    // TODO: optimize for skip based on common factors?
                    for (int k = kStart; k <= kEnd; k += i)
                    {
                        int x3 = k;
                        int y3 = (k * j-A) / i;
                        Assert(A, x2, y2, x3, y3);
                        if (y3 >= 0 && y3 <= M)
                            return string.Format("{0} {1} {2} {3} {4} {5}", x1, y1, x2, y2, x3, y3);
                        //A = k*j+y3*i;
                        //y3*i = A-k*j;
                    }
                    //i * y3 - k * j == A
                    kStart = (-A) / j;
                    kEnd = ( M * i + j-A) / j;
                    kStart = Math.Max(0, kStart);
                    kEnd = Math.Min(kEnd, N);
                    offset = (A + kStart * j) % i;
                    while (offset < 0)
                        offset += i;
                    kStart += offset;
                    // TODO: optimize for skip based on common factors?
                    for (int k = kStart; k <= kEnd; k += i)
                    {
                        int x3 = k;
                        int y3 = (A + k * j) / i;
                        Assert(A, x2, y2, x3, y3);
                        if (y3 >= 0 && y3 <= M)
                            return string.Format("{0} {1} {2} {3} {4} {5}", x1, y1, x2, y2, x3, y3);
                        //A = k*j+y3*i;
                        //y3*i = A-k*j;
                    }
                }
            }
            return "IMPOSSIBLE";
        }

        private static void Assert(int A, int x2, int y2, int x3, int y3)
        {
            if (Math.Abs(x2 * y3 - x3 * y2) != A)
                throw new Exception("");
        }
    }
}
