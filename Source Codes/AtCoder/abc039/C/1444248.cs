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

        string S;
        void solve() {
            S = cin.next();

            List<int> wwChain = new List<int>();

            for (int i = 0; i < S.Length - 1;i++){
                if(S[i]=='W'&&S[i+1]=='W'){
                    wwChain.Add(i);
                }
            }

            bool nearestIsMiFa = (wwChain[1] - wwChain[0]) == 7;

            if(nearestIsMiFa){
                if (wwChain[0] == 4) {
                    Console.WriteLine("Do");
                } else if(wwChain[0]==2){
                    Console.WriteLine("Re");
                } else if (wwChain[0]==0){
                    Console.WriteLine("Mi");
                }
            }else{
                if(wwChain[0]==6){
                    Console.WriteLine("Fa");
                }else if(wwChain[0]==4){
                    Console.WriteLine("So");
                }else if(wwChain[0]==2){
                    Console.WriteLine("La");
                }else if(wwChain[0]==0){
                    Console.WriteLine("Si");
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
            public string[] nStringArray() { return next().Split(' '); }
            public int[] nIntArray() { return nStringArray().Select(int.Parse).ToArray(); }
            public long[] nLongArray() { return nStringArray().Select(long.Parse).ToArray(); }
            public double[] nDoubleArray() { return nStringArray().Select(double.Parse).ToArray(); }
        }
        class Mathf {
            private int mod = 1000000007;
            public Mathf() { }
            public Mathf(int mod) { this.mod = mod; }
            public long Pow(long a, long b) {
                if (b == 0) return 1;
                if (b % 2 == 1) return (a % mod * Pow(a % mod, b - 1) % mod) % mod;
                else return Pow(a * a % mod, b / 2) % mod;
            }
            public long Fact(long n) { return n != 0 ? (n % mod * (Fact(n - 1) % mod) % mod) : 1; }
            public long C(long n, long r) {if (r == 0 || n == r) return 1;
                else return (Fact(n) % mod * Pow((Fact(n - r) % mod * Fact(r) % mod) % mod, mod - 2) % mod) % mod;}
        }
    }
}