using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC091A {
    class Program {
        static void Main(string[] args) {
            long[] input = Console.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
            long N = input[0];
            long M = input[1];
            long ans = 0;
            if (N == 1 && M == 1) {
                ans = 1;
            } else if (N == 1) {
                ans = M - 2;
            } else if (M == 1) {
                ans = N - 2;
            } else {
                ans = (N - 2) * (M - 2);
            }
            Console.WriteLine(ans);
        }
    }
}