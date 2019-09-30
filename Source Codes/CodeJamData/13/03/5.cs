using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2013QualC {
    class Program {
        /// <summary>
        /// スレッド数
        /// </summary>
        static int ThreadCount = 1;
        /// <summary>
        /// 進捗を表示する。
        /// </summary>
        static bool Verbose = false;
        static int ProgressInterval = 1;

        class Solver {
            public List<string> SolveAll(int threadId, StreamReader sr) {
                // ------------ 初期化 ------------
                int T = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int t = 0; t < T; t++) {
                    // ------------ 読み込み ------------
                    BigInteger[] l = sr.ReadLine().Split(' ').Select(a => BigInteger.Parse(a)).ToArray();
                    BigInteger A = l[0];
                    BigInteger B = l[1];
                    // ------------ 読み込み ------------
                    #region
                    if (t % ThreadCount != threadId) {
                        // このスレッドの担当ではないので解かない
                        continue;
                    }
                    if (Verbose) {
                        if (t % ProgressInterval == 0) {
                            Console.Error.WriteLine(t + " / " + T);
                        }
                    }
                    #endregion
                    // ------------ 呼び出し ------------
                    string output = Solve(A, B);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(BigInteger A, BigInteger B) {
                int count = 0;
                foreach (var p in Palindromes) {
                    if (p * p >= A && p * p <= B) {
                        count++;
                    }
                    else if (p * p > B) {
                        break;
                    }
                }
                return count.ToString();
            }
            bool IsPalindromic(BigInteger a) {
                List<int> vs = new List<int>();
                while (a > 0) {
                    vs.Add((int)(a % 10));
                    a /= 10;
                }
                for (int i = 0; i < vs.Count / 2; i++) {
                    if (vs[i] != vs[vs.Count - 1 - i]) {
                        return false;
                    }
                }
                return true;
            }
            List<BigInteger> Palindromes = new List<BigInteger>();
            long DigitMax = 50;
            public Solver() {
                BigInteger[] digit1 = new BigInteger[DigitMax + 1];
                digit1[0] = 1;
                for (int i = 0; i < DigitMax; i++) {
                    digit1[i + 1] = digit1[i] * 10;
                }
                // 1, 2, 3;
                Palindromes.Add(1);
                Palindromes.Add(2);
                Palindromes.Add(3);
                for (long d = 1; d <= DigitMax / 2; d++) {
                    BigInteger val;
                    // 1xx1, 1x0x1, 1x1x1, 1x2x1
                    {
                        val = digit1[0] + digit1[d * 2 - 1];
                        Palindromes.Add(val);
                        val = digit1[0] + digit1[d * 2];
                        Palindromes.Add(val);
                        val = digit1[0] + digit1[d] + digit1[d * 2];
                        Palindromes.Add(val);
                        val = digit1[0] + digit1[d] * 2 + digit1[d * 2];
                        Palindromes.Add(val);
                    }
                    // 1x1xx1x1, 1x1x0x1x1, 1x1x1x1x1, 1x1x2x1x1
                    for (long i = 1; i < d; i++) {
                        val = digit1[0] + digit1[i] + digit1[d * 2 - 1 - i] + digit1[d * 2 - 1];
                        Palindromes.Add(val);
                        val = digit1[0] + digit1[i] + digit1[d * 2 - i] + digit1[d * 2];
                        Palindromes.Add(val);
                        val = digit1[0] + digit1[i] + digit1[d] + digit1[d * 2 - i] + digit1[d * 2];
                        Palindromes.Add(val);
                        val = digit1[0] + digit1[i] + digit1[d] * 2 + digit1[d * 2 - i] + digit1[d * 2];
                        Palindromes.Add(val);
                    }
                    // 1x1x1xx1x1x1, 1x1x1x0x1x1x1, 1x1x1x1x1x1x1
                    for (long i = 1; i < d - 1; i++) {
                        for (long j = i + 1; j < d; j++) {
                            val = digit1[0] + digit1[i] + digit1[d * 2 - 1 - i] + digit1[d * 2 - 1];
                            val = digit1[0] + digit1[i] + digit1[j] + digit1[d * 2 - 1 - j] + digit1[d * 2 - 1 - i] + digit1[d * 2 - 1];
                            Palindromes.Add(val);
                            val = digit1[0] + digit1[i] + digit1[d * 2 - i] + digit1[d * 2];
                            val = digit1[0] + digit1[i] + digit1[j] + digit1[d * 2 - j] + digit1[d * 2 - i] + digit1[d * 2];
                            Palindromes.Add(val);
                            val = digit1[0] + digit1[i] + digit1[d * 2 - i] + digit1[d * 2];
                            val = digit1[0] + digit1[i] + digit1[j] + digit1[d] + digit1[d * 2 - j] + digit1[d * 2 - i] + digit1[d * 2];
                            Palindromes.Add(val);
                        }
                    }
                    // 1x1x1x1xx1x1x1x1, 1x1x1x1x0x1x1x1x1, 1x1x1x1x1x1x1x1x1
                    for (long i = 1; i < d - 2; i++) {
                        for (long j = i + 1; j < d - 1; j++) {
                            for (long k = j + 1; k < d; k++) {
                                val = digit1[0] + digit1[i] + digit1[d * 2 - 1 - i] + digit1[d * 2 - 1];
                                val = digit1[0] + digit1[i] + digit1[j] + digit1[d * 2 - 1 - j] + digit1[d * 2 - 1 - i] + digit1[d * 2 - 1];
                                val = digit1[0] + digit1[i] + digit1[j] + digit1[k] + digit1[d * 2 - 1 - k] + digit1[d * 2 - 1 - j] + digit1[d * 2 - 1 - i] + digit1[d * 2 - 1];
                                Palindromes.Add(val);
                                val = digit1[0] + digit1[i] + digit1[d * 2 - i] + digit1[d * 2];
                                val = digit1[0] + digit1[i] + digit1[j] + digit1[k] + digit1[d * 2 - k] + digit1[d * 2 - j] + digit1[d * 2 - i] + digit1[d * 2];
                                Palindromes.Add(val);
                                val = digit1[0] + digit1[i] + digit1[d * 2 - i] + digit1[d * 2];
                                val = digit1[0] + digit1[i] + digit1[j] + digit1[k] + digit1[d] + digit1[d * 2 - k] + digit1[d * 2 - j] + digit1[d * 2 - i] + digit1[d * 2];
                                Palindromes.Add(val);
                            }
                        }
                    }
                    // 2xx2, 2x0x2, 2x1x2
                    {
                        val = digit1[0] * 2 + digit1[d * 2 - 1] * 2;
                        Palindromes.Add(val);
                        val = digit1[0] * 2 + digit1[d * 2] * 2;
                        Palindromes.Add(val);
                        val = digit1[0] * 2 + digit1[d] + digit1[d * 2] * 2;
                        Palindromes.Add(val);
                    }
                }
                Palindromes.Sort();
#if false
                foreach (var a in Palindromes) {
                    Debug.Assert(IsPalindromic(a * a));
                }
#endif
            }
        }


        static void Main(string[] args) {
            // ファイル名が指定されている場合は、指定されたファイルに対して処理を行う。
            // ファイル名が指定されてない場合は、カレントディレクトリの large っぽいファイル、
            // small っぽいファイル、sample.in を順に検索する。
            string inputName = null;
            if (args.Length > 0) {
                if (File.Exists(args[0]) == false) {
                    Console.Error.WriteLine("入力ファイルが見つかりません。");
                    return;
                }
                inputName = args[0];
            }
            if (inputName == null) {
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.Contains("large") && fi.Name.EndsWith(".in")) {
                        inputName = fi.FullName;
                        break;
                    }
                }
            }
            if (inputName == null) {
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.Contains("small") && fi.Name.EndsWith(".in")) {
                        inputName = fi.FullName;
                        break;
                    }
                }
            }
            if (inputName == null) {
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.ToLower() == "sample.in") {
                        inputName = fi.FullName;
                        break;
                    }
                }
            }
            if (inputName == null) {
                Console.Error.WriteLine("入力ファイルが見つかりません。");
                return;
            }
            // 出力先のファイル名を決定し、同名のファイルがある場合はリネームする。
            string outputName = inputName;
            if (outputName.EndsWith(".in")) {
                outputName = outputName.Substring(0, outputName.Length - 3);
            }
            outputName += ".out";
            if (File.Exists(outputName)) {
                int rev = 1;
                while (File.Exists(outputName + "." + rev)) {
                    rev++;
                }
                File.Move(outputName, outputName + "." + rev);
            }

            // 実行する。ThreadCount == 1 なら、現在のスレッドで、それ以外なら Parallel で実行する。
            List<string>[] outputs = new List<string>[ThreadCount];
            if (ThreadCount == 1) {
                for (int i = 0; i < ThreadCount; i++) {
                    Solver solver = new Solver();
                    StreamReader sr = new StreamReader(inputName);
                    outputs[i] = solver.SolveAll(i, sr);
                    sr.Close();
                }
            }
            else {
                Parallel.For(0, ThreadCount, i => {
                    Solver solver = new Solver();
                    StreamReader sr = new StreamReader(inputName);
                    outputs[i] = solver.SolveAll(i, sr);
                    sr.Close();
                });
            }

            // 結果を出力する。Case # はここで付加する。
            StreamWriter sw = new StreamWriter(outputName);
            for (int i = 0; ; i++) {
                if (outputs[i % ThreadCount].Count > i / ThreadCount) {
                    sw.WriteLine("Case #" + (i + 1) + ": " + outputs[i % ThreadCount][i / ThreadCount]);
                }
                else {
                    break;
                }
            }
            sw.Close();
        }
    }
}
