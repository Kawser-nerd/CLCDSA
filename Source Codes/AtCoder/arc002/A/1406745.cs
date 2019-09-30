using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ARC00 {
    class MainClass {
        public static void Main(string[] args) {
            new MainClass().solve();
        }
        Scanner cin;

        int Y;
        void solve() {
            cin = new Scanner();

            Y = cin.nextInt();

            AboutTime at = new AboutTime();

            Console.WriteLine(at.isLeapYear(Y) ? "YES" : "NO");
        }
    }

    class Scanner {
        string[] nextBuffer; int BufferCnt;
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
        public int nextInt() { return int.Parse(next()); }
        public long nextLong() { return long.Parse(next()); }
        public double nextDouble() { return double.Parse(next()); }
    }
    class WarshallFloyd {
        int INF;
        public WarshallFloyd() { INF = (int)(1e8); }
        public WarshallFloyd(int INF) { this.INF = INF; }
        /// <summary>
        /// ??????????O(????^3)
        /// </summary>
        /// <param name="m">????????INF???????????</param>
        /// <returns></returns>
        public int[,] Run(int[,] m) {
            int edgeLength = m.GetLength(0);
            for (int i = 0; i < edgeLength; i++)
                for (int j = 0; j < edgeLength; j++)
                    for (int k = 0; k < edgeLength; k++)
                        m[j, k] = Math.Min(m[j, k], m[j, i] + m[i, k]);
            return m;
        }
        /// <summary>
        /// ????????????INF??????0????????????
        /// </summary>
        /// <param name="n">????</param>
        /// <returns></returns>
        public int[,] Init(int n) {
            int[,] m = new int[n, n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    m[i, j] = INF;
            for (int i = 0; i < n; i++)
                m[i, i] = 0;
            return m;
        }
    }
    class AssociativeArray {
        Dictionary<int, int> iDic; Dictionary<string, int> sDic; Dictionary<char, int> cDic;
        public void CountInit(int[] arr) {
            iDic = new Dictionary<int, int>();
            for (int i = 0; i < arr.Length; i++) {
                if (!iDic.ContainsKey(arr[i])) iDic[arr[i]] = 0;
                iDic[arr[i]]++;
            }
        }
        public void CountInit(string[] arr) {
            sDic = new Dictionary<string, int>();
            for (int i = 0; i < arr.Length; i++) {
                if (!sDic.ContainsKey(arr[i])) sDic[arr[i]] = 0;
                sDic[arr[i]]++;
            }
        }
        public void CountInit(char[] arr) {
            cDic = new Dictionary<char, int>();
            for (int i = 0; i < arr.Length; i++) {
                if (!cDic.ContainsKey(arr[i])) cDic[arr[i]] = 0;
                cDic[arr[i]]++;
            }
        }
        public int CountValueSum() {
            int sum = 0;
            if (iDic != null)
                foreach (KeyValuePair<int, int> item in iDic)
                    sum += item.Value;
            else if (sDic != null)
                foreach (KeyValuePair<string, int> item in sDic)
                    sum += item.Value;
            else if (cDic != null)
                foreach (KeyValuePair<char, int> item in cDic)
                    sum += item.Value;
            return sum;
        }
        public int CountKeyNum() {
            if (iDic != null)
                return iDic.Count;
            else if (sDic != null)
                return sDic.Count;
            else if (cDic != null)
                return cDic.Count;
            return -1;
        }
        public int Min() {
            if (iDic != null) return minInt();
            else if (sDic != null) return 0;
            else if (cDic != null) return 0;
            return -1;
        }
        public int Max() {
            if (iDic != null) return maxInt();
            else if (sDic != null) return 0;
            else if (cDic != null) return 0;
            return -1;
        }
        public bool isContainsKey(int n) {
            return iDic.ContainsKey(n);
        }
        public bool isContainsKey(int[] n) {
            bool boo = true;
            for (int i = 0; i < n.Length; i++)
                if (!iDic.ContainsKey(n[i])) {
                    boo = false;
                    break;
                }
            return boo;
        }
        public void Debug() {
            Console.WriteLine("--- debug ---");
            if (iDic != null)
                foreach (KeyValuePair<int, int> item in iDic)
                    Console.WriteLine(item.Key + " " + item.Value);
            //else if (sDic != null)

            //else if (cDic != null)

        }
        private int maxInt() {
            int max = int.MinValue;
            foreach (KeyValuePair<int, int> item in iDic)
                if (max < item.Value) max = item.Value;
            return max;
        }
        private int minInt() {
            int min = int.MaxValue;
            foreach (KeyValuePair<int, int> item in iDic)
                if (min > item.Value) min = item.Value;
            return min;
        }
    }
    public class AboutTime {
        public bool isLeapYear(int y) {
            if (y % 400 == 0||(y%4==0&&y%100!=0)) return true;
            return false;
        }
    }
    static class StringEx {
        public static string Reversed(this string s) {
            return string.Join("", s.Reverse());
        }
    }
    static class CharEx {
        public static int toInt(this char c) {
            return int.Parse(c.ToString());
        }
    }
    
}