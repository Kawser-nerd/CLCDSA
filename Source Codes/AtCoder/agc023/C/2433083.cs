using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC023C {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            long[] fact = new long[N];
            long[] invfact = new long[N];
            fact[0] = 1;
            invfact[0] = 1;
            for (int i = 1; i < N; i++) {
                fact[i] = multiply(fact[i - 1], i);
                invfact[i] = divide(1, fact[i]);
            }
            long[] nums = new long[N];
            for (int i = 1; i < N; i++) {
                long conbi = 0;
                if (i - 1 >= N - 1 - i) {
                    conbi = multiply(fact[i - 1], multiply(invfact[N - 1 - i], invfact[(i - 1) - (N - 1 - i)]));
                }
                nums[i] = multiply(multiply(fact[i], fact[N - 1 - i]), conbi);
            }
            long ans = 0;
            for (int i = 1; i < N; i++) {
                ans = (ans + multiply((nums[i] - nums[i - 1] + mod), i)) % mod;
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

        private static long divide(long x, long y) {
            return multiply(x, power(y, mod - 2));
        }
    }
}