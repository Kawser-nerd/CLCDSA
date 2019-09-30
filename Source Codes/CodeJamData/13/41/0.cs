using System;
using System.Collections.Generic;
using System.Linq;
//using System.Threading.Tasks;
//using System.Numerics;

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

    long mod = 1000002013;
    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            long ret = 0;
            long n = cin.nextInt();
            int m = cin.nextInt();
            int[] start = new int[m];
            int[] goal = new int[m];
            int[] num = new int[m];
            for (int i = 0; i < m; i++)
            {
                start[i] = cin.nextInt();
                goal[i] = cin.nextInt();
                num[i] = cin.nextInt();
                int dist = goal[i] - start[i];
                ret -= (((n * dist + getnum(dist)) % mod) * num[i]) % mod;
                ret = (ret + mod) % mod;
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m - 1; j++)
                {
                    if (start[j] > start[j + 1])
                    {
                        swap(ref start[j], ref start[j + 1]);
                        swap(ref goal[j], ref goal[j + 1]);
                        swap(ref num[j], ref num[j + 1]);
                    }
                }
            }

            int[] start2 = (int[])start.Clone();
            int[] goal2 = (int[])goal.Clone();
            int[] num2 = (int[])num.Clone();

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m - 1; j++)
                {
                    if (goal2[j] > goal2[j + 1])
                    {
                        swap(ref start2[j], ref start2[j + 1]);
                        swap(ref goal2[j], ref goal2[j + 1]);
                        swap(ref num2[j], ref num2[j + 1]);
                    }
                }
            }

            int temp = 0;
            for (int i = 0; i < m; i++)
            {
                while (temp != m && start[temp] <= goal2[i]) temp++;
                for (int j = temp - 1; j >= 0; j--)
                {
                    int dec = Math.Min(num[j], num2[i]);
                    num[j] -= dec;
                    num2[i] -= dec;
                    int dist = (goal2[i] - start[j]);
                    ret += (((n * dist + getnum(dist)) % mod) * dec) % mod;
                    ret = (ret + mod) % mod;
                }
            }
            ret = (ret % mod + mod) % mod;
            Console.WriteLine(ret);
        }

    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
    } 

    long getnum(int n)
    {
        return ((long)n * (n - 1) / 2) % mod;
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