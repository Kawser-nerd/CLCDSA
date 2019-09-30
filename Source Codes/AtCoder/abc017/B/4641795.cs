using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var X = Console.ReadLine ();
            if (IsChokuGo (X)) {
                Console.WriteLine ("YES");
            } else {
                Console.WriteLine ("NO");
            }
        }

        static bool IsChokuGo (IEnumerable<char> s) {
            if (!s.Any ()) {
                return true;
            }
            var first = s.First ();
            var tail = s.Skip (1);
            var take2 = s.Take (2);
            var body = s.Skip (2);
            if (string.Concat (take2) == "ch") {
                return true && IsChokuGo (body);
            } else if (first == 'o' || first == 'k' || first == 'u') {
                return true && IsChokuGo (tail);
            } else {
                return false;
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
                Console.Write (item + " ");
            }
            Console.Write ("\n");
        }
    }
}