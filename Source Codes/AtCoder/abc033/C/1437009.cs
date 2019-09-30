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

        string S;
        void solve() {
            cin = new Scanner();

            S=cin.next();

            string[] mul = S.Split('+');

            int ans = 0;
            for (int i = 0; i < mul.Length; i++) {
                bool zero = false;
                for (int j = 0; j < mul[i].Length; j++) {
                    if (mul[i][j]=='0'){
                        zero = true;
                        break;
                    }
                }
                if (!zero) {
                    ans++;
                }
            }

            Console.WriteLine(ans);

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