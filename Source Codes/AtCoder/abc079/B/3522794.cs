using System;
using System.IO;
using System.Collections.Generic;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder {
    public class Program {
        public static void Main() {
            int N = int.Parse(Console.ReadLine());
            long[] Ls = new long[N+1];
            Ls[0] = 2;
            Ls[1] = 1;
            for (int i = 2; i <= N; i++) {
                Ls[i] = Ls[i - 1] + Ls[i - 2];
            }
            Console.WriteLine(Ls[N]);
        }
    }
}