using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication34 {
    class Program {
        static void Main(string[] args) {
            string[] str = Console.ReadLine().Split(' ');
            int h1 = int.Parse(str[0]);
            int w1 = int.Parse(str[1]);
            string[] str2 = Console.ReadLine().Split(' ');
            int h2 = int.Parse(str2[0]);
            int w2 = int.Parse(str2[1]);
            var result = Method(h1, w1, h2, w2);
            if (result) {
                Console.WriteLine("YES");
            } else {
                Console.WriteLine("NO");
            }
        }
        private static bool Method(int h1, int w1, int h2, int w2) {


            if (h1 == h2 || h1 == w2) {
                return true;
            } else if (w1 == h2 || w1 == w2) {
                return true;
            }
            return false;
        }
    }
}