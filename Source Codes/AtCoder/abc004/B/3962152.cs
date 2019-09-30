using System;
using System.Collections.Generic;
using System.Linq;

namespace B {
    class Program {
        static void Main (string[] args) {
            var c = new List<List<char>> ();
            foreach (var i in Enumerable.Range (0, 4)) {
                c.Add (Console.ReadLine ().ToCharArray ().Where (t => t != ' ').ToList ());
            }

            c = Enumerable.Reverse (c.Select (c1 => Enumerable.Reverse (c1).ToList ())).ToList ();

            foreach (var cCol in c) {
                foreach (var cRow in cCol) {
                    Console.Write ($"{cRow} ");
                }
                Console.Write ("\n");
            }
        }
    }
}