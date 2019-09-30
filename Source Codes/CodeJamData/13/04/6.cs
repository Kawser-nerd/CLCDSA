using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2013QualD {
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
                int T = int.Parse(sr.ReadLine());
                // ------------ 初期化 ------------
                List<string> outputs = new List<string>();
                for (int t = 0; t < T; t++) {
                    // ------------ 読み込み ------------
                    int[] l = sr.ReadLine().Split(' ').Select(a => int.Parse(a)).ToArray();
                    int K = l[0];
                    int N = l[1];
                    List<int> keys = sr.ReadLine().Split(' ').Select(a => int.Parse(a)).ToList();
                    List<Chest> chests = new List<Chest>();
                    for (int i = 0; i < N; i++) {
                        Chest c = new Chest();
                        List<int> ll = sr.ReadLine().Split(' ').Select(a => int.Parse(a)).ToList();
                        c.ToOpen = ll[0];
                        c.Keys = ll.GetRange(2, ll[1]);
                        chests.Add(c);
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
                    string output = Solve(K, N, keys, chests);
                    // ------------ 呼び出し ------------
                    outputs.Add(output);
                }
                return outputs;
            }
            class Chest {
                public int ToOpen;
                public List<int> Keys;
                public override string ToString() {
                    return ToOpen + " : " + string.Join(" ", Keys);
                }
            }
            const int VisitedHashLen = 16;
            List<Visited>[] VisitedList = new List<Visited>[1 << VisitedHashLen];
            const int VisitedListCapacity = 10000000;
            int VisitedListCount = 0;
            struct Visited {
                const int MaskLen = 7;
                public uint[] Mask;
                public override int GetHashCode() {
                    uint h = 0;
                    foreach (var m in Mask) {
                        h ^= m;
                    }
                    h ^= h >> 16;
                    return (int)h;
                }
                public bool Equals(Visited rhs) {
                    if (rhs == null) {
                        return false;
                    }
                    for (int i = 0; i < MaskLen; i++) {
                        if (Mask[i] != rhs.Mask[i]) {
                            return false;
                        }
                    }
                    return true;
                }
                public override bool Equals(object obj) {
                    if (obj is Visited) {
                        return Equals((Visited)obj);
                    }
                    else {
                        return false;
                    }
                }
                public static bool operator ==(Visited lhs, Visited rhs) {
                    if (lhs == null && rhs == null) {
                        return true;
                    }
                    if (lhs == null || rhs == null) {
                        return false;
                    }
                    return lhs.Equals(rhs);
                }
                public static bool operator !=(Visited lhs, Visited rhs) {
                    return !lhs.Equals(rhs);
                }
                public bool this[int index] {
                    get {
                        return (Mask[index / 32] & (1u << (index % 32))) != 0;
                    }
                    set {
                        if (value == true) {
                            Mask[index / 32] |= 1u << (index % 32);
                        }
                        else {
                            Mask[index / 32] &= ~(1u << (index % 32));
                        }
                    }
                }
                public void Init() {
                    Mask = new uint[MaskLen];
                }

                public Visited Clone() {
                    Visited c = new Visited();
                    c.Mask = Mask.ToArray();
                    return c;
                }
            }
            string Solve(int K, int N, List<int> keys, List<Chest> chests) {
                VisitedList = new List<Visited>[1 << VisitedHashLen];
                for (int i = 0; i < VisitedList.Length; i++) {
                    VisitedList[i] = new List<Visited>();
                }
                List<List<int>> keyToChest = new List<List<int>>();
                for (int i = 0; i < chests.Count; i++) {
                    int k = chests[i].ToOpen;
                    while (k >= keyToChest.Count) {
                        keyToChest.Add(new List<int>());
                    }
                    keyToChest[k].Add(i);
                }
                Visited v = new Visited();
                v.Init();
                List<int> order = Search(keys, chests, keyToChest, v, 0);
                if (order != null) {
                    return string.Join(" ", order);
                }
                return "IMPOSSIBLE";
            }
            List<int> Search(List<int> keys, List<Chest> chests, List<List<int>> keyToChest, Visited v, int depth) {
                int hash = v.GetHashCode() & ((1 << VisitedHashLen) - 1);
                foreach (var h in VisitedList[hash]) {
                    if (h == v) {
                        return null;
                    }
                }
                VisitedList[hash].Add(v);
                VisitedListCount++;
                if (VisitedListCount > VisitedListCapacity) {
                    for (int i = 0; i < VisitedList.Length; i++) {
                        VisitedList[i] = new List<Visited>();
                    }
                }

                List<int> nexts = new List<int>();
                foreach (var k in keys.Distinct()) {
                    if (k < keyToChest.Count) {
                        nexts.AddRange(keyToChest[k]);
                    }
                }
                nexts.Sort();
                foreach (var n in nexts) {
                    if (v[n] == false) {
                        List<int> nkeys = keys.ToList();
                        nkeys.Remove(chests[n].ToOpen);
                        nkeys.AddRange(chests[n].Keys);
                        nkeys.Sort();
                        Visited nv = v.Clone();
                        nv[n] = true;
                        if (depth < chests.Count - 1) {
                            List<int> r = Search(nkeys, chests, keyToChest, nv, depth + 1);
                            if (r != null) {
                                r.Insert(0, n + 1);
                                return r;
                            }
                        }
                        else {
                            return new List<int> {n + 1};
                        }
                    }
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
