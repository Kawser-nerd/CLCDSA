using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC011B {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Array.Sort(input);
            long[] sum = new long[N];
            sum[0] = input[0];
            for (int i = 1; i < N; i++) {
                sum[i] = sum[i - 1] + input[i];
            }
            int ans = 1;
            for (int i = N - 2; i >= 0; i--) {
                if (sum[i] * 2 >= input[i + 1]) {
                    ans++;
                } else {
                    break;
                }
            }
            Console.WriteLine(ans);
        }
    }
}