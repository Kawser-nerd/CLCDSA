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
        int[] B;
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            B = new int[N];
            B[0] = 0;
            for (int i = 1; i < N; i++) {
                B[i] = cin.nextInt();
                B[i]--;
            }

            int[] salary = new int[N];
            for (int i = 0; i < N; i++)
                salary[i] = 1;

            for (int i = N - 1; i >= 0;i--){
                int? min = null;
                int? max = null;
               
                for (int j = i+1; j < N;j++){
                    if(B[j]==i){
                        if (min == null)
                            min = salary[j];
                        else
                            min = (min < salary[j]) ? min : salary[j];
                        if (max == null)
                            max = salary[j];
                        else
                            max = (salary[j] < max) ? max : salary[j];
                    }
                }
                salary[i] = (max ?? 0) + (min ?? 0) + 1;
            }

            Console.WriteLine(salary[0]);

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
    class Mathf {
        public int Clamp(int n, int a, int b) { if (n < a) return a; if (b < n) return b; return n; }
        public long Clamp(long n, long a, long b) { if (n < a) return a; if (b < n) return b; return n; }
        public double Clamp(double n, double a, double b) { if (n < a) return a; if (b < n) return b; return n; }
    }
}