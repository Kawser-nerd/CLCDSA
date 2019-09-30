using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017QualD {
    // 使用方法
    // Visual Studio 2015 でコンソールアプリケーションを新規作成する。
    // このファイルを Program.cs にコピーする。
    // プロジェクトのプロパティで対象のフレームワークを .NET Framework 4.6 にする。
    // プロジェクトのプロパティでプラットフォームターゲットを x64 にする。
    // 参照の追加で、System.Numerics を追加する。
    // 入力ファイルは bin/Debug 以下に置く。
    // サンプルのファイル名は sample.in とする。
    // 実行すると、入力ファイルの拡張子を .out に変更したものが出力される。
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
                int TestCaseCount = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int testCaseIx = 0; testCaseIx < TestCaseCount; testCaseIx++) {
                    // ------------ 読み込み ------------
                    List<int> cs = SplitToInts(sr.ReadLine());
                    int N = cs[0];
                    int M = cs[1];
                    List<List<string>> models = new List<List<string>>();
                    for (int i = 0; i < M; i++) {
                        List<string> model = SplitToStrings(sr.ReadLine());
                        models.Add(model);
                    }
                    // ------------ 読み込み ------------
                    #region
                    if (testCaseIx % ThreadCount != threadId) {
                        // このスレッドの担当ではないので解かない
                        continue;
                    }
                    if (Verbose) {
                        if (testCaseIx % ProgressInterval == 0) {
                            Console.Error.WriteLine(testCaseIx + " / " + TestCaseCount);
                        }
                    }
                    #endregion
                    // ------------ 呼び出し ------------
                    string output = Solve(testCaseIx, N, models);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(int testCaseIx, int N, List<List<string>> models) {
                bool[,] rs = new bool[N, N];
                bool[,] bs = new bool[N, N];
                bool[] ri = new bool[N];
                bool[] rj = new bool[N];
                bool[] bsum = new bool[2 * N - 1]; // i + j
                bool[] bdiff = new bool[2 * N - 1]; // i - j + (N - 1)
                List<Model> ms = models.Select(m => new Model { Type = m[0], X = int.Parse(m[2]) - 1, Y = int.Parse(m[1]) - 1 }).ToList();
                int score = 0;
                foreach (var m in ms) {
                    if (m.Type == "x" || m.Type == "o") {
                        rs[m.Y, m.X] = true;
                        ri[m.Y] = true;
                        rj[m.X] = true;
                        score++;
                    }
                    if (m.Type == "+" || m.Type == "o") {
                        bs[m.Y, m.X] = true;
                        bsum[m.Y + m.X] = true;
                        bdiff[m.Y - m.X + N - 1] = true;
                        score++;
                    }
                }
                bool[,] initRs = rs.Clone() as bool[,];
                bool[,] initBs = bs.Clone() as bool[,];
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (ri[i] == false && rj[j] == false) {
                            ri[i] = true;
                            rj[j] = true;
                            rs[i, j] = true;
                            score++;
                        }
                    }
                }
                for (int ij0 = 0; ij0 < N; ij0++) {
                    for (int k = 0; k < 2; k++) {
                        int ij;
                        if (k == 0) {
                            ij = ij0;
                        }
                        else {
                            ij = N * 2 - 2 - ij0;
                        }
                        for (int j = 0; j < N; j++) {
                            int i = ij - j;
                            if (i < 0 || i >= N) {
                                continue;
                            }
                            if (bsum[i + j] == false && bdiff[i - j + (N - 1)] == false) {
                                bsum[i + j] = true;
                                bdiff[i - j + (N - 1)] = true;
                                bs[i, j] = true;
                                score++;
                            }
                        }
                    }
                }
                List<Model> newms = new List<Model>();
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (rs[i, j] != initRs[i, j] || bs[i, j] != initBs[i, j]) {
                            string type = "";
                            if (rs[i, j] == true && bs[i, j] == false) {
                                type = "x";
                            }
                            else if (rs[i, j] == false && bs[i, j] == true) {
                                type = "+";
                            }
                            else if (rs[i, j] == true && bs[i, j] == true) {
                                type = "o";
                            }
                            newms.Add(new Model { Type = type, X = j, Y = i });
                        }
                    }
                }

                string ans = score + " " + newms.Count;
                foreach(var nm in newms) {
                    ans += Environment.NewLine + nm;
                }

                return ans;
            }
            class Model {
                public string Type;
                public int X;
                public int Y;
                public override string ToString() {
                    return Type + " " + (Y + 1) + " " + (X + 1);
                }
            }
        }


        static int Main(string[] args) {
            // 入力ファイルは、引数で指定されたファイル、ファイル名が tmp から始まるファイル、
            // large っぽいファイル、small っぽいファイル、sample の順に検索する。
            // ファイルの検索はカレントディレクトリで行われる。
            // 入力ファイルの拡張子は .in でなければならない。
            // 複数ある場合は、名前でソートして一番最後のを使う。
            // tmp 以外は、一度実行済みのみものでも、前回の結果を番号付きの別ファイルに
            // リネームするので、何度でも実行できる。tmp は一回だけ実行する。

            // 基本的に sample, small, large の順で解き進めていけるが、
            // 一時的に試したい入力があるときに、tmp001.in などのファイルを作成すれば、
            // それが優先的に実行されるようにするため、このような順番で検索するようにしている。
            // なお、tmp は、1回限りの実行なので、実行後に入力ファイルを削除する必要はないが、
            // 同じ tmp を何度も実行したい場合は、前回の出力を手動で削除またはリネームする必要があるので注意。
            string inputName = null;
            if (args.Length > 0) {
                if (File.Exists(args[0]) == false) {
                    Console.Error.WriteLine("入力ファイルが見つかりません。");
                    return 1;
                }
                if (args[0].EndsWith(".in") == false) {
                    Console.Error.WriteLine("入力ファイルの拡張子が .in ではありません。");
                    return 1;
                }
                inputName = args[0];
            }
            if (inputName == null) {
                var fInCands = new DirectoryInfo(Directory.GetCurrentDirectory()).GetFiles().Where(fi => fi.Name.EndsWith(".in"));
                inputName =
                    fInCands.Where(fi => fi.Name.StartsWith("tmp") && File.Exists(OutputName(fi.Name)) == false)
                    .OrderByDescending(fi => fi.Name)
                    .FirstOrDefault()?.Name ??
                    fInCands.Where(fi => fi.Name.Contains("large"))
                    .OrderByDescending(fi => fi.Name)
                    .FirstOrDefault()?.Name ??
                    fInCands.Where(fi => fi.Name.Contains("small"))
                    .OrderByDescending(fi => fi.Name)
                    .FirstOrDefault()?.Name ??
                    fInCands.Where(fi => fi.Name.Contains("sample"))
                    .OrderByDescending(fi => fi.Name)
                    .FirstOrDefault()?.Name;
            }
            if (inputName == null) {
                Console.Error.WriteLine("入力ファイルが見つかりません。");
                return 1;
            }
            // 出力先のファイル名を決定し、同名のファイルがある場合はリネームする。
            string outputName = OutputName(inputName);
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
        static string OutputName(string inputName) => inputName.Substring(0, inputName.Length - 3) + ".out";
        static List<string> SplitToStrings(string input) => input.Split(' ').ToList();
        static List<int> SplitToInts(string input) => input.Split(' ').Select(a => int.Parse(a)).ToList();
        static List<long> SplitToLongs(string input) => input.Split(' ').Select(a => long.Parse(a)).ToList();
    }
}
