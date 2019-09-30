using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1 {
    class Program {
        static void Main(string[] args) {
            var s = Console.ReadLine().Split();
            var n = long.Parse(s[0]);
            var l = long.Parse(s[1]);
            var a = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var pos = new long();
            bool flag = true;
            for (int i = 0; i < n - 1; i++) {
                if (a[i + 1] + a[i] >= l) {
                    flag = false;
                    pos = i;
                    break;
                }
            }
            if (!flag) {
                Console.WriteLine("Possible");
                for (long i = 0; i < pos; i++) {
                    Console.WriteLine(i + 1);
                }
                for (long i = n - 1; i > pos; i--) {
                    Console.WriteLine(i);
                }
            }
            else {
                Console.WriteLine("Impossible");
            }
        }
    }
}