using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var ABC = ReadInts ();
            var A = ABC[0];
            var B = ABC[1];
            var C = ABC[2];

            if (A + B == C && A - B == C) {
                Console.WriteLine ("?");
            } else if (A + B == C) {
                Console.WriteLine ("+");
            } else if (A - B == C) {
                Console.WriteLine ("-");
            } else {
                Console.WriteLine ("!");
            }
        }
        static int ReadInt () {
            return int.Parse (Console.ReadLine ());
        }
        static List<int> ReadInts () {
            return Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
        }
        static List<List<int>> ReadSequence (int n) {
            /*
            ???
            A1 B1
            A2 B2
            ...
            An Bn

            ???
            [[A1,A2,...,An], [B1,B2,...,Bn]]
            */
            var seq = Enumerable.Range (0, n).Select (i => ReadInts ()).ToList ();
            return Enumerable.Range (0, seq.First ().Count ()).Select (i => seq.Select (items => items[i]).ToList ()).ToList ();
        }
        static void PrintList<T> (IEnumerable<T> list) {
            foreach (var item in list) {
                Console.WriteLine (item);
            }
        }
    }
}