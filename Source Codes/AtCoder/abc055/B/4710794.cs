using System;
using System.Collections.Generic;
using static System.Console;
using System.Linq;

namespace ConsoleApp2
{
    class Program {
        static void Main(string[] Args) {
            long res = 1;
            int N = int.Parse(ReadLine());
            int mod = 1000000007;
            for (int i = 1; i <= N; i++) {
                res *= i;
                res %= mod;
            }

            WriteLine(res);

            ReadLine();
        }
    }
}