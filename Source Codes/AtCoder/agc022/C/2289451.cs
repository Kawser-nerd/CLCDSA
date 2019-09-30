using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC022C {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] inputA = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int[] inputB = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            bool flagg = false;
            for (int i = 0; i < N; i++) {
                if (inputA[i] != inputB[i]) {
                    flagg = true;
                }
            }
            if (flagg) {
                bool[,] dp = new bool[N, 51];
                for (int i = 0; i < N; i++) {
                    dp[i, inputB[i]] = true;
                }
                int max = -1;
                //for (int i = 1; i <= 25; i++) {
                for (int i = 1; i <= 50; i++) {
                    for (int j = 0; j < N; j++) {
                        for (int k = 0; k < 51; k++) {
                            if (dp[j, k % i]) {
                                dp[j, k] = true;
                            }
                        }
                    }
                    bool flag = true;
                    for (int j = 0; j < N; j++) {
                        if (!dp[j, inputA[j]]) {
                            flag = false;
                        }
                    }
                    if (flag) {
                        max = i;
                        break;
                    }
                }
                bool ok = (max == -1) ? false : true;
                long ans = 0;
                if (ok) {
                    bool[] flags = Enumerable.Repeat(true, max).ToArray();
                    for (int l = max; l >= 1; l--) {
                        dp = new bool[N, 51];
                        for (int i = 0; i < N; i++) {
                            dp[i, inputB[i]] = true;
                        }
                        for (int i = 1; i <= max; i++) {
                            if (i != max) {
                                if (i == l || !flags[i - 1]) {
                                    continue;
                                }
                            }
                            //Console.WriteLine(i);
                            for (int j = 0; j < N; j++) {
                                for (int k = 0; k < 51; k++) {
                                    if (dp[j, k % i]) {
                                        dp[j, k] = true;
                                    }
                                }
                            }
                        }
                        bool flag = true;
                        for (int j = 0; j < N; j++) {
                            if (!dp[j, inputA[j]]) {
                                flag = false;
                            }
                        }
                        //Console.WriteLine(flag);
                        if (flag) {
                            flags[l - 1] = false;
                        }
                    }
                    for (int i = 0; i < max; i++) {
                        //Console.WriteLine(flags[max - i - 1]);
                        if (i == 0 || flags[max - i - 1]) {
                            ans = (ans + 1) << 1;
                        } else {
                            ans = ans << 1;
                        }
                    }
                }
                if (ok) {
                    Console.WriteLine(ans);
                } else {
                    Console.WriteLine(-1);
                }
            } else {
                Console.WriteLine(0);
            }
        }

        //n????????????
        private static int IsPrime(int n) {
            for (int i = 2; i < Math.Sqrt(n); i++) {
                if (n % i == 0) {
                    return i;
                }
            }
            return -1;
        }

        //????????????
        class Edge {
            public int to;
            public int cost;
        }
    }
}