using System;
using System.Collections.Generic;
using System.Linq;
using static System.Math;
using static AtCoderTemplate.MyExtensions;
using static AtCoderTemplate.MyInputOutputs;
using static AtCoderTemplate.MyNumericFunctions;

namespace AtCoderTemplate {
    class Program {
        static void Main (string[] args) {
            var S = Console.ReadLine ();
            var T = Console.ReadLine ();

            /*
            ??????????????????????????
            S[i] = S[j] => T[i] = T[j] ??? (1)
            ????????
            S[i] ? S[j] => T[i] ? T[j] ??? (2)
            ?????????

            ????(2)????????
            T[i] = T[j] => S[i] = S[j] ??? (2')

            ????a~z???????????b = S[i]????????????i????(1)(2')???????????????
             */

            var isYes = Enumerable.Range ('a', 'z' - 'a' + 1).Select (i => (char) i)
                .All (c => {
                    var TBecauseS = Enumerable.Range (0, S.Count ()).Where (i => S[i] == c).Select (i => T[i]);
                    var SBecauseT = Enumerable.Range (0, T.Count ()).Where (i => T[i] == c).Select (i => S[i]);
                    var prop1 = TBecauseS.IsEmpty () ? true : TBecauseS.All (Ti => Ti == TBecauseS.First ());
                    var prop2 = SBecauseT.IsEmpty () ? true : SBecauseT.All (Si => Si == SBecauseT.First ());
                    return prop1 && prop2;
                });

            PrintIf (isYes, "Yes", "No");
        }
    }

    static class MyInputOutputs {
        /* Input & Output*/
        public static int ReadInt () {
            return int.Parse (Console.ReadLine ());
        }
        public static long ReadLong () {
            return long.Parse (Console.ReadLine ());
        }
        public static List<int> ReadInts () {
            return Console.ReadLine ().Split (' ').Select (c => int.Parse (c)).ToList ();
        }
        public static List<long> ReadLongs () {
            return Console.ReadLine ().Split (' ').Select (c => long.Parse (c)).ToList ();
        }
        public static List<List<int>> ReadIntColumns (int n) {
            /*
            ???
            A1 B1
            A2 B2
            ...
            An Bn

            ???
            [[A1,A2,...,An], [B1,B2,...,Bn]]
            */
            var rows = Enumerable.Range (0, n).Select (i => ReadInts ()).ToList ();
            var m = rows.FirstOrDefault ()?.Count () ?? 0;
            return Enumerable.Range (0, m).Select (i => rows.Select (items => items[i]).ToList ()).ToList ();
        }
        public static List<List<long>> ReadLongColumns (int n) {
            /*
            ???
            A1 B1
            A2 B2
            ...
            An Bn

            ???
            [[A1,A2,...,An], [B1,B2,...,Bn]]
            */
            var rows = Enumerable.Range (0, n).Select (i => ReadLongs ()).ToList ();
            var m = rows.FirstOrDefault ()?.Count () ?? 0;
            return Enumerable.Range (0, m).Select (i => rows.Select (items => items[i]).ToList ()).ToList ();
        }
        public static void PrintRow<T> (IEnumerable<T> list) {
            /* ????????
            A B C D ...
            */
            if (!list.IsEmpty ()) {
                Console.Write (list.First ());
                foreach (var item in list.Skip (1)) {
                    Console.Write ($" {item}");
                }
            }
            Console.Write ("\n");
        }
        public static void PrintColomn<T> (IEnumerable<T> list) {
            /* ????????
            A
            B
            C
            D
            ...
            */
            foreach (var item in list) {
                Console.WriteLine (item);
            }
        }
        public static void Print2DArray<T> (IEnumerable<IEnumerable<T>> sources) {
            foreach (var row in sources) {
                PrintRow (row);
            }
        }

        public static void PrintIf<T1, T2> (bool condition, T1 trueResult, T2 falseResult) {
            if (condition) {
                Console.WriteLine (trueResult);
            } else {
                Console.WriteLine (falseResult);
            }
        }
    }

    static class MyNumericFunctions {
        public static int Fact (int n) {
            return Enumerable.Range (1, n).Aggregate (1, ((i, k) => i * k));
        }
        public static int PermNum (int n, int m) {
            if (m > n) {
                return 0;
            }
            return Enumerable.Range (n - m, m + 1).Aggregate (1, ((i, k) => i * k));
        }
        public static int CombNum (int n, int m) {
            return PermNum (n, m) / Fact (m);
        }
        // ????? (m ? n)
        public static int GCD (int m, int n) {
            if (n == 0) {
                return m;
            } else {
                return GCD (n, m % n);
            }
        }
        // ????? (m ? n)
        public static int LCM (int m, int n) {
            return GCD (m, n) / (m * n);
        }
    }

    static class MyExtensions {
        public static bool IsEmpty<T> (this IEnumerable<T> source) {
            return source.Count () == 0;
        }

        /// <summary>
        /// ???????????
        /// O(N * log(N))
        /// </summary>
        public static IEnumerable<int> Diff (this IEnumerable<int> source) {
            var list = source.ToList ();
            return Enumerable.Range (1, list.Count - 1)
                .Select (i => list[i] - list[i - 1]);
        }

        /// <summary>
        /// ??????
        /// O(N * log(N))
        /// </summary>
        public static IEnumerable<int> CumSum (this IEnumerable<int> source) {
            var list = source.ToList ();
            var result = new List<int> { list[0] };
            foreach (var i in Enumerable.Range (1, source.Count () - 1)) {
                result.Add (result[i - 1] + list[i]);
            }
            return result;
        }

        /// <summary>
        /// ?????????????????
        /// </summary>
        public static IEnumerable<int> SortIndex<T> (this IEnumerable<T> source) {
            return source
                .Select ((item, i) => new { Item = item, Index = i })
                .OrderBy (x => x.Item)
                .Select (x => x.Index);
        }
    }
}