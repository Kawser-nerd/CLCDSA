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
        string R;
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            R=cin.next();

            Dictionary<char, int> dic = new Dictionary<char, int>();
            for (int i = 0; i < N;i++){
                if (!dic.ContainsKey(R[i])) dic[R[i]] = 0;
                dic[R[i]]++;
            }

            if (!dic.ContainsKey('A')) dic['A'] = 0;
            if (!dic.ContainsKey('B')) dic['B'] = 0;
            if (!dic.ContainsKey('C')) dic['C'] = 0;
            if (!dic.ContainsKey('D')) dic['D'] = 0;
            double ans = (dic['A'] * 4 + dic['B'] * 3 + dic['C'] * 2 + dic['D'] * 1) / (double)N;

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