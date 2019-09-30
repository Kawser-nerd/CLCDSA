using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC095C {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int[] inputb = new int[N];
            for(int i = 0; i < N; i++) {
                inputb[i] = input[i];
            }
            Array.Sort(inputb);
            int low = inputb[N / 2 - 1];
            int high = inputb[N / 2];
            for(int i = 0; i < N; i++) {
                int del = input[i];
                int ans = -1;
                if(del <= low) {
                    ans = high;
                } else {
                    ans = low;
                }
                Console.WriteLine(ans);
            }
        }
    }
}