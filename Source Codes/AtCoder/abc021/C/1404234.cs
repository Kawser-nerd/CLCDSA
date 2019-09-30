using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC021 {
    class MainClass {
        public static void Main(string[] args) {
            new MainClass().solve();
        }
        Scanner cin;
        const int DIV = (int)(1e9 + 7);

        int N;
        int a, b;
        int M;
        int[] x, y;

        int[,] r;
        long[] dp;
        void solve() {
            cin = new Scanner();
            WarshallFloyd w = new WarshallFloyd();
            N = cin.nextInt();
            a = cin.nextInt();
            b = cin.nextInt();
            a--;
            b--;
            M = cin.nextInt();
            x = new int[M];
            y = new int[M];

            for (int i = 0; i < M; i++) {
                x[i] = cin.nextInt();
                y[i] = cin.nextInt();
                x[i]--;
                y[i]--;
            }

            r = w.Init(N);
            for (int i = 0; i < M; i++)
                r[x[i], y[i]] = r[y[i], x[i]] = 1;

            r = w.Run(r);

            dp = new long[N];//dp[i] i???????
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    dp[i] = 0;
            dp[a] = 1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (r[a, j] != i)
                        continue;
                    for (int k = 0; k < N; k++) {
                        if (r[a, k] == i + 1 && r[j, k] == 1) {
                            dp[k] += dp[j];
                            dp[k] %= DIV;
                        }
                    }
                }
            }

            Console.WriteLine(dp[b]);
        }
    }

    class Scanner {
        string[] nextBuffer;
        int BufferCnt;
        char[] cs = new char[] { ' ' };
        public Scanner() {
            nextBuffer = new string[0];
            BufferCnt = 0;
        }
        public string next() {
            if (BufferCnt < nextBuffer.Length)
                return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "")
                st = Console.ReadLine();
            nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt = 0;
            return nextBuffer[BufferCnt++];
        }
        public int nextInt() {
            return int.Parse(next());
        }
        public long nextLong() {
            return long.Parse(next());
        }
        public double nextDouble() {
            return double.Parse(next());
        }
    }
    class WarshallFloyd {
        int INF;
        public WarshallFloyd() {
            INF = (int)(1e8);
        }
        public WarshallFloyd(int INF) {
            this.INF = INF;
        }

        /// <summary>
        /// ??????????O(????^3)
        /// </summary>
        /// <param name="m">????????INF???????????</param>
        /// <returns></returns>
        public int[,] Run(int[,] m) {
            int edgeLength = m.GetLength(0);
            for (int i = 0; i < edgeLength; i++)
                for (int j = 0; j < edgeLength; j++)
                    for (int k = 0; k < edgeLength; k++)
                        m[j, k] = Math.Min(m[j, k], m[j, i] + m[i, k]);
            return m;
        }
        /// <summary>
        /// ????????????INF??????0????????????
        /// </summary>
        /// <param name="n">????</param>
        /// <returns></returns>
        public int[,] Init(int n) {
            int[,] m = new int[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    m[i, j] = INF;
            for (int i = 0; i < n; i++)
                m[i, i] = 0;
            return m;
        }
    }
    static class StringEx {
        /// <summary>
        /// ?????????????
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static string Reversed(this string s) {
            return string.Join("", s.Reverse());
        }
    }
}