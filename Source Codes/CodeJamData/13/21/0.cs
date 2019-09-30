using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Numerics;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    void init()
    {

    }

    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            int a = cin.nextInt();
            int n = cin.nextInt();
            long[] now = new long[n + 1];
            now[0] = a;
            int[] nums = new int[n];
            for (int i = 0; i < n; i++)
            {
                nums[i] = cin.nextInt();
            }
            Array.Sort(nums);

            for (int i = 0; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    now[j] = Math.Min((long)1e8, Math.Max(now[j], now[j - 1] * 2 - 1));
                }
                long[] next = new long[n + 1];
                for (int j = 0; j < n; j++)
                {
                    next[j + 1] = now[j];
                }
                for (int j = 0; j < n; j++)
                {
                    if (now[j] > nums[i]) next[j] = Math.Max(next[j], now[j] + nums[i]);
                }
                now = next;
            }
            int ret = 0;
            for (int i = 0; i <= n; i++)
            {
                if (now[i] > 0)
                {
                    ret = i; break;
                }
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