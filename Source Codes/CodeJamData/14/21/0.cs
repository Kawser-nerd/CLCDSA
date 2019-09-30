using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);
            //Console.WriteLine("Case #{0}:", i + 1);

            run();
        }
    }


    void run()
    {
        int ret = 0;
        int n = cin.nextInt();
        string[] st = new string[n];
        for (int i = 0; i < n; i++)
        {
            st[i] = cin.next();
        }

        for (int i = 0; i < n - 1; i++)
        {
            int r = calc(st[i], st[i + 1]);
            if (r == -1)
            {
                Console.WriteLine("Fegla Won");
                return;
            }
            ret += r;
        }

        

        //ret = 0;
        List<int>[] l = new List<int>[n];
        for (int i = 0; i < n; i++)
        {
            l[i] = calc2(st[i]);
        }

        ret = 0;
        int m = l[0].Count;
        for (int i = 0; i < m; i++)
        {
            int[] nums = new int[n];
            for (int j = 0; j < n; j++)
            {
                nums[j] = l[j][i];
            }
            Array.Sort(nums);

            int target = nums[nums.Length / 2];
            for (int j = 0; j < n; j++)
            {
                ret += Math.Abs(nums[j] - target);
            }
        }
        Console.WriteLine(ret);

    }

    int calc(string a, string b)
    {
        int ret = 0;

        int ap = 0;
        int bp = 0;
        while (a.Length > ap || b.Length >bp)
        {
            if (a.Length == ap || b.Length == bp) return -1;
            if (a[ap] != b[bp]) return -1;
            int anum = 0;
            char ac = a[ap];
            while (a.Length > ap && ac == a[ap])
            {
                anum++;
                ap++;
            }

            int bnum = 0;
            char bc = b[bp];
            while (b.Length > bp && bc == b[bp])
            {
                bnum++;
                bp++;
            }

            ret += Math.Abs(anum - bnum);
        }
        return ret;

    }

    List<int> calc2(string a)
    {
        List<int> ret = new List<int>();

        int ap = 0;
        while (a.Length > ap )
        {
            int anum = 0;
            char ac = a[ap];
            while (a.Length > ap && ac == a[ap])
            {
                anum++;
                ap++;
            }
            ret.Add(anum);

        }
        return ret;

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

    public double nextDouble()
    {
        return double.Parse(next());
    }

}
