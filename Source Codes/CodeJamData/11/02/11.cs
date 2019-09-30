using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemB
{
    class Program
    {
        static string[] cRule, dRule;
        static List<char> queue;
        static int[] cnt;

        static bool checkCRule(out char result)
        {
            result = 'A';
            int num = queue.Count;
            if (num < 2) return false;
            for (int i = 0; i < cRule.Length; ++i)
            {
                if ((queue[num - 1] == cRule[i][0]) && (queue[num - 2] == cRule[i][1]))
                {
                    result = cRule[i][2];
                    return true;
                }
                if ((queue[num - 1] == cRule[i][1]) && (queue[num - 2] == cRule[i][0]))
                {
                    result = cRule[i][2];
                    return true;
                }
            }
            return false;
        }

        static bool checkDRule()
        {
            for (int i = 0; i < dRule.Length; ++i)
            {
                if ((cnt[dRule[i][0] - 'A'] > 0) && (cnt[dRule[i][1] - 'A'] > 0))
                {
                    return true;
                }
            }
            return false;
        }

        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int cur = 0;
                int c = Convert.ToInt32(str[cur++]);
                cRule = new string[c];
                for (int i = 0; i < c; ++i)
                {
                    cRule[i] = str[cur++];
                }
                int d = Convert.ToInt32(str[cur++]);
                dRule = new string[d];
                for (int i = 0; i < d; ++i)
                {
                    dRule[i] = str[cur++];
                }
                int n = Convert.ToInt32(str[cur++]);
                string chain = str[cur++];
                cnt = new int[26];
                queue = new List<char>();
                for (int i = 0; i < n; ++i)
                {
                    queue.Add(chain[i]);
                    cnt[chain[i]-'A']++;
                    char result;
                    while (checkCRule(out result))
                    {
                        int num = queue.Count();
                        cnt[queue[num - 1] - 'A']--;
                        cnt[queue[num - 2] - 'A']--;
                        cnt[result - 'A']++;
                        queue.RemoveRange(num - 2, 2);
                        queue.Add(result);
                    }
                    if (checkDRule())
                    {
                        cnt = new int[26];
                        queue.Clear();
                    }
                }
                Console.Write("Case #{0}: [", curCase + 1);
                if (queue.Count > 0) Console.Write(queue[0]);
                for (int i = 1; i < queue.Count; ++i)
                {
                    Console.Write(", " + queue[i]);
                }
                Console.WriteLine("]");
            }
        }
    }
}
