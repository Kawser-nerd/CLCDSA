using System;
using System.Linq;

class B {
    public static void Main() {
        var n = int.Parse(Console.ReadLine());
        var t = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        var total = t.Sum();
        var m = int.Parse(Console.ReadLine());
        for (int i = 0; i < m; ++i) {
            var line = Console.ReadLine().Split();
            var p = int.Parse(line[0]) - 1;
            var x = int.Parse(line[1]);
            Console.WriteLine(total - t[p] + x);
        }
    }
}