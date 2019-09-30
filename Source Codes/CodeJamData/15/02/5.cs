using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015QualB {
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
                    int D = int.Parse(sr.ReadLine());
                    int[] Ps = sr.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
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
                    string output = Solve(testCase, D, Ps);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(int testCase, int D, int[] Ps) {
                if (testCase == -1) {
                }
                int sp = 1;
                int mmin = int.MaxValue;
                int max = Ps.Max();
                for (int dmax = 1; dmax <= max; dmax++) {
                    int m = dmax;
                    foreach (var p in Ps) {
                        m += (p + dmax - 1) / dmax - 1;
                    }
                    if (m <= mmin) {
                        mmin = m;
                    }
                }
                return mmin.ToString();
            }
        }


        static int Main(string[] args) {
            // ファイル名が指定されている場合は、指定されたファイルに対して処理を行う。
            // ファイル名が指定されてない場合は、カレントディレクトリの large っぽいファイル、
            // small っぽいファイル、その他の順に検索する。
            // large や small が複数ある場合は、名前でソートして一番最後のを使う。
            string inputName = null;
            if (args.Length > 0) {
                if (File.Exists(args[0]) == false) {
                    Console.Error.WriteLine("入力ファイルが見つかりません。");
                    return 1;
                }
                inputName = args[0];
            }
            if (inputName == null) {
                var fis = new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles()
                    .Where(fi => fi.Name.EndsWith(".in"))
                    .OrderBy(fi => fi.Name.Contains("large") ? 1 : (fi.Name.Contains("small") ? 2 : 3))
                    .ThenByDescending(fi => fi.Name);
                var f = fis.FirstOrDefault();
                if (f != null) {
                    inputName = f.FullName;
                }
            }
            if (inputName == null) {
                Console.Error.WriteLine("入力ファイルが見つかりません。");
                return 1;
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
            // 実行中に入力ファイルを変更できるようにするために、いったんメモリにコピー。
            byte[] inputFile = File.ReadAllBytes(inputName);
            if (ThreadCount == 1) {
                for (int i = 0; i < ThreadCount; i++) {
                    Solver solver = new Solver();
                    using (StreamReader sr = new StreamReader(new MemoryStream(inputFile))) {
                        outputs[i] = solver.SolveAll(i, sr);
                    }
                }
            }
            else {
                Parallel.For(0, ThreadCount, i => {
                    Solver solver = new Solver();
                    using (StreamReader sr = new StreamReader(new MemoryStream(inputFile))) {
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

            return 0;
        }
    }
}
