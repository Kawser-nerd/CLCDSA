using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC007B {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int[] rank = new int[N];
            for (int i = 0; i < N; i++) {
                rank[input[i] - 1] = i;
            }
            int[] A = new int[N];
            int[] B = new int[N];
            A[0] = 1;
            B[0] = 1000000000;
            for (int i = 1; i < N; i++) {
                int pre = rank[i - 1];
                int nex = rank[i];
                if (pre < nex) {
                    A[i] = A[i - 1] + 1 + (nex - pre);
                    B[i] = B[i - 1] - 1;
                } else {
                    A[i] = A[i - 1] + 1;
                    B[i] = B[i - 1] - 1 - (pre - nex);
                }
            }
            Console.WriteLine(String.Join(" ", A));
            Console.WriteLine(String.Join(" ", B));
        }
    }
}