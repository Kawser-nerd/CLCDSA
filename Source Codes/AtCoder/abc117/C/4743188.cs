using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var NM = ReadInts ();
            var N = NM[0];
            var M = NM[1];
            var X = ReadInts ().OrderBy (x => x).ToList ();
            var diffsAndI = Enumerable.Range (1, M - 1).Select (i => new int[2] { X[i] - X[i - 1], i - 1 }).ToList ();
            var diffs = diffsAndI.Select (x => x[0]).ToList ();
            var maxIndexs = diffsAndI.OrderByDescending (x => x[0]).Select (x => x[1]).ToList ();
            foreach (var k in Enumerable.Range (0, Math.Min (N, M) - 1)) {
                diffs[maxIndexs[k]] = 0;
            }
            Console.WriteLine (diffs.Sum ());
        }
        /* Input & Output*/
        static int ReadInt () {
            return int.Parse (Console.ReadLine ());
        }
        static List<int> ReadInts () {
            return Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
        }
        static List<List<int>> ReadColumns (int n) {
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
        static void PrintEnum<T> (IEnumerable<T> list) {
            Console.Write (list.First ());
            foreach (var item in list.Skip (1)) {
                Console.Write ($" {item}");
            }
            Console.Write ("\n");
        }
        static void PrintLnEnum<T> (IEnumerable<T> list) {
            foreach (var item in list) {
                Console.WriteLine (item);
            }
        }

        /* Numeric Function */
        static int Fact (int n) {
            return Enumerable.Range (1, n).Aggregate (1, ((i, k) => i * k));
        }
        static int PermNum (int n, int m) {
            if (m > n) {
                return 0;
            }
            return Enumerable.Range (n - m, m + 1).Aggregate (1, ((i, k) => i * k));
        }
        static int CombNum (int n, int m) {
            return PermNum (n, m) / Fact (m);
        }
        // ????? (m ? n)
        static int GCD (int m, int n) {
            if (n == 0) {
                return m;
            } else {
                return GCD (n, m % n);
            }
        }
        // ????? (m ? n)
        static int LCM (int m, int n) {
            return GCD (m, n) / (m * n);
        }

    }
}