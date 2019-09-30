using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CJ20101BC {
    class Program {
        const int MOD = 100003;
        const int UB = 500;
        long Choose(long n, long k) {
            if (k > n) return 0;
            long result = 1;

            for (int i = (int)Math.Max(k, n - k) + 1; i <= n; ++i)
                result = (result * i) % MOD;

            for (int i = 2; i <= Math.Min(k, n - k); ++i)
                result = (result * ModularInverse(i, MOD)) % MOD;

            return result;
        }
        private int[,] solutions = new int[UB + 1, UB + 1];
        private long solve(int n, int i) {
            if (solutions[n, i] >= 0) return solutions[n, i];
            // n is stored at rank i
            if (i == 1) return 1;
            if (i == n - 1) return 1;
            long result = 0;
            for (int a = 1; a <= i - 1; ++a) {
                // i is stored at rank a
                // between a+1 to i-1, are numbers i+1 to n-1
                long fillers = Choose(n - i - 1, i - a - 1);
                if (fillers > 0) {
                    result += ((long)solve(i, a) * fillers) % MOD;
                    result = result % MOD;
                }
            }
            solutions[n, i] = (int)result;
            return result;
        }
        private long solve1(int n) {
            long result = 0;
            for (int i = 1; i <= n - 1; ++i)
                result = (result + solve(n, i)) % MOD;
            return result;
        }
        public int ModularInverse(int px, int py) {
            int x = px;
            int y = py;

            //Setup initial variables
            //Maintain throughout that ax * px + bx * py = x and that ay * px + by * py = y
            int ax = 1;
            int ay = 0;
            int bx = 0;
            int by = 1;

            //Perform extended gcd
            while (x>0) {
                if (x <= y) {
                    int m = y / x;
                    y -= m * x;
                    ay -= ax * m;
                    by -= bx * m;
                }
                else {
                    int t;
                    //swap(x, y);
                    t = x; x = y; y = t;
                    //swap(ax, ay);
                    t = ax; ax = ay; ay = t;
                    //swap(bx, by);
                    t = bx; bx = by; by = t;
                }
            }

            //you can assert that ay * px + by * py = y = gcd(px, py)
            //you can assert that ax * px + bx * py = x = 0

            //If we're taking the modular inverse of px (mod py), then for it to exist gcd(px, py) = 1
            //If it does exist, it is given by ay (mod py)
            int inverse = ay % py;
            if (inverse < 0) inverse += py;
            return inverse;
        }
        public Program() {
            for (int i = 0; i < UB+1; ++i)
                for (int j = 0; j < UB+1; ++j)
                    solutions[i, j] = -1;
            // Preprocess
            solve1(UB);
            Console.WriteLine("Ready...");
            using (StreamWriter outfile = new StreamWriter(@"C:\Arnab\Progs\dotNet\CJ20101BC\CJ20101BC\bin\Debug\output.txt")) {
                int ncases = int.Parse(Console.ReadLine());
                for (int i = 0; i < ncases; ++i) {
                    int input = int.Parse(Console.ReadLine());
                    outfile.WriteLine("Case #{0}: {1}", i + 1, solve1(input));
                }
            }
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
