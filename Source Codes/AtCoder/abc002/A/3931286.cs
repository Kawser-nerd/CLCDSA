using System;

namespace A {
    class Program {
        static void Main (string[] args) {
            var words = Console.ReadLine ().Split (' ');
            var x = int.Parse (words[0]);
            var y = int.Parse (words[1]);
            Console.WriteLine (Math.Max (x, y));
        }
    }
}