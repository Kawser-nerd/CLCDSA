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

        long N;
        void solve() {
            cin = new Scanner();

            N = cin.nextLong();
            bool isChokudaiR;
            long cur = 1;

            for (int i = 1; ; i++)
                if (Math.Pow(2, i) - 1 >= N) {
                    isChokudaiR = i % 2 == 1;
                    break;
                }

            for (int i = 1; ; i++) {
                if(i%2==1){//chokudai
                    if (isChokudaiR)
                        cur = cur * 2 + 1;
                    else
                        cur = cur * 2;
                }else{
                    if (isChokudaiR)
                        cur = cur * 2;
                    else
                        cur = cur * 2 + 1;
                }
                if (cur > N) {
                    Console.WriteLine(i % 2 == 0 ? "Takahashi" : "Aoki");
                    break;
                }
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