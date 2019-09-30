using System;

namespace AtCoder.ABC081 {
    class B {
        static void Main() => Solve();

        static void Solve() {
#if DEBUG
            global::Common.ChangeStdIn();
#endif
            var N = int.Parse(Console.ReadLine());
            var ints = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);

            var ans = 0;
            bool endFlg = false;
            while (!endFlg) {
                for (int i = 0; i < N; i++) {
                    if (ints[i] % 2 == 1) {
                        endFlg = true;
                        break;
                    } else {
                        ints[i] /= 2;
                    }
                }

                if (!endFlg) {
                    ans++;
                }
            }

            Console.WriteLine(ans);
        }
    }
}