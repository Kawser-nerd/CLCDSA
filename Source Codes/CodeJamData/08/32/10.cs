using System;
using System.Collections.Generic;
using System.Text;

namespace Google {
    class Ugly {

        static string line;
        static int[] choice = new int[50];
        static long wynik;

        static void go(int n) {
            if (n == line.Length - 1) {

                long result = 0;
                long mult = 1;
                long current = 0;

                for (int i = n; i >= 0; i--) {
                    current += (line[i] - '0') * mult;

                    mult *= 10;
                    if (i == 0) break;
                    if (choice[i - 1] == 0) continue;
                    if (choice[i - 1] == 2) current *= -1;

                    result += current;
                    current = 0;
                    mult = 1;
                }
                result += current;
                if (((result % 2 == 0) || (result % 3 == 0) || (result % 5 == 0) || (result % 7 == 0))) wynik++;
            }
            else {
                for (int i = 0; i <= 2; i++) {
                    choice[n] = i;
                    go(n + 1);
                }
            }
        }

        static void Main(string[] args) {
              long NN = Int64.Parse(Console.ReadLine());
              for (long cs = 1; cs <= NN; cs++) {
                  line = Console.ReadLine();

                  wynik = 0;
                  go(0);

                  Console.WriteLine("Case #" + cs.ToString()+": "+wynik.ToString());
              }
        }

    }
}