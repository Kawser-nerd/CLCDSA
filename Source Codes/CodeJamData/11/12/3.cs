using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G1_B
    {
        public static void Main(String[] args)
        {
            string input = @"../../B.in";
            string output = @"../../B.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    int tn = int.Parse(sr.ReadLine());
                    for (int tc = 1; tc <= tn; tc++)
                    {
                        string res = ls(sr);
                        sw.WriteLine("Case #{0}: {1}", tc, res);
                        Console.WriteLine("Case #{0}: {1}", tc, res);
                    }
                }
            }
        }

        class Status
        {
            public int lose;
            public List<int> list = new List<int>();
            public string pat = "";

            public Status(int l, string p)
            {
                lose = l;
                pat = p;
            }
        };

        private static string ls(StreamReader sr)
        {
            string[] ss = sr.ReadLine().Split(' ');
            int n = int.Parse(ss[0]);
            int m = int.Parse(ss[1]);
            string[] d = new string[n];
            for (int i = 0; i < n; i++)
            {
                d[i] = sr.ReadLine();
            }
            string[] ret = new string[m];
            for (int i = 0; i < m; i++)
            {
                string l = sr.ReadLine();
                ret[i] = solve(l, d);
            }
            return String.Join(" ", ret);
        }

        private static string solve(string l, string[] d)
        {
            Status ss = init(d);
            int idx = 0;
            //bool[] guessed = new bool[26];
            int len = find(ss, l, -1, out idx, d);
            return d[idx];
        }

        private static int find(Status ss, string l, int li, out int idx, string[] d)
        {
            char c = '-';
            if (li >= 0)
            {
                //guessed[l[li] - 'a'] = true;
                c = l[li];
            }
            int ret;
            if (ss.list.Count == 1)
            {
                idx = ss.list[0];
                ret = ss.lose;
            }
            else
            {
                Dictionary<string, Status> dict = split(ss, d, l, li, c);
                if (dict.Count == 1)
                {
                    ret = find(ss, l, li + 1, out idx, d);
                }
                else
                {
                    int max = -1;
                    idx = -1;
                    foreach (Status ns in dict.Values)
                    {
                        int idx2;
                        int v = find(ns, l, li + 1, out idx2, d);
                        if (v > max)
                        {
                            max = v;
                            idx = idx2;
                        }
                        else if (v == max && idx2 < idx)
                        {
                            idx = idx2;
                        }
                    }
                    ret = max;
                }
            }
            return ret;
        }

        private static Dictionary<string, Status> split(Status ss, string[] d, string l, int li, char c)
        {
            bool[] guessed = new bool[26];
            for (int i = 0; i <= li && i <l.Length; i++)
            {
                guessed[l[i] - 'a'] = true;
            }
            Dictionary<string, Status> ret = new Dictionary<string, Status>();
            foreach(int di in ss.list)
            {
                int lostadd;
                string pat = getPat(d[di], guessed, c, out lostadd);
                if (!ret.ContainsKey(pat))
                {
                    ret[pat] = new Status(ss.lose + lostadd, pat);
                }
                ret[pat].list.Add(di);
            }
            return ret;
        }

        private static string getPat(string word, bool[] guessed, char c, out int lostadd)
        {
            StringBuilder sb = new StringBuilder();
            lostadd = 1;
            for (int i = 0; i < word.Length; i++)
            {
                if (guessed[word[i] - 'a'])
                {
                    sb.Append(word[i]);
                }
                else
                {
                    sb.Append("_");
                }
                if (word[i] == c)
                    lostadd = 0;
            }
            if (c == '-')
                lostadd = 0;
            return sb.ToString();
        }

        private static Status init(string[] d)
        {
            Status ss = new Status(0, "");
            for (int i = 0; i < d.Length; i++)
            {
                ss.list.Add(i);
            }
            return ss;
        }



        static void assert(bool v)
        {
            if (false)
            {
                throw new Exception();
            }
        }
    }
}
