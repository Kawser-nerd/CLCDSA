using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Read();
            if (S == "zyxwvutsrqponmlkjihgfedcba") { Console.WriteLine(-1); return; }
            var used = new Dictionary<char, bool>();
            for (char c = 'a'; c <= 'z'; c++) used.Add(c, false);
            for (int i = 0; i < S.Length; i++) used[S[i]] = true;
            var ans = S;
            if (S.Length < 26)
            {
                foreach(var u in used)
                {
                    if (!u.Value)
                    {
                        ans += u.Key;
                        break;
                    }
                }
            }
            else
            {
                while (true)
                {
                    var c = ans[ans.Length - 1];
                    used[c] = false;
                    ans = ans.Remove(ans.Length - 1, 1);
                    var suc = false;
                    var chk = ans[ans.Length - 1];
                    foreach(var u in used)
                    {
                        if (!u.Value && u.Key > chk)
                        {
                            ans = ans.Remove(ans.Length - 1, 1);
                            ans += u.Key;
                            suc = true;
                            break;
                        }
                    }
                    if (suc) break;
                }
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}