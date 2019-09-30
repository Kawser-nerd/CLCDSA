using System;
using System.Linq;

namespace _20190316_01 {
    class Program {
        static void Main(string[] args) {
            var n = int.Parse(Console.ReadLine());
            var line = Console.ReadLine().Split(' ').Select(d => int.Parse(d)).ToList();
            line.Insert(0, 0);
            var ans = 0;
            for (int i = 1; i < line.Count; i++) {
                if (line[i] > line[i - 1]) {
                    ans += line[i] - line[i - 1];
                }
            }
            Console.WriteLine(ans);
        }
    }
}