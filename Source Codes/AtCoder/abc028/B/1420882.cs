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

            S = cin.next();

            Dictionary<char, int> dic = new Dictionary<char, int>();

            for (int i = 0; i < S.Length;i++){
                if (!dic.ContainsKey(S[i])) dic[S[i]] = 0;
                dic[S[i]]++;
            }

            string str = "ABCDEF";
            for (int i = 0; i < str.Length-1;i++){
                if (!dic.ContainsKey(str[i])) dic[str[i]] = 0;
                Console.Write(dic[str[i]]+" ");
            }
            if (!dic.ContainsKey('F')) dic['F'] = 0;
            Console.WriteLine(dic['F']);
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