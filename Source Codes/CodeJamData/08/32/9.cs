using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ugly_Numbers
{
    class Program
    {
        static long cnt;
        static void go(string s, int idx, long result, long cur, int op)
        {
            if (idx == s.Length)
            {
                result += op * cur;
                if (result % 2 == 0 || result % 3 == 0 || result % 5 == 0 || result % 7 == 0)
                    cnt++;
                return;
            }
            go(s, idx + 1, result, cur * 10 + (s[idx] - '0'), op);
            go(s, idx + 1, result + op * cur, s[idx] - '0', 1);
            go(s, idx + 1, result + op * cur, s[idx] - '0', -1);
        }
        static long process()
        {
            cnt = 0;
            string s = Console.ReadLine();
            
            go(s, 1, 0, s[0]-'0', 1);
            return cnt;
        }
        static void Main(string[] args)
        {
            int t = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
                Console.WriteLine("Case #{0}: {1}", i + 1, process());
        }
    }
}
