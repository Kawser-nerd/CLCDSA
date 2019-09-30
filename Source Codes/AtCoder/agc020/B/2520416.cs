using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC020B {
    class Program {
        static void Main(string[] args) {
            int K = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            bool ok = true;
            if (input[K - 1] != 2) {
                ok = false;
            }
            long min = 2;
            long max = 3;
            for (int i = 1; i < K; i++) {
                if (!ok) {
                    break;
                }
                int num = input[K - 1 - i];
                if (num >= max * 2) {
                    ok = false;
                } else {
                    if (num > min) {
                        min = num;
                    } else {
                        min = (min + num - 1) / num * num;
                    }
                    max = (max / num) * num + (num - 1);
                }
            }
            if(min > max) {
                ok = false;
            }
            if (ok) {
                Console.WriteLine(min.ToString() + " " + max.ToString());
            } else {
                Console.WriteLine(-1);
            }
        }
    }
}