using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC093C {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int allMoney = 0;
            int[] difs = new int[N];
            for (int i = 0; i < N; i++) {
                int prev = (i == 0) ? 0 : input[i - 1];
                int next = (i == N - 1) ? 0 : input[i + 1];
                allMoney += Math.Abs(input[i] - prev);
                difs[i] = Math.Abs(input[i] - prev) + Math.Abs(next - input[i]) - Math.Abs(next - prev);
            }
            allMoney += Math.Abs(input[N - 1]);
            for(int i = 0; i < N; i++) {
                Console.WriteLine(allMoney - difs[i]);
            }
        }
    }
}