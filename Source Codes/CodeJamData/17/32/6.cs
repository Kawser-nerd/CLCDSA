using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017R1CB {
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
            class Activity {
                public int Start;
                public int End;
                public Activity(int s, int e) {
                    Start = s;
                    End = e;
                }
                public override string ToString() {
                    return Start + ", " + End;
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
                    int Ac = cs[0];
                    int Aj = cs[1];
                    List<Activity> Acs = new List<Activity>();
                    for (int i = 0; i < Ac; i++) {
                        List<int> a = SplitToInts(sr.ReadLine());
                        Acs.Add(new Activity(a[0], a[1]));
                    }
                    List<Activity> Ajs = new List<Activity>();
                    for (int i = 0; i < Aj; i++) {
                        List<int> a = SplitToInts(sr.ReadLine());
                        Ajs.Add(new Activity(a[0], a[1]));
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
                    string output = Solve(testCaseIx, Ac, Aj, Acs, Ajs);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(int testCaseIx, int Ac, int Aj, List<Activity> Acs, List<Activity> Ajs) {
                Acs = Acs.OrderBy(a => a.Start).ToList();
                Ajs = Ajs.OrderBy(a => a.Start).ToList();
                int a0 = Solve1(Acs, Ajs);
                int a1 = Solve1(Ajs, Acs);
                int min = Math.Min(a0, a1);
                return min.ToString();
            }
            static int Solve1(List<Activity> a0, List<Activity> a1) {
                int a0Ix = 0;
                int a1Ix = 0;
                a0 = a0.ToList();
                a0.Add(new Activity(1440, 0));
                a1 = a1.ToList();
                a1.Add(new Activity(1440, 0));
                int current = 0;
                int currentPos = 0;
                List<int> a0Blanks = new List<int>();
                List<int> a1Blanks = new List<int>();
                int a0Sum = 0;
                int a1Sum = 0;
                int a0BlanksSum = 0;
                int a1BlanksSum = 0;
                int exchangeTime = 0;
                int exchangeCount = 0;
                while (a0Ix < a0.Count && a1Ix < a1.Count) {
                    if (a0[a0Ix].Start < a1[a1Ix].Start) {
                        if (current == 0) {
                            a0Blanks.Add(a0[a0Ix].Start - currentPos);
                            a0BlanksSum += a0[a0Ix].Start - currentPos;
                            a0Sum += a0[a0Ix].End - a0[a0Ix].Start;
                            Debug.Assert(a0Sum >= 0);
                            currentPos = a0[a0Ix].End;
                            a0Ix++;
                            continue;
                        }
                        else {
                            exchangeTime += a0[a0Ix].Start - currentPos;
                            a0Sum += a0[a0Ix].End - a0[a0Ix].Start;
                            currentPos = a0[a0Ix].End;
                            Debug.Assert(a0Sum >= 0);
                            a0Ix++;
                            current = 0;
                            exchangeCount++;
                            continue;
                        }
                    }
                    else if (a0[a0Ix].Start > a1[a1Ix].Start) {
                        if (current == 1) {
                            a1Blanks.Add(a1[a1Ix].Start - currentPos);
                            a1BlanksSum += a1[a1Ix].Start - currentPos;
                            a1Sum += a1[a1Ix].End - a1[a1Ix].Start;
                            currentPos = a1[a1Ix].End;
                            a1Ix++;
                            continue;
                        }
                        else {
                            exchangeTime += a1[a1Ix].Start - currentPos;
                            a1Sum += a1[a1Ix].End - a1[a1Ix].Start;
                            currentPos = a1[a1Ix].End;
                            a1Ix++;
                            current = 1;
                            exchangeCount++;
                            continue;
                        }
                    }
                    else {
                        break;
                    }
                }
                if (current == 0) {
                    a0Blanks.Add(1440 - currentPos);
                    a0BlanksSum += 1440 - currentPos;
                }
                else {
                    exchangeTime += 1440 - currentPos;
                    exchangeCount++;
                }
                Debug.Assert(a0Sum + a0BlanksSum + a1Sum + a1BlanksSum + exchangeTime == 1440);
                if (a0Sum + a0BlanksSum <= 720 && a1Sum + a1BlanksSum <= 720) {
                    return exchangeCount;
                }
                a0Blanks = a0Blanks.OrderByDescending(a => a).ToList();
                a1Blanks = a1Blanks.OrderByDescending(a => a).ToList();
                if (a0Sum + a0BlanksSum > 720) {
                    int over = a0Sum + a0BlanksSum - 720;
                    while (over > 0) {
                        over -= a0Blanks[0];
                        a0Blanks.RemoveAt(0);
                        exchangeCount += 2;
                    }
                }
                if (a1Sum + a1BlanksSum > 720) {
                    int over = a1Sum + a1BlanksSum - 720;
                    while (over > 0) {
                        over -= a1Blanks[0];
                        a1Blanks.RemoveAt(0);
                        exchangeCount += 2;
                    }
                }
                return exchangeCount;
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
