using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace AtCoder {
    class Practice {
        static void Main() => CustomMain();

        static void Solve() {
            int n, m;
            ReadMulti(out n, out m);

            var a = new int[m];
            var b = new int[m];
            for (int i = 0; i < m; i++) {
                ReadMulti(out a[i], out b[i]);
                a[i]--;
                b[i]--;
            }

            var ans = new long[m];
            ans[m - 1] = (long) n * (n - 1) / 2;
            UnionFind uni = new UnionFind(n);

            for (int i = m - 1; i >= 1; i--) {
                ans[i - 1] = ans[i];

                long g1 = uni.Data[uni.Root(a[i])];
                long g2 = uni.Data[uni.Root(b[i])];
                long dif = g1 * g2;
                if (uni.Connect(a[i], b[i])) {
                    ans[i - 1] -= dif;
                }
            }

            foreach (var item in ans) {
                WriteAnswer(item);
            }
        }

        class UnionFind {
            public int[] Data;

            public UnionFind(int n) {
                Data = new int[n];
                for (int i = 0; i < n; i++) {
                    Data[i] = -1;
                }
            }

            public int Root(int a) {
                if (Data[a] < 0) return a;
                return Data[a] = Root(Data[a]);
            }

            public bool Connect(int a, int b) {
                a = Root(a);
                b = Root(b);
                if (a == b) return false;

                if (Data[a] > Data[b]) {
                    var t = a;
                    a = b;
                    b = t;
                }

                Data[a] += Data[b];
                Data[b] = a;
                return true;
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

        static bool IsOdd(long num) {
            return (num & 1) == 1;
        }

        static bool IsEven(long num) {
            return (num & 1) == 0;
        }

        static long GCD(long a, long b) {
            return b != 0 ? GCD(b, a % b) : a;
        }
    }
}