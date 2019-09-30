using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace AtCoder.ABC113 {
    class C {
        static void Main() => CustomMain();

        class City {
            public int no;
            public int prefecture;
            public int year;
        }

        static void Solve() {
            int n, m;
            ReadMulti(out n, out m);

            var c = new List<City>();
            for (int i = 0; i < m; i++) {
                var a = ReadIntArray();
                c.Add(new City() {
                    no = i,
                    prefecture = a[0],
                    year = a[1]
                });
            }

            var ca = c.OrderBy(x => x.prefecture).ThenBy(x => x.year);

            var p_now = 0;
            var y_now = 1;
            foreach (var city in ca) {
                if (city.prefecture != p_now) {
                    p_now = city.prefecture;
                    city.year = 1;
                    y_now = 1;
                } else {
                    y_now++;
                    city.year = y_now;
                }
            }

            var cb = ca.OrderBy(x => x.no);
            foreach (var city in cb) {
                WriteAnswer($"{city.prefecture:D6}{city.year:D6}");
            }
        }


        static void CustomMain() {
#if DEBUG
            // ?????????????????
            global::Common.ChangeStdIn();
            // ????
            var stopwatch = new Stopwatch();
            stopwatch.Start();
#endif
            // ?????
            var streamWriter = new StreamWriter(Console.OpenStandardOutput()) {AutoFlush = false};
            Console.SetOut(streamWriter);
            // ??
            Solve();
#if DEBUG
            stopwatch.Stop();
            Console.WriteLine(stopwatch.Elapsed);
#endif
            Console.Out.Flush();
        }

        static string ReadString() => Console.ReadLine().Trim();
        static int ReadInt() => int.Parse(ReadString());
        static long ReadLong() => long.Parse(ReadString());
        static float ReadFloat() => float.Parse(ReadString());
        static double ReadDouble => double.Parse(ReadString());

        static string[] ReadStringArray() => ReadString().Split(' ');
        static int[] ReadIntArray() => Array.ConvertAll(ReadString().Split(' '), int.Parse);
        static long[] ReadLongArray() => Array.ConvertAll(ReadString().Split(' '), long.Parse);
        static float[] ReadFloatArray() => Array.ConvertAll(ReadString().Split(' '), float.Parse);
        static double[] ReadDoubleArray() => Array.ConvertAll(ReadString().Split(' '), double.Parse);

        static T TypeConversion<T>(string s) {
            if (typeof(T) == typeof(int)) {
                return (T) Convert.ChangeType(int.Parse(s), typeof(T));
            } else if (typeof(T) == typeof(long)) {
                return (T) Convert.ChangeType(long.Parse(s), typeof(T));
            } else if (typeof(T) == typeof(double)) {
                return (T) Convert.ChangeType(double.Parse(s), typeof(T));
            } else {
                return (T) Convert.ChangeType(s, typeof(T));
            }
        }

        static void ReadMulti<T, U>(out T a, out U b) {
            var str = ReadStringArray();
            a = TypeConversion<T>(str[0]);
            b = TypeConversion<U>(str[1]);
        }

        static void ReadMulti<T, U, V>(out T a, out U b, out V c) {
            var str = ReadStringArray();
            a = TypeConversion<T>(str[0]);
            b = TypeConversion<U>(str[1]);
            c = TypeConversion<V>(str[2]);
        }

        static void WriteAnswer(object ans) => Console.WriteLine(ans);
    }
}