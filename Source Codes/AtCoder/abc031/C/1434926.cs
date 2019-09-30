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

        int N;
        int[] a;

        int INF = (int)1e9;
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            a = new int[N];
            for (int i = 0; i < N; i++) {
                a[i] = cin.nextInt();
            }

            int ans = -INF;
            for (int i = 0; i < N;i++){
                int maxT = -INF;
                int maxA = -INF;
                for (int j = 0; j < N;j++){
                    if (i == j) continue;
                    int chokudai = 0;
                    int aoki = 0;
                    int s = Math.Min(i, j);
                    int e = Math.Max(i, j);
                    int cur = 1;
                    for (int k = s; k <= e;k++){
                        if(cur%2!=0){
                            chokudai += a[k];
                        }else{
                            aoki += a[k];
                        }
                        cur++;
                    }
                    if(maxA<aoki){
                        maxA = aoki;
                        maxT = chokudai;
                    }
                }
                if (ans < maxT) ans = maxT;
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