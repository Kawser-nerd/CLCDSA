using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC091C {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = input[0];
            int A = input[1];
            int B = input[2];
            int lowAnum = (N + B - 1) / B;
            int highAnum = N - B + 1;
            bool ok = true;
            if (A < lowAnum || highAnum < A) {
                ok = false;
            }
            if (ok) {
                int point = 0;
                bool mark = true;
                for (int i = 0; i < lowAnum; i++) {
                    for (int j = 1; j <= B; j++) {
                        int k = i * B + j;
                        if (N - k + (i + 1) == A) {
                            point = k;
                            mark = false;
                            break;
                        }
                    }
                    if (!mark) {
                        break;
                    }
                }
                int[] ans = new int[N];
                int bnum = B;
                int varnum = B;
                int first = B - (point % B);
                int second = B - first;
                int third = N - point;
                int pointer = 0;
                for (int i = 0; i < first; i++) {
                    for (int j = 0; j < (point / B); j++) {
                        ans[pointer] = varnum;
                        varnum += B;
                        pointer++;
                    }
                    bnum--;
                    varnum = bnum;
                }
                for (int i = 0; i < second; i++) {
                    for (int j = 0; j < (point / B) + 1; j++) {
                        ans[pointer] = varnum;
                        varnum += B;
                        pointer++;
                    }
                    bnum--;
                    varnum = bnum;
                }
                for(int i = 0; i < third; i++) {
                    ans[pointer] = point + i + 1;
                    pointer++;
                }
                Console.WriteLine(string.Join(" ", ans));
            } else {
                Console.WriteLine(-1);
            }
        }
    }
}