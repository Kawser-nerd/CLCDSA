using System;
using System.Linq;

namespace A {
    class Program {
        static void Main (string[] args) {
            var X = Console.ReadLine ().First ();
            Console.WriteLine (X - 'A' + 1);
        }
    }
}