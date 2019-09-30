using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Trees {
    class Program {
        static long cnt(long a, long b, long c) {
            if ((a <= 0) || (b <= 0) || (c <= 0)) return 0;
            return a * b * c;
        }
        static void Main(string[] args) {
            TextWriter wr = new StreamWriter("c:\\temp\\out.txt");
            TextReader tr = new StreamReader("c:\\temp\\tree.in");
            int cases = int.Parse(tr.ReadLine());
            for (int c = 0; c != cases; c++) {
                string[] tt = tr.ReadLine().Split(" ".ToCharArray());
                long n = long.Parse(tt[0]);
                long A = long.Parse(tt[1]);
                long B = long.Parse(tt[2]);
                long C = long.Parse(tt[3]);
                long D = long.Parse(tt[4]);
                long x0 = long.Parse(tt[5]);
                long y0 = long.Parse(tt[6]);
                long M = long.Parse(tt[7]);
                long X = x0;
                long Y = y0;
                int[,] cc = new int[3,3];
                cc[X % 3, Y % 3]++;
                for ( int i = 0 ; i != n-1 ; i++) {
                    X = (A * X + B) % M;
                    Y = (C * Y + D) % M;
                    cc[X % 3, Y % 3]++;
                }
                long res = 0;
                for (int i = 0; i != 3; i++) {
                    for (int j = 0; j != 3; j++) {
                        for (int k = 0; k != 3; k++) {
                            if ((i + j + k) % 3 != 0) continue;
                            for (int m = 0; m != 3; m++) {
                                for (int p = 0; p != 3; p++) {
                                    for (int q = 0; q != 3; q++) {
                                        if ((m + p + q) % 3 != 0) continue;
                                        long x = cc[i, m];
                                        long y = cc[j, p];
                                        long z = cc[k, q];
                                        if (i == j && m == p) y--;
                                        if (i == k && m == q) z--;
                                        if (j == k && p == q) z--;
                                        res += cnt(x, y, z);
                                    }
                                }
                            }
                        }
                    }
                }
                Console.WriteLine("Case #{0}: {1}", c + 1, res/6);
                wr.WriteLine("Case #{0}: {1}", c + 1, res/6);
            }
            wr.Close();
        }
    }
}
