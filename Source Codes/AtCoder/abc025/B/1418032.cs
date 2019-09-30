using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace AtCoder{
    class MainClass {
        public static void Main(string[] args) { new MainClass().solve(); }
        Scanner cin;

        int N, A, B;
        bool[] isEast;
        int[] d;
        void solve() {
            cin = new Scanner();

            Mathf m = new Mathf();
            N = cin.nextInt();
            A = cin.nextInt();
            B = cin.nextInt();
            isEast = new bool[N];
            d = new int[N];

            for (int i = 0; i < N;i++){
                isEast[i] = cin.next() == "East";
                d[i] = cin.nextInt();
            }

            int chokudai = 0;
            for (int i = 0; i < N;i++){
                //East<-pos,West<-neg
                int move = m.Clamp(d[i], A, B);
                if (isEast[i])
                    chokudai += move;
                else
                    chokudai -= move;
            }

            if (chokudai == 0)
                Console.WriteLine("0");
            else
                Console.WriteLine((chokudai>0?"East ":"West ")+Math.Abs(chokudai));
        }
    }
    class Scanner{
        string[] nextBuffer;int BufferCnt;char[] cs = new char[] { ' ' };
        public Scanner(){nextBuffer = new string[0];BufferCnt = 0;}
        public string next(){
            if (BufferCnt < nextBuffer.Length)return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "")st = Console.ReadLine();
            nextBuffer= st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt=0;
            return nextBuffer[BufferCnt++];
        }
        public int nextInt(){return int.Parse(next());}
        public long nextLong(){return long.Parse(next());}
        public double nextDouble(){return double.Parse(next());}
    }
    class Mathf{
        public int Clamp(int n,int a,int b){
            if (n < a) return a;
            if (b < n) return b;
            return n;
        }
        public long Clamp(long n,long a,long b){
            if (n < a) return a;
            if (b < n) return b;
            return n;
        }
        public double Clamp(double n,double a,double b){
            if (n < a) return a;
            if (b < n) return b;
            return n;
        }
        //public T Clamp<T>(T n,T a,T b){}
    }

}