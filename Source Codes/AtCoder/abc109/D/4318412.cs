using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

// ????????AC
namespace AtCoder.ABC109 {
    class D {
        static void Main() => CustomMain();

        static int H, W;
        private static int[][] a;

        static void Solve() {
            ReadMulti(out H, out W);
            a = new int[H][];
            for (int i = 0; i < H; i++) {
                a[i] = ReadIntArray();
            }

            var ans = new List<int[]>();
            for (int i = 0; i < H; i++) {
                if (IsEven(i)) {
                    for (int j = 0; j < W; j++) {
                        if (IsOdd(a[i][j])) {
                            if (j != W - 1) {
                                a[i][j]--;
                                a[i][j + 1]++;
                                ans.Add(new int[] {i, j, i, j + 1});
                            } else {
                                if (i == H - 1) continue;
                                a[i][j]--;
                                a[i + 1][j]++;
                                ans.Add(new int[] {i, j, i + 1, j});
                            }
                        }
                    }
                } else {
                    for (int j = W - 1; j >= 0; j--) {
                        if (IsOdd(a[i][j])) {
                            if (j != 0) {
                                a[i][j]--;
                                a[i][j - 1]++;
                                ans.Add(new int[] {i, j, i, j - 1});
                            } else {
                                if (i == H - 1) continue;
                                a[i][j]--;
                                a[i + 1][j]++;
                                ans.Add(new int[] {i, j, i + 1, j});
                            }
                        }
                    }
                }
            }

            WriteAnswer(ans.Count);
            for (int i = 0; i < ans.Count; i++) {
                for (int j = 0; j < 4; j++) {
                    ans[i][j]++;
                }
            }

            foreach (var va in ans) {
                WriteAnswer(string.Join(" ", va));
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
    }
}