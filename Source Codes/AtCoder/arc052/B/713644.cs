using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AtCoder
{
    class ARC052
    {

        static void Main(string[] args) {
            string[] spl = Console.ReadLine().Split(' ');
            int N = int.Parse(spl[0]);
            int Q = int.Parse(spl[1]);
            int[] X = new int[N];
            int[] R = new int[N];
            int[] H = new int[N];
            for (int i = 0; i < N; i++) {
                spl = Console.ReadLine().Split(' ');
                X[i] = int.Parse(spl[0]);
                R[i] = int.Parse(spl[1]);
                H[i] = int.Parse(spl[2]);
            }
            for (int i = 0; i < Q; i++) {
                spl = Console.ReadLine().Split(' ');
                int A = int.Parse(spl[0]);
                int B = int.Parse(spl[1]);
                double res = 0;
                for (int j = 0; j < N; j++) { // ?? X, R, H
                    bool bottom = (X[j] <= A) && (A <= X[j] + H[j]);
                    bool top = (X[j] <= B) && (B <= X[j] + H[j]);
                    if (bottom && top) {
                        res += V(H[j], R[j], X[j] + H[j] - A) -
                               V(H[j], R[j], X[j] + H[j] - B);
                    }
                    else if (bottom) {
                        res += V(H[j], R[j], X[j] + H[j] - A);
                    }
                    else if (top) {
                        res += V(H[j], R[j], H[j]) -
                               V(H[j], R[j], X[j] + H[j] - B);
                    }
                    else if ((A <= X[j]) && (X[j] + H[j] <= B)) {
                        res += V(H[j], R[j], H[j]);
                    }
                }
                Console.WriteLine(res);
            }
        }

        private static double V(double h, double r, double h2) {
            return Math.PI * r * r * h / 3.0 * (h2 / h) * (h2 / h) * (h2 / h);
        }
}
}