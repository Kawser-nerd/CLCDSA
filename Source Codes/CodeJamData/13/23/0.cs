using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Numerics;
using System.IO;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    string[] words;

    void init()
    {
        words = File.ReadAllText("garbled_email_dictionary.txt").Split(new char[] { '\n' }, StringSplitOptions.RemoveEmptyEntries);
    }


    int MAX = 99999999;
    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            string s = cin.next();
            int n = s.Length;
            int[,] dp = new int[n + 1, 5];
            for (int i = 0; i < n + 1; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    dp[i, j] = MAX;
                }
            }
            dp[0, 0] = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (dp[i, j] == MAX) continue;
                    foreach (string ss in words)
                    {
                        if (i + ss.Length > n) continue;
                        int pre = j;
                        int change = 0;
                        for (int k = 0; k < ss.Length; k++)
                        {
                            if (s[i + k] != ss[k])
                            {
                                if (pre != 0)
                                {
                                    pre = 5; break;
                                }
                                else pre = 4;
                                change++;
                            }
                            else
                            {
                                pre = Math.Max(0, pre - 1);
                            }
                        }
                        if (pre == 5) continue;
                        dp[i + ss.Length, pre] = Math.Min(dp[i + ss.Length, pre], dp[i, j] + change);
                    }
                }
            }

            int ret = MAX;
            for (int j = 0; j < 5; j++)
            {
                ret = Math.Min(dp[n, j], ret);
            }
            Console.WriteLine(ret);
        }

    }


}




class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }
}