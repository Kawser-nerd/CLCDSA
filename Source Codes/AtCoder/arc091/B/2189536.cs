using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC091B {
    class Program {
        static void Main(string[] args) {
            long[] input = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
            long N = input[0];
            long K = input[1];
            long ans = 0;
            if(K == 0) {
                ans = N * N;
            } else {
                for (int b = 1; b <= N; b++) {
                    if (b <= K) {
                        continue;
                    }
                    long num = N / b;
                    ans += num * (b - K);
                    long remain = N % b;
                    if (remain >= K) {
                        ans += remain - K + 1;
                    }
                }
            }
            Console.WriteLine(ans);
        }
    }
}