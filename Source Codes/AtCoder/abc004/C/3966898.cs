using System;
using System.Collections.Generic;
using System.Linq;

namespace c {
    class Program {
        static void Main (string[] args) {
            // input
            var n = int.Parse (Console.ReadLine ()) % (5 * 6);
            // calc
            var k = n / 5;
            var shiftedCards = Enumerable.Range (0, 6).Select (x => (((x + k) % 6) + 1).ToString ()).ToList ();
            var swapedCards = new List<string> (shiftedCards);

            foreach (var i in Enumerable.Range (0, n % 5)) {
                var swapping = swapedCards[i % 5];
                swapedCards[i % 5] = swapedCards[i % 5 + 1];
                swapedCards[i % 5 + 1] = swapping;
            }

            // output
            Console.WriteLine (String.Join ("", swapedCards));
        }
    }
}