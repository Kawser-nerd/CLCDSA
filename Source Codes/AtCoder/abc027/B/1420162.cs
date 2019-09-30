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
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            a = new int[N];
            int sum = 0;
            int ave = 0;
            int chokudai = 0;
            bool[] isReachable = new bool[N - 1];
            for (int i = 0; i < N; i++) {
                a[i] = cin.nextInt();
                sum += a[i];
            }

            if (sum % N != 0) {
                Console.WriteLine(-1);
            } else {
                ave = sum / N;
                for (int i = 0; i < N; i++) {
                    if (a[i] < ave) {
                        for (int j = i + 1; j < N; j++) {
                            if (!isReachable[j - 1]) {
                                chokudai++;
                                isReachable[j - 1] = true;
                            }
                            if (a[j] > ave) {
                                int diff = Math.Min(a[j] - ave, ave - a[i]);
                                a[j] -= diff;
                                a[i] += diff;
                                if (a[i] == ave)
                                    break;
                            }
                        }
                    }
                    if (a[i] > ave) {
                        for (int j = i + 1; j < N; j++) {
                            if (!isReachable[j - 1]) {
                                chokudai++;
                                isReachable[j - 1] = true;
                            }
                            if (a[j] < ave) {
                                int diff = Math.Min(ave - a[j], a[i] - ave);
                                a[j] += diff;
                                a[i] -= diff;
                                if (a[i] == ave) break;
                            }
                        }
                    }
                }
               
                Console.WriteLine(chokudai);
            }
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