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

        Scanner cin = new Scanner();

        int W, H;
        void solve() {
            W = cin.nextInt();
            H = cin.nextInt();

            Mathf mat = new Mathf();

            long ans = mat.C(W + H - 2,H - 1);

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
    class Mathf {
        private int mod = 1000000007;
        public Mathf() { }
        public Mathf(int mod) { this.mod = mod; }
        public long Pow(long a, long b) {
            if (b == 0)     return 1;
            if (b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
            else return Pow(a * a % mod, b / 2) % mod;
        }
        public long Fact(long n) { return n != 0 ? (n % mod * (Fact(n - 1) % mod) % mod) : 1; }
        public long C(long n, long r) {
            if (r == 0 || n == r) return 1;
            else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;
        }
    }
}