using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
class Simple {
    int N;
    int[] a;
    void Solve() {
        //input
        N = io.Int;
        a = new int[N];
        for (int i = 0; i < N; ++i)
            a[i] = io.Int;
        //???
        var ans = int.MinValue;
        //chokudai????????
        for (int i = 0; i < N; ++i) {
            //???????????
            var tmpChokudai = int.MinValue;
            var tmpAoki = int.MinValue;
            //Aoki????????                
            for (int j = 0; j < N; ++j) {
                var sumChokudai = 0;
                var sumAoki = 0;
                if (i == j) continue;
                int cnt = 1;
                for (int k = (i < j) ? i : j; k <= ((i < j) ? j : i); ++k) {
                    if (cnt % 2 == 1) sumChokudai += a[k];
                    else sumAoki += a[k];
                    cnt++;
                }
                if (tmpAoki < sumAoki) {
                    tmpAoki = sumAoki;
                    tmpChokudai = sumChokudai;
                }
            }
            if (ans < tmpChokudai)
                ans = tmpChokudai;
        }
        //ret
        Console.WriteLine(ans);
    }

        SimpleIO io = new SimpleIO();
        public static void Main(string[] args) { new Simple().Stream(); }
        void Stream() { Solve(); io.writeFlush(); }
    }
    class SimpleIO {
        string[] nextBuffer;
        int BufferCnt;
        char[] cs = new char[] { ' ' };
        StreamWriter sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
        public SimpleIO() {
            nextBuffer = new string[0];
            BufferCnt = 0;
            Console.SetOut(sw);
        }
        public string Next() {
            if (BufferCnt < nextBuffer.Length)
                return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "")
                st = Console.ReadLine();
            nextBuffer = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt = 0;
            return nextBuffer[BufferCnt++];
        }
        public string String => Next();
        public char Char => char.Parse(String);
        public int Int => int.Parse(String);
        public long Long => long.Parse(String);
        public double Double => double.Parse(String);
        public void writeFlush() { Console.Out.Flush(); }
    }