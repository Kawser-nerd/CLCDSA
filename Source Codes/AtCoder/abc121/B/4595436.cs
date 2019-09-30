using System;
using System.Linq;

namespace CanYouSolveThis {
    class Program {
        static void Main(string[] args) {
            var input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var n = input[0];
            var m = input[1];
            var c = input[2];

            var b = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();

            var result = 0;

            for (int i = 0; i < n; i++) {
                var ai = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += ai[j] * b[j];
                }

                if (sum + c > 0) result++;
            }

            Console.WriteLine(result);
        }
    }
}