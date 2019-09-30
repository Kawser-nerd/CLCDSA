using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC006B {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = input[0];
            int x = input[1];
            if (x == 1 || x == 2 * N - 1) {
                Console.WriteLine("No");
            } else {
                Console.WriteLine("Yes");
                if (N == 2) {
                    Console.WriteLine(1);
                    Console.WriteLine(2);
                    Console.WriteLine(3);
                } else {
                    int pair = x - 1;
                    int high = x + 2;
                    int low = x + 1;
                    int under = x - 1;
                    if (x == 2 * N - 2) {
                        pair = x + 1;
                        high = x - 1;
                        low = x - 2;
                        under = x - 2;
                    }
                    int mark = 1;
                    for (int i = 0; i < 2 * N - 1; i++) {
                        if (i == N - 2) {
                            Console.WriteLine(low);
                        } else if (i == N - 1) {
                            Console.WriteLine(x);
                        } else if (i == N) {
                            Console.WriteLine(pair);
                        } else if (i == N + 1) {
                            Console.WriteLine(high);
                        } else {
                            if (mark == under) {
                                mark += 4;
                            }
                            Console.WriteLine(mark);
                            mark++;
                        }
                    }
                }
            }
        }
    }
}