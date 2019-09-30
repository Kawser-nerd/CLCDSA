using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Globalization;
namespace ant
{
    class MainClass
    {
        
        public static void Main(string[] args)
        {
            new MainClass().solve();
        }

        Scanner cin;

        //1<=N<=100
        //C1,C2,...,CN
        //1<=Ci<=1e9
        int N;
        int[] C;

        double ans;
        void solve(){
            cin = new Scanner();
            N = cin.nextInt();
            C = new int[N];
            for (int i = 0; i < N; i++)
                C[i] = cin.nextInt();
            
            ans = 0.0;
            Array.Sort(C);
    
            for (int i = C.Length - 1; i >= 0;i--){
                int cur = C[i];
				int myself = i;

                int div = 0;//????
                double aveC = 0.0;//????????????????????
                for (int j = C.Length - 1; j >= 0; j--){
                    if (j == myself) continue;
                    if (cur % C[j] == 0)
                        div++;
                }
				
                if (div % 2 == 0)
                    aveC=(div + 2.0) / (2.0 * div + 2.0);
                else
                    aveC=0.5;
               // Console.WriteLine(C[i]+" "+aveC);
                ans += aveC;
            }

            Console.WriteLine(ans);
        }
    }

    class Scanner{
        string[] nextBuffer;
        int BufferCnt;
        char[] cs = new char[] { ' ' };
        public Scanner(){
            nextBuffer = new string[0];
            BufferCnt = 0;
        }
        public string next()
        {
            if (BufferCnt < nextBuffer.Length)
                return nextBuffer[BufferCnt++];
            string st = Console.ReadLine();
            while (st == "")
                st = Console.ReadLine();
            nextBuffer= st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            BufferCnt=0;
            return nextBuffer[BufferCnt++];
        }
        public int nextInt(){
            return int.Parse(next());
        }
        public long nextLong(){
            return long.Parse(next());
        }
        public double nextDouble(){
            return double.Parse(next());
        }
    }
}