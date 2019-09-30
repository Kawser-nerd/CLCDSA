using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Prog
{
    public Prog() { }
    public static int Main()
    {
        new Prog().calc();
        return 0;
    }

    Scanner cin;

    public void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int M = cin.nextInt();

        // bit DP
        // dp[i] := ????i??????????????
        long[] dp = new long[1 << N];

        // t[y] := y???????????????
        int[] t = new int[N];

        for(int i = 0;i<M;i++)
        {
            // x -> y ?????????
            int x = cin.nextInt() - 1;
            int y = cin.nextInt() - 1;

            // t[y]???x??????????
            t[y] |= 1 << x;
        }

        // ????????1
        dp[0] = 1;

        for (int i = 0; i < (1 << N); i++)
        {
            for(int j =0;j<N;j++)
            {
                // (i >> j & 1) == 0  ??????i???j?????
                // (i | t[j]) == i  ???????i???j????????????t[j]???????
                //                    ????j??????i??????????
                //                        (????????dp?????????

                // i | 1 << j := ????i???j????????

                if ((i >> j & 1) == 0 && (i | t[j]) == i)
                    dp[i | 1 << j] += dp[i];                  
            }
        }

        Console.WriteLine(dp[(1 << N) - 1]);
        Console.Read();
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
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
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