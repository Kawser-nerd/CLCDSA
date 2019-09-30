using System;

namespace C_SccPuzzle {
    class Program {
        static void Main(string[] args) {
            var str = Console.ReadLine().Split(' ');
            var N = long.Parse(str[0]);
            var M = long.Parse(str[1]);
            var ans = Math.Min(N, M / 2);
            ans += Math.Max(0, (M - 2 * ans) / 4);
            Console.WriteLine(ans);
        }
    }
}