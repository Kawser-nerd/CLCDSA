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

        int N, M, X, Y;
        int[] a, b;
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            M = cin.nextInt();
            X = cin.nextInt();
            Y = cin.nextInt();
            a = new int[N];
            b = new int[M];
            for (int i = 0; i < N; i++)
                a[i] = cin.nextInt();
            for (int i = 0; i < M; i++)
                b[i] = cin.nextInt();

            bool isA = false;
            int curA = 1;
            int curB = 0;
            int chokudai = a[0]+X;
            int ans = 0;

            while (true) {
                //Console.WriteLine((isA?"A":"B")+chokudai);
                if (isA) {
                    if (chokudai <= a[curA]) {
                        isA = false;
                        chokudai = a[curA] + X;
                        //curA++;
                    } else {
                        curA++;
                    }
                } else {
                    if (chokudai <= b[curB]) {
                        isA = true;
                        chokudai = b[curB] + Y;
                        //curB++;
                        ans++;
                    } else {
                        curB++;
                    }
                }
                if (curA == a.Length || curB == b.Length)
                    break;
            }

            Console.WriteLine(ans);

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