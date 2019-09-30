using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

class ProblemB
{
    private const bool parallel = true;

    class Case
    {
        private int caseNum;
        private string[] terms;
        private int K;
        private string[] dict;
        private const int MOD = 10009;

        private void readInput()
        {
            string[] tmp = readWords();
            terms = tmp[0].Split('+');
            K = int.Parse(tmp[1]);
            int n = readInt();
            dict = new string[n];
            for (int i = 0; i < n; i++)
                dict[i] = readLine();
        }

        public string DoCase()
        {
            string res = find("", 1).ToString();
            for (int i = 2; i <= K; i++)
                res += " " + find("", i);
            return string.Format("Case #{0}: {1}", caseNum, res);
        }

        int find(string ph, int left)
        {
            if (left == 0) return P(ph);
            int res = 0;
            foreach (string s in dict)
                res += find(ph + s, left - 1);
            return res % MOD;
        }

        int P(string phrase)
        {
            int[] freq = new int[26];
            foreach (char c in phrase)
                if (char.IsLower(c))
                    freq[c - 'a']++;
            int res = 0;
            foreach (string t in terms)
                res += eval(t, freq);
            return res % MOD;
        }

        int eval(string t, int[] freq)
        {
            int res = 1;
            foreach (char c in t)
                res = (res * freq[c - 'a']) % MOD;
            return res;
        }

        //////////////////////////////////////
        // Mostly template stuff below here //
        //////////////////////////////////////

        private Task<string> task;

        public Case(int num)
        {
            caseNum = num;
            readInput();
        }

        public void Start()
        {
            task = Task.Factory.StartNew(new Func<string>(DoCase));
        }

        public string Finish()
        {
            task.Wait();
            return task.Result;
        }
    }

    private static StreamReader input;
    private static StreamWriter output;
    private static int? firstCase, lastCase;

    public static void Main(string[] args)
    {
        input = new StreamReader(args[0] + ".in");
        output = new StreamWriter(args[0] + ".out");
        if (args.Length > 1)
            firstCase = int.Parse(args[1]);
        if (args.Length > 2)
            lastCase = int.Parse(args[2]);
        solution();
        output.Close();
        input.Close();
    }

    static void solution()
    {
        int T = readInt();
        var tests = new Case[T];
        for (int i = 1; i <= T; i++)
        {
            tests[i - 1] = new Case(i);
            if (i >= (firstCase ?? 1) && i <= (lastCase ?? T))
            {
                if (parallel)
                    tests[i - 1].Start();
                else
                    output.WriteLine(tests[i - 1].DoCase());
            }
        }
        if (parallel)
        {
            for (int i = (firstCase ?? 1) - 1; i < (lastCase ?? T); i++)
            {
                output.WriteLine(tests[i].Finish());
            }
        }
    }

    static string readLine()
    {
        return input.ReadLine();
    }

    static int readInt()
    {
        return int.Parse(readLine());
    }

    static string[] readWords()
    {
        return readLine().Split();
    }

    static int[] readInts()
    {
        return Array.ConvertAll(readWords(), int.Parse);
    }
}
