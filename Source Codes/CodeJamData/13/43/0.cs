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
            int n = cin.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; i++)
            {
                a[i] = cin.nextInt();
            }
            for (int i = 0; i < n; i++)
            {
                b[i] = cin.nextInt();
            }
            List<int> l = new List<int>();
            for (int i = 0; i < n; i++)
            {
                l.Add(i + 1);
            }

            int[] flag = new int[n];
            for (int i = 0; i < n; i++)
            {
                flag[i] = -1;
            }
            int[] ret = new int[n];
            Dictionary<int, int>[] dic = new Dictionary<int, int>[n];
            for (int i = n - 1; i >= 0; i--)
            {
                dic[i] = new Dictionary<int, int>();

                int mya = a[i];
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] <= mya)
                    {
                        dic[i][j] = 1;
                        foreach (var item in dic[j].Keys)
                        {
                            dic[i][item] = 1;
                        }
                    }
                }

                int myb = b[i];
                for (int j = i + 1; j < n; j++)
                {
                    if (b[j] < myb)
                    {
                        dic[i][j] = 1;
                        foreach (var item in dic[j].Keys)
                        {
                            dic[i][item] = 1;
                        }

                        if (myb == b[j] + 1)
                        {
                            myb--;
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                int need = dic[i].Count;
                ret[i] = l[need];
                l.Remove(ret[i]);
            }

            for (int i = 0; i < n; i++)
            {
                if (i != n - 1) Console.Write(ret[i] + " ");
                else Console.WriteLine(ret[i]);
            }

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