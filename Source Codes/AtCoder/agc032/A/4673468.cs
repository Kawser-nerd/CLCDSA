using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var N = ReadInt ();
            var b = ReadInts ();
            var js = new List<int> ();
            foreach (var i in Enumerable.Range (0, N + 1).Reverse ()) {
                if (i == 0) {
                    PrintList (Enumerable.Reverse (js));
                    return;
                }

                // foreach (var m in Enumerable.Range (0, i)) {
                //     Console.Write ($"{b[m]} ");
                // }
                // Console.Write ("\n");
                foreach (var j in Enumerable.Range (0, i + 1).Reverse ()) {
                    // Console.WriteLine ("ok");
                    if (j == 0) {
                        // a????????????????
                        Console.WriteLine (-1);
                        return;
                    }
                    if (b[j - 1] == j) {
                        // Console.WriteLine (j);
                        js.Add (j);
                        b.RemoveAt (j - 1);
                        break;
                    }
                }
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