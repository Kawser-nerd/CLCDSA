using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC019A {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int Q = input[0];
            int H = input[1];
            int S = input[2];
            int D = input[3];
            long N = int.Parse(Console.ReadLine());
            long[] four = { Q * 8, H * 4, S * 2, D };
            long[] three = { Q * 4, H * 2, S };
            long ans = 0;
            long num = N / 2;
            ans += four.Min() * num;
            N -= num * 2;
            ans += three.Min() * N;
            Console.WriteLine(ans);
        }
    }
}