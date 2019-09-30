using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC094D {
    class Program {
        static void Main(string[] args) {
            int Q = int.Parse(Console.ReadLine());
            for(int i = 0; i < Q; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                Array.Sort(input);
                long A = input[0];
                long B = input[1];
                long mul = A * B;
                long N = (long)Math.Floor(Math.Sqrt(mul));
                long ans = -1;
                if(N * N == mul) {
                    ans = (N - 1) * 2;
                    if(A < N) {
                        ans--;
                    }
                } else {
                    ans = N * 2 - 2;
                }
                if(N * (N + 1) < mul) {
                    ans++;
                }
                Console.WriteLine(ans);
            }
        }
    }
}