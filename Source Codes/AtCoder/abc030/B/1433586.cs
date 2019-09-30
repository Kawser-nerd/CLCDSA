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

        double n, m;
        void solve() {
            cin = new Scanner();

            n = cin.nextDouble();
            m = cin.nextDouble();
            n %= 12;

            double ho = (360 / 12) * n + (360 / 12) * (m / 60);
            double mi = (360 / 60) * m;

            double ans = ho >= mi ? (ho - mi) : (mi - ho);

            Console.WriteLine(ans<=180?ans:(360-ans));
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