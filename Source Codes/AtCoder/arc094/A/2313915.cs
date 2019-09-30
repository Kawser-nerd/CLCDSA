using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC094C {
    class Program {
        static void Main(string[] args) {
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Array.Sort(input);
            int A = input[0];
            int B = input[1];
            int C = input[2];
            int fir = C - B;
            int sec = -1000;
            if ((C - (A + fir)) % 2 == 0) {
                sec = (C - (A + fir)) / 2;
            } else {
                sec = (C - (A + fir)) / 2 + 2;
            }
            Console.WriteLine(fir + sec);
        }
    }
}