using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder {
    class Program {
        static List<int> A = new List<int>();
        static int K;

        static void Main() {
            Read();
            Shori();
        }
        static void Shori() {
            A.Add(1);
            A.Add(1);
            for(int i = 1; i <= K; i++) {
                A.Add(A[i] + A[i - 1]);
            }
            Console.WriteLine(A[K - 1] + " " + A[K]);
        }

        static void Read() {
            K = int.Parse(Console.ReadLine());
        }
        
    }
}