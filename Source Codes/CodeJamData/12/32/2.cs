using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ20121CB {
    class Program {
        double[] Solve(double D, int N, int A, double[,] tx, double[] Acc) {
            double[] beginAt = new double[A];
            double prevt = 0, prevx = 0;
            for (int i = 0; i < N; ++i) {
                if (tx[i, 1] > D) {
                    double t = (D - prevx) / (tx[i, 1] - prevx) * (tx[i, 0] - prevt) + prevt;
                    tx[i, 0] = t;
                    tx[i, 1] = D;
                    N = i + 1;
                    break;
                }
                prevt = tx[i, 0]; prevx = tx[i, 1];
            }
            for (int ai=0; ai<A; ++ai) {
                double a = Acc[ai];
                for (int i = 0; i < N; ++i) {
                    // should be at tx[i,1] or less by time tx[i,0]
                    // D(ti) <= xi
                    double minB = tx[i, 0] - Math.Sqrt(2 * tx[i, 1] / a);
                    if (minB > beginAt[ai]) beginAt[ai] = minB;
                }
            }
            double[] result = new double[A];
            for (int ai = 0; ai < A; ++ai) {
                result[ai] = beginAt[ai] + Math.Sqrt(2 * D / Acc[ai]);
            }
            return result;
        }
        Program() {
            int T = int.Parse(Console.ReadLine());
            for (int tt = 0; tt < T; ++tt) {
                double[] DNA = Console.ReadLine().Split().Select(p => double.Parse(p)).ToArray();
                double D = DNA[0];
                int N = (int)(DNA[1] + 0.5), A = (int)(DNA[2] + 0.5);
                double[,] tx = new double[N, 2];
                for (int i = 0; i < N; ++i) {
                    double[] inp = Console.ReadLine().Split().Select(p => double.Parse(p)).ToArray();
                    tx[i, 0] = inp[0]; tx[i, 1] = inp[1];
                }
                double[] Acc = Console.ReadLine().Split().Select(p => double.Parse(p)).ToArray();
                double[] times = Solve(D, N, A, tx, Acc);
                Console.WriteLine("Case #{0}:", tt + 1);
                foreach (double time in times) {
                    Console.WriteLine(time);
                }
            }
            //Console.ReadLine();
        }
        static void Main(string[] args) {
            new Program();
        }
    }
}
