using System;

namespace AtCoder.ABC114 {
    class A {
        static void Main() => Solve();

        static void Solve() {
#if DEBUG
            global::Common.ChangeStdIn();
#endif
            var x = int.Parse(Console.ReadLine());
            if (x == 3 || x == 5 || x == 7) {
                Console.WriteLine("YES");
            } else {
                Console.WriteLine("NO");
            }
        }
    }
}