using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC080C {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            int four = 0;
            int two = 0;
            int one = 0;
            for (int i = 0; i < N; i++) {
                int num = input[i];
                if (num % 4 == 0) {
                    four++;
                } else if (num % 2 == 0) {
                    two++;
                } else {
                    one++;
                }
            }
            bool ok = false;
            if (two == 0) {
                if(four >= one - 1) {
                    ok = true;
                }
            } else {
                if(four >= one) {
                    ok = true;
                }
            }
            if (ok) {
                Console.WriteLine("Yes");
            } else {
                Console.WriteLine("No");
            }
        }
    }
}