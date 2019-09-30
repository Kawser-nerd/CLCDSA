using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CookieExchanges {
    class Program {
        static void Main(string[] args) {
            string[] s = Console.ReadLine().Split();
            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);
            int c = int.Parse(s[2]);
            int ans = 0;
            if (a == b && b == c) {
                if (a % 2 == 0) {
                    Console.WriteLine(-1);
                    return;
                }
                else {
                    Console.WriteLine(0);
                    return;
                }
            }
            while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
                int tmpA = a / 2, tmpB = b / 2, tmpC = c / 2;
                a = tmpB + tmpC;
                b = tmpA + tmpC;
                c = tmpA + tmpB;
                ans++;
            }
            Console.WriteLine(ans);
        }
    }
}