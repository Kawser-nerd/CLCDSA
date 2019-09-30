using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace CJ2010R2B {
    class Program {
        private int[][] prices;
        int[] M;
        private int Solve(int n, int start, int stop, int dec) {
            if (n==0) {
                Debug.Assert(stop-start+1==2);
                if (M[start] - dec == 0 || M[stop] - dec == 0) return prices[0][start / 2];
                else return 0;
            }
            int mid = start + (stop - start + 1) / 2 - 1;
            bool noneZero = true;
            for (int i = start; i <= stop && noneZero; ++i) if (M[i] - dec == 0) { noneZero = false; }
            int result1 = int.MaxValue;
            if (noneZero) {
                // Can miss the final match
                result1 = Solve(n - 1, start, mid, dec + 1)
                    + Solve(n - 1, mid+1, stop, dec + 1);
            }
            // Not missing final match
            int price = prices[n][start >> (n + 1)];
            int result2 = Solve(n - 1, start, mid, dec) + Solve(n - 1, mid + 1, stop, dec) + price;
            return Math.Min(result1, result2);
        }
        Program() {
            int ncases = int.Parse(Console.ReadLine());
            for (int i = 0; i < ncases; ++i) {
                int P = int.Parse(Console.ReadLine());
                M = Console.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                prices = new int[P][];
                for (int j = 0; j < P; ++j) {
                    prices[j] = Console.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
                }
                Console.WriteLine("Case #{0}: {1}", i + 1, Solve(P-1,0,(1<<P)-1,0));
            }
            Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
