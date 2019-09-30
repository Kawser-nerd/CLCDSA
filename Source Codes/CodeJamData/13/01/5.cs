using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2013QualA {
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
                    List<string> board = new List<string>();
                    for (int i = 0; i < 4; i++) {
                        board.Add(sr.ReadLine());
                    }
                    sr.ReadLine();
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
                    string output = Solve(board);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(List<string> board) {
                for (int i = 0; i < 4; i++) {
                    string r = Check(board[i].ToCharArray());
                    if (r != null) {
                        return r;
                    }
                }
                for (int i = 0; i < 4; i++) {
                    string r = Check(new char[] { board[0][i], board[1][i], board[2][i], board[3][i] });
                    if (r != null) {
                        return r;
                    }
                }
                {
                    string r = Check(new char[] { board[0][0], board[1][1], board[2][2], board[3][3] });
                    if (r != null) {
                        return r;
                    }
                }
                {
                    string r = Check(new char[] { board[0][3], board[1][2], board[2][1], board[3][0] });
                    if (r != null) {
                        return r;
                    }
                }
                if (string.Join("", board).Any(a => a == '.') == false) {
                    return "Draw";
                }
                return "Game has not completed";
            }
            string Check(char[] line) {
                int x = line.Where(a => a == 'X' || a == 'T').Count();
                if (x == 4) {
                    return "X won";
                }
                int o = line.Where(a => a == 'O' || a == 'T').Count();
                if (o == 4) {
                    return "O won";
                }
                return null;
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
