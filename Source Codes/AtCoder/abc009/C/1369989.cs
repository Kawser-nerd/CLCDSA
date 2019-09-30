using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
namespace ABC009 {
    class MainClass {
        public static void Main(string[] args) {
            new MainClass().solve();
        }
        const int alph = 'z' - 'a' + 1;

        Scanner cin;

        int N, K;
        string S;

        int[] f, origin;

        string ans;
        void solve() {
            cin = new Scanner();

            N = cin.nextInt();
            K = cin.nextInt();
            S = cin.next();

            f = new int[alph];
            origin = new int[alph];
            for (int i = 0; i < alph; i++)
                f[i] = 0;
            for (int i = 0; i < alph; i++)
                origin[i] = 0;

            ans = "";

            //????????????
            for (int i = 0; i < N; i++) {
                f[S[i] - 'a']++;
                origin[S[i] - 'a']++;
            }

            //????????
            for (int i = 0; i < N; i++) {
                origin[S[i] - 'a']--;
                //??????
                for (int j = 0; j < alph; j++) {
                    //S?????????????
                    if (f[j] > 0) {
                        f[j]--;
                        if (S[i] != (char)(j + 'a'))
                            K--;

                        int diff = 0;

                        for (int k = 0; k < alph; k++)
                            diff += Math.Abs(origin[k] - f[k]);

                        //???++?--???????diff????
                        //??1????2????
                        if (diff / 2 <= K) {
                            ans += (char)(j + 'a');
                            break;
                        } else {

                            if (S[i] != (char)(j + 'a'))
                                K++;
                            f[j]++;
                        }
                    }
                }
            }
            Console.WriteLine(ans);
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
}