using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC068D {
    class Program {
        static void Main(string[] args) {
            int N = int.Parse(Console.ReadLine());
            int[] input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            Array.Sort(input);
            int even = 0;
            int odd = 0;
            int nownum = input[0];
            int nowcount = 1;
            for (int i = 1; i < N; i++) {
                if (input[i] == nownum) {
                    nowcount++;
                } else {
                    if (nowcount % 2 == 0) {
                        even++;
                    } else {
                        odd++;
                    }
                    nownum = input[i];
                    nowcount = 1;
                }
            }
            if (nowcount % 2 == 0) {
                even++;
            } else {
                odd++;
            }
            int ans = even + odd;
            if (even % 2 == 1) {
                ans--;
            }
            Console.WriteLine(ans);
        }
    }
}