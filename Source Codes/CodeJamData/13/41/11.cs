using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2013R2A {
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
            class Passenger {
                public BigInteger Origin;
                public BigInteger EndPoint;
                public BigInteger Number;
            }
            public List<string> SolveAll(int threadId, StreamReader sr) {
                // ------------ 初期化 ------------
                int T = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int t = 0; t < T; t++) {
                    // ------------ 読み込み ------------
                    BigInteger[] l = sr.ReadLine().Split(' ').Select(a => BigInteger.Parse(a)).ToArray();
                    BigInteger N = l[0];
                    BigInteger M = l[1];
                    List<Passenger> ps = new List<Passenger>();
                    for (int i = 0; i < M; i++) {
                        BigInteger[] p = sr.ReadLine().Split(' ').Select(a => BigInteger.Parse(a)).ToArray();
                        ps.Add(new Passenger { Origin = p[0], EndPoint = p[1], Number = p[2] });
                    }
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
                    string output = Solve(N, M, ps);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            class Event {
                public BigInteger Station;
                public BigInteger Diff;
            }
            class Ticket {
                public BigInteger Station;
                public BigInteger Number;
            }
            string Solve(BigInteger N, BigInteger M, List<Passenger> ps) {
                BigInteger fare = 0;
                foreach (var p in ps) {
                    fare += Cost(p.EndPoint - p.Origin) * p.Number;
                }
                List<Event> seq = new List<Event>();
                foreach (var p in ps) {
                    seq.Add(new Event { Station = p.Origin, Diff = p.Number });
                    seq.Add(new Event { Station = p.EndPoint, Diff = -p.Number });
                }
                seq = (from e in seq orderby e.Station, -e.Diff select e).ToList();

                List<Ticket> tickets = new List<Ticket>();
                foreach (var e in seq) {
                    if (e.Diff > 0) {
                        tickets.Add(new Ticket { Station = e.Station, Number = e.Diff });
                    }
                    else {
                        BigInteger l = -e.Diff;
                        while (l > tickets[tickets.Count - 1].Number) {
                            fare -= Cost(e.Station - tickets[tickets.Count - 1].Station) * tickets[tickets.Count - 1].Number;
                            l -= tickets[tickets.Count - 1].Number;
                            tickets.RemoveAt(tickets.Count - 1);
                        }
                        if (l > 0) {
                            fare -= Cost(e.Station - tickets[tickets.Count - 1].Station) * l;
                            tickets[tickets.Count - 1].Number -= l;
                        }
                    }
                }

                return (-fare).ToString();
            }
            public BigInteger Cost(BigInteger n) {
                return n * (n - 1) / 2;
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
