using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var S = Console.ReadLine ();
            var head = char.ToUpper (S.First ());
            var body = String.Concat (S.Skip (1).Select (c => char.ToLower (c)));
            Console.WriteLine (head + body);
        }
    }
}