using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC058D {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int H = input[0];
            int W = input[1];
            int A = input[2];
            int B = input[3];
            long ans = 0;
            long[] fact = new long[H + W];
            long[] invfact = new long[H + W];
            fact[0] = 1;
            invfact[0] = 1;
            for (int i = 1; i < H + W; i++) {
                fact[i] = multiply(fact[i - 1], i);
                invfact[i] = divide(1, fact[i]);
            }
            for (int i = 1; i <= H - A; i++) {
                long conbia = multiply(multiply(fact[B - 1 + i - 1], invfact[i - 1]), invfact[B - 1]);
                long conbib = multiply(multiply(fact[W - B - 1 + H - i], invfact[H - i]), invfact[W - B - 1]);
                ans = (ans + multiply(conbia, conbib)) % mod;
            }
            Console.WriteLine(ans);
        }

        //????
        const long mod = 1000000007;

        //mod???x×y??
        private static long multiply(long x, long y) {
            return (x % mod) * (y % mod) % mod;
        }

        //mod???x?y???
        private static long power(long x, long y) {
            if (y == 0) {
                return 1;
            } else if (y == 1) {
                return x % mod;
            } else if (y % 2 == 0) {
                long p = power(x, y / 2);
                return p * p % mod;
            } else {
                long p = power(x, y / 2);
                return (p * p) % mod * (x % mod) % mod;
            }
        }

        //mod???x÷y??????????????y?mod-2??????
        private static long divide(long x, long y) {
            return multiply(x, power(y, mod - 2));
        }
    }
}