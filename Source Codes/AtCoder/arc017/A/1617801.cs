using System;
using System.Collections.Generic;
using System.Linq;

using static System.Console;

namespace F0rEsM8
{
    class MainClass
    {
        public static void Main (string[] args)
        {
            var n = int.Parse (ReadLine ());
            bool ok = true;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) ok = false;
            }
            if (n == 1) ok = false;

            WriteLine ((ok) ? "YES" : "NO");

        }
    }
}