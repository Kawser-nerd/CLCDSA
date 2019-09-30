using System;

namespace b119B {
    class Program {
        static void Main(string[] args) {
            var n = int.Parse(Console.ReadLine());
            var res = 0.0;
            for (int i = 0; i < n; i++) {
                var input = Console.ReadLine().Split(' ');
                if (input[1] == "JPY") {
                    res += int.Parse(input[0]);
                } else {
                    res += 380000.0 * Double.Parse(input[0]);
                }
            }

            Console.WriteLine(res);
        }
    }
}