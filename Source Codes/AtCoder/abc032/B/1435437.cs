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

        string s;
        int k;
        void solve() {
            cin = new Scanner();

            s = cin.next();
            k = cin.nextInt();

            Dictionary<string, int> dic = new Dictionary<string, int>();

            for (int i = 0; i + k <= s.Length;i++){
                string tmp = s.Substring(i, k);
                if (!dic.ContainsKey(tmp)) dic[tmp] = 0;
                dic[tmp]++;
            }

            Console.WriteLine(dic.Count());
            //check
            /*
            foreach(KeyValuePair<string,int> item in dic){
                Console.WriteLine(item.Key+":"+item.Value);
            }*/

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