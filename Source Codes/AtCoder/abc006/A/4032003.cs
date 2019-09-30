using System;

namespace A {
    class Program {
        static void Main (string[] args) {
            var n = int.Parse (Console.ReadLine ());

            if (n % 3 == 0) {
                Console.WriteLine ("YES");
            } else {
                Console.WriteLine ("NO");
            }
        }
    }
}