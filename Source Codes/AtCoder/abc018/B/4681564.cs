using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var S = Console.ReadLine ();
            var N = ReadInt ();
            var lr = ReadSequence (N);
            var l = lr[0];
            var r = lr[1];
            foreach (var i in Enumerable.Range (0, N)) {
                var left = S.Take (l[i] - 1);
                var right = S.Skip (r[i]);
                var middle = S.Take (r[i]).Skip (l[i] - 1);
                S = string.Concat (left.Concat (middle.Reverse ()).Concat (right));
            }
            Console.WriteLine (S);
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