using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC095D {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Array.Sort(input);
            int high = input[N - 1];
            int low = -1;
            if (high % 2 == 0) {
                for (int i = 0; i < N; i++) {
                    int now = input[i];
                    int tar = high / 2;
                    if (Math.Abs(tar - low) > Math.Abs(tar - now)) {
                        low = now;
                    }
                }
            } else {
                for (int i = 0; i < N; i++) {
                    int now = input[i];
                    int tar = high / 2;
                    if(now <= tar) {
                        if (Math.Abs(tar - low) > Math.Abs(tar - now)) {
                            low = now;
                        }
                    } else {
                        if (Math.Abs(tar + 1 - low) > Math.Abs(tar + 1 - now)) {
                            low = now;
                        }
                    }
                }
            }
            Console.WriteLine(high.ToString() + " " + low.ToString());
        }
    }
}