using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class C
{
    public static void Main()
    {
        int T = ReadInt();
        for (int i = 1; i <= T; i++)
        {
            int[] args = ReadInts();
            int res = doit(args[0], args[1]);
            Console.WriteLine("Case #{0}: {1}", i, res);
        }
    }

    static int doit(int A, int B)
    {
        int res = 0;
        for (int n = A; n < B; n++)
        {
            string s = n.ToString();
            Dictionary<string, string> check = new Dictionary<string, string>();
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] == '0') continue;
                string t = s.Substring(i) + s.Substring(0, i);
                if (t == s) continue;
                int m = int.Parse(t);
                if (m > n && m <= B)
                {
                    if (!check.ContainsKey(t))
                    {
                        check.Add(t, null);
                        res++;
                    }
                }
            }
        }
        return res;
    }

    #region Library

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    #endregion
}
