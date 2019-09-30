using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoderTemplate {
    class Program {
        enum choice : int {
            A = 0,
            B,
            C,
            none
        }
        static void Main (string[] args) {
            var NABC = ReadInts ();
            var N = NABC[0];
            var A = NABC[1];
            var B = NABC[2];
            var C = NABC[3];
            var l = ReadColumns (N) [0];
            var seqs = GetSequences ((choice[]) Enum.GetValues (typeof (choice)), N);
            var compsableSeqs = seqs.Where (seq => seq.Any (x => x == choice.A) && seq.Any (x => x == choice.B) && seq.Any (x => x == choice.C)).Select (seq => seq.ToList ());
            var costSums = compsableSeqs.Select (seq => {
                var iA = Enumerable.Range (0, N).Where (i => seq[i] == choice.A);
                var iB = Enumerable.Range (0, N).Where (i => seq[i] == choice.B);
                var iC = Enumerable.Range (0, N).Where (i => seq[i] == choice.C);
                return (iA.Count () + iB.Count () + iC.Count () - 3) * 10 + Math.Abs (iA.Select (i => l[i]).Sum () - A) + Math.Abs (iB.Select (i => l[i]).Sum () - B) + Math.Abs (iC.Select (i => l[i]).Sum () - C);
            });
            Console.WriteLine (costSums.OrderBy (x => x).First ());
        }
        static IEnumerable<IEnumerable<T>> GetSequences<T> (IEnumerable<T> source, int n) {
            if (n == 1) {
                return source.Select (x => new List<T> { x });
            } else {
                return source.SelectMany (x => GetSequences (source, n - 1).Select (y => y.Concat (new List<T> { x })));
            }
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