using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class ProblemC {
    static string inputFileName = "../../input.txt";
    static string outputFileName = "../../output.txt";
    static StreamReader fileReader;
    static StreamWriter file;
    static string[] inputTokens;
    static int curInputTokenIndex;
    static string NextToken() {
        if (file == null) {
            file = new StreamWriter(outputFileName, false);
        }
        string ret = "";
        while (ret == "") {
            if (inputTokens == null || curInputTokenIndex >= inputTokens.Length) {
                string line;
                if (Type.GetType("HaitaoLocal") != null) {
                    if (fileReader == null) {
                        fileReader = new StreamReader(inputFileName);
                    }
                    line = fileReader.ReadLine();
                    if (line == null) {
                        throw new Exception("Error: out of input tokens!");
                    }
                } else {
                    line = Console.ReadLine();
                }
                inputTokens = line.Split();
                curInputTokenIndex = 0;
            }
            ret = inputTokens[curInputTokenIndex++];
        }
        return ret;
    }
    static int ReadInt() {
        return Int32.Parse(NextToken());
    }
    static string ReadString() {
        return NextToken();
    }
    static long ReadLong() {
        return Int64.Parse(NextToken());
    }
    static int[] ReadIntArray(int length) {
        int[] ret = new int[length];
        for (int i = 0; i < length; i++) {
            ret[i] = ReadInt();
        }
        return ret;
    }
    static string[] ReadStringArray(int length) {
        string[] ret = new string[length];
        for (int i = 0; i < length; i++) {
            ret[i] = ReadString();
        }
        return ret;
    }
    static long[] ReadLongArray(int length) {
        long[] ret = new long[length];
        for (int i = 0; i < length; i++) {
            ret[i] = ReadLong();
        }
        return ret;
    }
    static string DoubleToString(double d) {
        return d.ToString(new CultureInfo("en-US"));
    }

    public static void Main(string[] args) {
        int T = ReadInt();
        for (int m = 0; m < T; m++) {
            Console.WriteLine(m);
            int dictSize = 0;
            Dictionary<string, int> dict = new Dictionary<string, int>();
            int N = ReadInt()-2;
            string[] w1 = fileReader.ReadLine().Split();
            string[] w2 = fileReader.ReadLine().Split();
            Dictionary<int,int> fr = new Dictionary<int,int>();
            Dictionary<int,int> en = new Dictionary<int,int>();
            foreach (string str in w1) {
                if (dict.ContainsKey(str)) {
                    fr[dict[str]] = 0;
                } else {
                    dict[str] = dictSize++;
                    fr[dict[str]] = 0;
                }
            }
            foreach (string str in w2) {
                if (dict.ContainsKey(str)) {
                    en[dict[str]] = 0;
                } else {
                    dict[str] = dictSize++;
                    en[dict[str]] = 0;
                }
            }
            List<int>[] words = new List<int>[N];
            for (int n = 0; n < N; n++) {
                words[n] = new List<int>();
                string[] w = fileReader.ReadLine().Split();
                foreach (string str in w) {
                    if (!dict.ContainsKey(str)) {
                        dict[str] = dictSize++;
                    }
                    words[n].Add(dict[str]);
                }
            }
            List<int> toRemove = new List<int>();
            foreach (int key in fr.Keys) {
                if (en.ContainsKey(key)) {
                    toRemove.Add(key);
                }
            }
            foreach (int key in toRemove) {
                fr.Remove(key);
                en.Remove(key);
                for (int n = 0; n < N; n++) {
                    for (int i = words[n].Count - 1; i >= 0; i--) {
                        if (words[n][i] == key) {
                            words[n].RemoveAt(i);
                        }
                    }
                }
            }
            int best = 10000000;
            for (int mask = 0; mask < 1 << N; mask++) {
                Dictionary<int, int> d1 = new Dictionary<int, int>(fr);
                Dictionary<int, int> d2 = new Dictionary<int, int>(en);
                for (int i = 0; i < N; i++) {
                    bool b = (mask & (1 << i)) == 0;
                    Dictionary<int, int> d = b ? d1 : d2;
                    foreach (int w in words[i]) {
                        d[w] = 0;
                    }
                }
                int value = 0;
                foreach (int key in d1.Keys) {
                    if (d2.ContainsKey(key)) value++;
                }
                best = Math.Min(best, value);
            }

            string ans = ""+(best+toRemove.Count);
            file.WriteLine("Case #" + (m + 1) + ": " + ans);
        }
        file.WriteLine();
        file.Close();
    }
}
