using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactorsOfFactorial {
    class Program {
        static void Main(string[] args) {
            var n = int.Parse(Console.ReadLine());
            var a = new int[n+1];
            long ans = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 2; j <= n; j++) {
                    if (IsPrime(j)) {
                        var tmp = i;
                        while (tmp % j == 0) {
                            tmp /= j;
                            a[j]++;
                        }
                    }
                }
            }
            for (int i = 0; i <= n; i++) {
                if (a[i] > 0) {
                    ans *= (a[i] + 1);
                    ans %= (long)Math.Pow(10, 9) + 7;
                }
            }
            Console.WriteLine(ans);
        }
        static bool IsPrime(int x) {
            if (x == 1) {
                return false;
            }
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
}