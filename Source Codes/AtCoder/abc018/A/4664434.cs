using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var A = ReadInt ();
            var B = ReadInt ();
            var C = ReadInt ();
            // var ABC = new List<List<int>> ();
            // ABC.Add (new List<int> { 1, A });
            // ABC.Add (new List<int> { 2, B });
            // ABC.Add (new List<int> { 3, C });

            // var rank = ABC.OrderByDescending (i => i[1]).Select (i => i[0]);
            Console.WriteLine (B <= A && C <= A?1 : B <= A || C <= A?2 : 3);
            Console.WriteLine (A <= B && C <= B?1 : A <= B || C <= B?2 : 3);
            Console.WriteLine (A <= C && B <= C?1 : A <= C || B <= C?2 : 3);
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