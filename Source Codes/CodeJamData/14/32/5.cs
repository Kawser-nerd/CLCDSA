using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014R1CB {
    class Program {
        /// <summary>
        /// スレッド数
        /// </summary>
        static int ThreadCount = 1;
        /// <summary>
        /// 進捗を表示する。
        /// </summary>
        static bool Verbose = true;
        static int ProgressInterval = 1;

        class Solver {
            public List<string> SolveAll(int threadId, StreamReader sr) {
                // ------------ 初期化 ------------
                int TestCase = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int testCase = 0; testCase < TestCase; testCase++) {
                    // ------------ 読み込み ------------
                    int N = int.Parse(sr.ReadLine());
                    string l = sr.ReadLine();
                    // ------------ 読み込み ------------
                    #region
                    if (testCase % ThreadCount != threadId) {
                        // このスレッドの担当ではないので解かない
                        continue;
                    }
                    if (Verbose) {
                        if (testCase % ProgressInterval == 0) {
                            Console.Error.WriteLine(testCase + " / " + TestCase);
                        }
                    }
                    #endregion
                    // ------------ 呼び出し ------------
                    string output = Solve(testCase, l);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            const long Mod = 1000000007;
            string Solve(int testCase, string l) {
                if (testCase == -1) {
                }
                List<string> ts = l.Split(' ').ToList();
                BigInteger ans = 1;
                for(char c = 'a'; c <= 'z'; c++) {
                    int ct = 0;
                    string ns = "";
                    for(int i = 0; i < ts.Count; i++) {
                        if (ts[i].First() == c && ts[i].Last() == c) {
                            ns += ts[i];
                            ct++;
                            ans *= ct;
                            ts.RemoveAt(i);
                            i--;
                        }
                    }
                    if (ct > 0) {
                        ts.Add(ns);
                    }
                }
                for(;;) {
                    bool f = Update(ts, true);
                    if (f == false) {
                        break;
                    }
                }
                for(;;) {
                    bool f = Update(ts, false);
                    if (f == false) {
                        break;
                    }
                }
                string all = string.Concat(ts);
                for(char c = 'a'; c <= 'z'; c++) {
                    int first = all.IndexOf(c);
                    if (first < 0) {
                        continue;
                    }
                    int last = all.LastIndexOf(c);
                    for(int i = first; i < last; i++) {
                        if (all[i] != c) {
                            return "0";
                        }
                    }
                }
                for(int i = 1; i <= ts.Count; i++) {
                    ans *= i;
                }
                ans %= Mod;
                return ans.ToString();
            }
            static bool Update(List<string> ts, bool primary) {
                int N = ts.Count();
                for(int i = 0; i < N; i++) {
                    if (primary && ts[i].First() != ts[i].Last()) {
                        continue;
                    }
                    for(int j = 0; j < N; j++) {
                        if (i == j) {
                            continue;
                        }
                        if (ts[i].Last() == ts[j].First()) {
                            ts[i] += ts[j];
                            ts.RemoveAt(j);
                            return true;
                        }
                    }
                }
                return false;
            }
        }


        static void Main(string[] args) {
            // ファイル名が指定されている場合は、指定されたファイルに対して処理を行う。
            // ファイル名が指定されてない場合は、カレントディレクトリの large っぽいファイル、
            // small っぽいファイル、sample.in を順に検索する。
            // large や small が複数ある場合は、名前でソートして一番最後のを使う。
            string inputName = null;
            if (args.Length > 0) {
                if (File.Exists(args[0]) == false) {
                    Console.Error.WriteLine("入力ファイルが見つかりません。");
                    return;
                }
                inputName = args[0];
            }
            if (inputName == null) {
                List<string> larges = new List<string>();
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.Contains("large") && fi.Name.EndsWith(".in")) {
                        larges.Add(fi.FullName);
                    }
                }
                if (larges.Count > 0) {
                    larges.Sort();
                    inputName = larges[larges.Count - 1];
                }
            }
            if (inputName == null) {
                List<string> smalls = new List<string>();
                foreach (var fi in new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()) {
                    if (fi.Name.Contains("small") && fi.Name.EndsWith(".in")) {
                        smalls.Add(fi.FullName);
                    }
                }
                if (smalls.Count > 0) {
                    smalls.Sort();
                    inputName = smalls[smalls.Count - 1];
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
                    using (StreamReader sr = new StreamReader(inputName)) {
                        outputs[i] = solver.SolveAll(i, sr);
                    }
                }
            }
            else {
                Parallel.For(0, ThreadCount, i => {
                    Solver solver = new Solver();
                    using (StreamReader sr = new StreamReader(inputName)) {
                        outputs[i] = solver.SolveAll(i, sr);
                    }
                });
            }

            // 結果を出力する。Case # はここで付加する。
            using (StreamWriter sw = new StreamWriter(outputName)) {
                for (int i = 0; ; i++) {
                    if (outputs[i % ThreadCount].Count > i / ThreadCount) {
                        sw.WriteLine("Case #" + (i + 1) + ": " + outputs[i % ThreadCount][i / ThreadCount]);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
}
