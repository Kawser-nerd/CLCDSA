using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC022B {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] ans = new int[N];
            if (N == 3) {
                ans[0] = 2;
                ans[1] = 5;
                ans[2] = 63;
            } else {
                int div = N / 8;
                int rem = N % 8;
                for (int i = 0; i < div; i++) {
                    ans[i * 8] = 12 * i + 2;
                    ans[i * 8 + 1] = 12 * i + 3;
                    ans[i * 8 + 2] = 12 * i + 4;
                    ans[i * 8 + 3] = 12 * i + 6;
                    ans[i * 8 + 4] = 12 * i + 8;
                    ans[i * 8 + 5] = 12 * i + 9;
                    ans[i * 8 + 6] = 12 * i + 10;
                    ans[i * 8 + 7] = 12 * i + 12;
                }
                switch (rem) {
                    case 0:
                        break;
                    case 1:
                        ans[div * 8] = 12 * div + 6;
                        break;
                    case 2:
                        ans[div * 8] = 12 * div + 3;
                        ans[div * 8 + 1] = 12 * div + 9;
                        break;
                    case 3:
                        ans[div * 8] = 12 * div + 3;
                        ans[div * 8 + 1] = 12 * div + 9;
                        ans[div * 8 + 2] = 12 * div + 6;
                        break;
                    case 4:
                        ans[div * 8] = 12 * div + 3;
                        ans[div * 8 + 1] = 12 * div + 9;
                        ans[div * 8 + 2] = 12 * div + 2;
                        ans[div * 8 + 3] = 12 * div + 4;
                        break;
                    case 5:
                        ans[div * 8] = 12 * div + 3;
                        ans[div * 8 + 1] = 12 * div + 9;
                        ans[div * 8 + 2] = 12 * div + 2;
                        ans[div * 8 + 3] = 12 * div + 4;
                        ans[div * 8 + 4] = 12 * div + 6;
                        break;
                    case 6:
                        ans[div * 8] = 12 * div + 3;
                        ans[div * 8 + 1] = 12 * div + 9;
                        ans[div * 8 + 2] = 12 * div + 2;
                        ans[div * 8 + 3] = 12 * div + 4;
                        ans[div * 8 + 4] = 12 * div + 8;
                        ans[div * 8 + 5] = 12 * div + 10;
                        break;
                    case 7:
                        ans[div * 8] = 12 * div + 3;
                        ans[div * 8 + 1] = 12 * div + 9;
                        ans[div * 8 + 2] = 12 * div + 2;
                        ans[div * 8 + 3] = 12 * div + 4;
                        ans[div * 8 + 4] = 12 * div + 8;
                        ans[div * 8 + 5] = 12 * div + 10;
                        ans[div * 8 + 6] = 12 * div + 6;
                        break;
                }
            }
            Console.WriteLine(string.Join(" ", ans));
        }
    }
}