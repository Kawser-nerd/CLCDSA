using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC094E {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            long min = 1000000000000;
            long ans = 0;
            bool ok = false;
            for(int i = 0; i < N; i++) {
                int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                int A = input[0];
                int B = input[1];
                if(A != B) {
                    ok = true;
                }
                ans += A;
                if(A > B) {
                    if(B < min) {
                        min = B;
                    }
                }
            }
            if (ok) {
                Console.WriteLine(ans - min);
            } else {
                Console.WriteLine(0);
            }
        }
    }
}