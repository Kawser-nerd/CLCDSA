using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017R2B {
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
            class Ticket {
                public int Pos;
                public int Owner;
                public Ticket(int pos, int owner) {
                    Pos = pos;
                    Owner = owner;
                }
                public override string ToString() {
                    return Pos + ", " + Owner;
                }
            }
            public List<string> SolveAll(int threadId, StreamReader sr) {
                // ------------ 初期化 ------------
                int TestCaseCount = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int testCaseIx = 0; testCaseIx < TestCaseCount; testCaseIx++) {
                    // ------------ 読み込み ------------
                    List<int> cs = SplitToInts(sr.ReadLine());
                    int N = cs[0];
                    int C = cs[1];
                    int M = cs[2];
                    List<Ticket> ts = new List<Ticket>();
                    for (int i = 0; i < M; i++) {
                        List<int> t = SplitToInts(sr.ReadLine());
                        ts.Add(new Ticket(t[0] - 1, t[1] - 1));
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
                    string output = Solve(testCaseIx, N, C, M, ts);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(int testCaseIx, int N, int C, int M, List<Ticket> ts) {
                List<bool[]> maps = new List<bool[]>();
                int[,] cs = new int[C, N];
                int ride = 0;
                int prom = 0;
                foreach(var t in ts) {
                    cs[t.Owner, t.Pos]++;
                }
                for (int i = 0; i < C; i++) {
                    int ct = 0;
                    for (int j = 0; j < N; j++) {
                        ct += cs[i, j];
                    }
                    if (ride < ct) {
                        ride = ct;
                    }
                }
                bool error = true;
                while(error) {
                    error = false;
                    prom = 0;
                    int blank = 0;
                    for (int j = 0; j < N; j++) {
                        int ct = 0;
                        for (int i = 0; i < C; i++) {
                            ct += cs[i, j];
                        }
                        if (ct > ride) {
                            if (ct > ride + blank) {
                                error = true;
                                ride++;
                                break;
                            }
                            prom += ct - ride;
                            blank -= ct - ride;
                        }
                        else {
                            blank += ride - ct;
                        }
                    }
                }
                return ride + " " + prom;
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
