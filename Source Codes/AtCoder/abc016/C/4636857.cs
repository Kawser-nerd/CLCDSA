using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var NM = ReadInts ();
            var N = NM[0];
            var M = NM[1];

            if (M == 0) {
                PrintList (Enumerable.Repeat (0, N));
                return;
            }

            var AB = ReadSequence (M);
            var A = AB[0];
            var B = AB[1];

            var friends = Enumerable.Range (0, N + 1).Select (i => new List<int> ()).ToList ();
            foreach (var i in Enumerable.Range (0, M)) {
                friends[A[i]].Add (B[i]);
                friends[B[i]].Add (A[i]);
            }
            var firiendConnections = Enumerable.Range (0, N + 1).Select (i => friends[i].SelectMany (k => friends[k]).Distinct ()).ToList ();
            var overFriendCounts = Enumerable.Range (0, N + 1).Select (i => firiendConnections[i].Except (friends[i]).Where (overfriend => overfriend != i).Count ());
            PrintList (overFriendCounts.Skip (1));
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