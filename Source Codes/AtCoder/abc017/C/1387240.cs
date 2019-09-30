using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC017 {
    class MainClass {
        public static void Main(string[] args) {
            new MainClass().solve();
        }
        Scanner cin;

        int N, M;
        int[] l, r, s;
        
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            M = cin.nextInt();

            l = new int[N];
            r = new int[N];
            s = new int[N];

            for(int i = 0; i < N; i++) {
                l[i] = cin.nextInt();
                r[i] = cin.nextInt();
                s[i] = cin.nextInt();
            }

            int sum = 0;
            //??????????????imos
            int[] imos = new int[M+1];
            for (int i = 0; i < M+1; i++)
                imos[i] = 0;

            for(int i = 0; i < N; i++) {
                imos[l[i]-1]+=s[i];
                imos[r[i]]-=s[i];
                sum += s[i];
            }

            for (int i = 1; i < M; i++)
                imos[i] += imos[i - 1];

            //????????????????????
            //???????????
            int min = int.MaxValue;
            for(int i = 0; i < M; i++) 
                min = Math.Min(min, imos[i]);

            Console.WriteLine(sum - min);

        }
        
        int dfs() {

            return -1;
        }

    }
    class Scanner {
        string[] nextBuffer;
        int BufferCnt;
        char[] cs = new char[] { ' ' };
        public Scanner() {
            nextBuffer = new string[0];
            BufferCnt = 0;
        }
        public string next() {
            if (BufferCnt < nextBuffer.Length)
                return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "")
                st = Console.ReadLine();
            nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt = 0;
            return nextBuffer[BufferCnt++];
        }
        public int nextInt() {
            return int.Parse(next());
        }
        public long nextLong() {
            return long.Parse(next());
        }
        public double nextDouble() {
            return double.Parse(next());
        }

    }
    static class StringEx {
        /// <summary>
        /// ?????????????
        /// </summary>
        /// <param name="s"></param>
        /// <returns></returns>
        public static string Reversed(this string s) {
            return string.Join("", s.Reverse());
        }
    }
}