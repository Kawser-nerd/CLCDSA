using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC061D {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int H = input[0];
            int W = input[1];
            int N = input[2];
            List<long> list = new List<long>();
            for (int i = 0; i < N; i++) {
                int[] inputb = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                for (int j = inputb[0] - 1; j <= inputb[0] + 1; j++) {
                    for (int k = inputb[1] - 1; k <= inputb[1] + 1; k++) {
                        if (j >= 2 && j <= H - 1 && k >= 2 && k <= W - 1) {
                            list.Add((long)(j - 1) * W + k);
                        }
                    }
                }
            }
            list.Sort();
            long temp = 0;
            int num = 0;
            long[] ans = new long[10];
            ans[0] = (long)(H - 2) * (W - 2);
            for (int i = 0; i < list.Count; i++) {
                if (list[i] != temp) {
                    if (temp != 0) {
                        ans[num]++;
                        ans[0]--;
                    }
                    temp = list[i];
                    num = 1;
                } else {
                    num++;
                }
            }
            ans[num]++;
            ans[0]--;
            for (int i = 0; i < 10; i++) {
                Console.WriteLine(ans[i]);
            }
        }
    }
}