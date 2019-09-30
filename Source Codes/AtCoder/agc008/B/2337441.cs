using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC008B {
    class Program {
        static void Main(string[] args) {
            int[] NKinput = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int N = NKinput[0];
            int K = NKinput[1];
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            long sum = 0;
            int[] minus = new int[N];
            int[] plus = new int[N];
            for (int i = 0; i < N; i++) {
                if (input[i] < 0) {
                    minus[i] = input[i];
                } else {
                    sum += input[i];
                    plus[i] = input[i];
                }
            }
            long msum = 0;
            long psum = 0;
            for (int i = 0; i < K; i++) {
                psum += plus[i];
                msum += minus[i];
            }
            long min = Math.Min(psum, msum * (-1));
            for (int i = 0; i < N - K; i++) {
                psum += plus[K + i] - plus[i];
                if (psum < min) {
                    min = psum;
                }
                msum += minus[K + i] - minus[i];
                if (msum * (-1) < min) {
                    min = msum * (-1);
                }
            }
            Console.WriteLine(sum - min);
        }
    }
}