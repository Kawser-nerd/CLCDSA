using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2015QualC {
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
                    long[] cs = sr.ReadLine().Split(' ').Select(c => long.Parse(c)).ToArray();
                    int L = (int)cs[0];
                    long X = cs[1];
                    string s = sr.ReadLine();
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
                    string output = Solve(testCase, L, X, s);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            string Solve(int testCase, int L, long X, string s) {
                string[] left = new string[L + 1];
                left[0] = "1";
                for (int i = 0; i < L; i++) {
                    left[i + 1] = Mul(left[i], s[i].ToString());
                }
                string[] right = new string[L + 1];
                right[0] = "1";
                for (int i = 0; i < L; i++) {
                    right[i + 1] = Mul(s[L - i - 1].ToString(), right[i]);
                }
                Debug.Assert(left[L] == right[L]);
                string whole = left[L];
                int x;
                if (X <= 13) {
                    x = (int)X;
                }
                else {
                    x = (int)((X - 13) % 4 + 13);
                }
                string[] wholes = new string[x + 1];
                wholes[0] = "1";
                for (int i = 0; i < x; i++) {
                    wholes[i + 1] = Mul(wholes[i], whole);
                }
                if (wholes[x] != "-1") {
                    return "NO";
                }
                int len = L * x;
                int l1;
                for (l1 = 1; l1 <= len - 2; l1++) {
                    if (Mul(wholes[l1 / L], left[l1 % L]) == "i") {
                        break;
                    }
                }
                int l3;
                for (l3 = 1; l3 <= len - 2; l3++) {
                    if (Mul(right[l3 % L], wholes[l3 / L]) == "k") {
                        break;
                    }
                }
                if (l1 + l3 + 1 <= len) {
                    return "YES";
                }
                return "NO";
            }
            string Mul(string m1, string m2) {
                int sign = 1;
                if (m1.StartsWith("-")) {
                    m1 = m1.Substring(1);
                    sign *= -1;
                }
                if (m2.StartsWith("-")) {
                    m2 = m2.Substring(1);
                    sign *= -1;
                }
                string m = "";
                switch (m1 + m2) {
                    case "11":
                        m = "1";
                        break;
                    case "1i":
                        m = "i";
                        break;
                    case "1j":
                        m = "j";
                        break;
                    case "1k":
                        m = "k";
                        break;

                    case "i1":
                        m = "i";
                        break;
                    case "ii":
                        m = "-1";
                        break;
                    case "ij":
                        m = "k";
                        break;
                    case "ik":
                        m = "-j";
                        break;

                    case "j1":
                        m = "j";
                        break;
                    case "ji":
                        m = "-k";
                        break;
                    case "jj":
                        m = "-1";
                        break;
                    case "jk":
                        m = "i";
                        break;

                    case "k1":
                        m = "k";
                        break;
                    case "ki":
                        m = "j";
                        break;
                    case "kj":
                        m = "-i";
                        break;
                    case "kk":
                        m = "-1";
                        break;

                    default:
                        Debug.Assert(false);
                        break;
                }
                if (sign == -1) {
                    m = "-" + m;
                }
                if (m.StartsWith("--")) {
                    m = m.Substring(2);
                }
                m = string.Intern(m);
                return m;
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
