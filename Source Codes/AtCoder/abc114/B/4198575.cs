using System;

namespace AtCoder.ABC114 {
    class B {
        static void Main() => Solve();

        static void Solve() {
#if DEBUG
            global::Common.ChangeStdIn();
#endif
            var s = Console.ReadLine();
            var ans = 1000;
            for (int i = 0; i < s.Length - 2; i++) {
                var val = int.Parse(s[i].ToString()) * 100 +
                          int.Parse(s[i + 1].ToString()) * 10 +
                          int.Parse(s[i + 2].ToString());
                ans = Math.Min(ans, Math.Abs(753 - val));
            }

            Console.WriteLine(ans);
        }
    }
}