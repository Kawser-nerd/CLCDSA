using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemBSmall
{
    class Program
    {
        static bool Check(List<string> dict, char ch)
        {
            for (int i = 0; i < dict.Count; ++i)
            {
                if (dict[i].IndexOf(ch) != -1) return true;
            }
            return false;
        }

        static int Calc(string[] dict, string word, string guess)
        {
            HashSet<char> set = new HashSet<char>();
            for (int i = 0; i < word.Length; ++i) set.Add(word[i]);
            int loss = 0;
            int hit = 0;
            List<string> curDict = new List<string>();
            for (int i = 0; i < dict.Length; ++i)
            {
                if (dict[i].Length == word.Length)
                {
                    curDict.Add(dict[i]);
                }
            }
            for (int i = 0; i < guess.Length; ++i)
            {
                if (Check(curDict, guess[i]))
                {
                    if (word.IndexOf(guess[i]) != -1)
                    {
                        ++hit;
                        if (hit == set.Count())
                        {
                            break;
                        }
                        List<int> pos = new List<int>();
                        for (int j = 0; j < word.Length; ++j)
                        {
                            if (word[j] == guess[i]) pos.Add(j);
                        }
                        List<string> newDict = new List<string>();
                        for (int j = 0; j < curDict.Count; ++j)
                        {
                            bool t = true;
                            List<int> curPos = new List<int>();
                            for (int k = 0; k < curDict[j].Length; ++k)
                            {
                                if (curDict[j][k] == guess[i]) curPos.Add(k);
                            }
                            if (pos.Count != curPos.Count) t = false;
                            else
                            {
                                for (int k = 0; k < pos.Count; ++k)
                                {
                                    if (pos[k] != curPos[k])
                                    {
                                        t = false;
                                        break;
                                    }
                                }
                            }
                            if (t) newDict.Add(curDict[j]);
                        }
                        curDict = newDict;
                    }
                    else
                    {
                        ++loss;
                        List<string> newDict = new List<string>();
                        for (int j = 0; j < curDict.Count; ++j)
                        {
                            if (curDict[j].IndexOf(guess[i]) == -1) newDict.Add(curDict[j]);
                        }
                        curDict = newDict;
                    }
                }
            }
            return loss;
        }

        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int n = Convert.ToInt32(str[0]);
                int m = Convert.ToInt32(str[1]);
                string[] dict = new string[n];
                string[] guess = new string[m];
                string[] ans = new string[m];
                for (int i = 0; i < n; ++i) dict[i] = Console.ReadLine();
                for (int i = 0; i < m; ++i) guess[i] = Console.ReadLine();
                for (int i = 0; i < m; ++i)
                {
                    int max = Calc(dict, dict[0], guess[i]);
                    ans[i] = dict[0];
                    for (int j = 1; j < n; ++j)
                    {
                        int cur = Calc(dict, dict[j], guess[i]);
                        if (cur > max)
                        {
                            max = cur;
                            ans[i] = dict[j];
                        }
                    }
                }
                Console.Write("Case #{0}:", curCase + 1);
                for (int i = 0; i < m; ++i) Console.Write(" {0}", ans[i]);
                Console.WriteLine();
            }
        }
    }
}
