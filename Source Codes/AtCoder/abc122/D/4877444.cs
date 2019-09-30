using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

namespace AtCoderABC122
{
    class Program
    {
        static long mod = 1000000007;
        static int N;
        static Dictionary<string, long>[] memo;

        public static bool Ok(string s)
        {
            for (int i = 0; i < 4; i++)
            {
                char[] t = s.ToCharArray();
                if (i >= 1)
                {
                    char temp = t[i];
                    t[i] = t[i - 1];
                    t[i - 1] = temp;
                }
                string ss = new string(t);
                if (ss.IndexOf("AGC", 0) >= 0) return false;
            }
            return true;
        }

        static string chars = "ACGT";

        public static long Dfs(int cur, string s)
        {
            if (memo[cur].ContainsKey(s)) return memo[cur][s];
            if (cur == N) return 1;

            long ret = 0;

            for (int i = 0; i < 4; i++)
            {
                string c = chars[i].ToString();
                if (Ok(s + c)) ret = (ret + Dfs(cur + 1, s.Substring(1) + c)) % mod;
            }
            memo[cur][s] = ret;

            return ret;
        }

        public static void Main(string[] args)
        {
            N = int.Parse(Console.ReadLine());
            memo = new Dictionary<string, long>[N + 1];
            for (int i = 0; i < N + 1; i++) memo[i] = new Dictionary<string, long>();

            Console.WriteLine(Dfs(0, "TTT"));
        }
    }
}