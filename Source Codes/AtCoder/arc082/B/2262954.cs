using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC082D {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (input[i] == i + 1) {
                    count++;
                    i++;
                }
            }
            Console.WriteLine(count);
        }
    }
}