using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC017B {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int n = input[0] - 1;
            int A = input[1];
            int B = input[2];
            int C = input[3];
            int D = input[4];
            int target = Math.Abs(B - A);
            bool ok = true;
            int first = (target + D - 1) / D;
            if (first > n) {
                ok = false;
            } else {
                int remain = n - first;
                if (remain % 2 == 0) {
                    int fhigh = first * D;
                    int flow = first * C;
                    if (flow <= target) {
                        ok = true;
                    } else {
                        if(D - C == 0) {
                            ok = false;
                        } else {
                            int diff = flow - target;
                            int p = (diff + (D - C) - 1) / (D - C);
                            if (p <= remain / 2) {
                                ok = true;
                            } else {
                                ok = false;
                            }
                        }
                    }
                } else {
                    int fhigh = (first + 1) * D;
                    int flow = (first + 1) * C;
                    if (flow <= target) {
                        ok = true;
                    } else {
                        if(D - C == 0) {
                            ok = false;
                        } else {
                            int diff = target - (first - 1) * D;
                            int p = (diff + (D - C) - 1) / (D - C);
                            if (p <= (remain + 1) / 2) {
                                ok = true;
                            } else {
                                ok = false;
                            }
                        }
                    }
                }
            }
            if (ok) {
                Console.WriteLine("YES");
            } else {
                Console.WriteLine("NO");
            }
        }
    }
}