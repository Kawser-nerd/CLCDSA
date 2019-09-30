using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace AtCoder {
    class MainClass {
        public static void Main(string[] args) { new MainClass().solve(); }
        Scanner cin;

        int N, K;
        int[] S;
        void solve() {//???
            cin = new Scanner();

            N = cin.nextInt();
            K = cin.nextInt();
            S = new int[N + 1];
            S[N] = -1;//??
            for (int i = 0; i < N; i++)
                S[i] = cin.nextInt();

            bool zero = false;
            for (int i = 0; i < S.Length; i++) {
                if (S[i] == 0) {
                    zero = true;
                }
            }

            if (zero) {
                Console.WriteLine(N);
            } else {
                long mul = 1;
                int max = 0;
                int _to = 0;
                int _from = 0;

                while (_to <= N) {
                    max = Math.Max((_to - _from), max);
                    if (mul * S[_to] <= K)
                        mul *= S[_to++];
                    else {
                        if (_from == _to) {
                            _from++; _to++;
                        } else {
                            mul /= S[_from++];
                        }
                    }
                }

                Console.WriteLine(max);

            }
        }
        class Scanner {
            string[] nextBuffer; int BufferCnt; char[] cs = new char[] { ' ' };
            public Scanner() { nextBuffer = new string[0]; BufferCnt = 0; }
            public string next() {
                if (BufferCnt < nextBuffer.Length) return nextBuffer[BufferCnt++];
                string st = Console.ReadLine();
                while (st == "") st = Console.ReadLine();
                nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
                BufferCnt = 0;
                return nextBuffer[BufferCnt++];
            }
            public int nextInt() { return int.Parse(next()); }
            public long nextLong() { return long.Parse(next()); }
            public double nextDouble() { return double.Parse(next()); }
        }
    }
}