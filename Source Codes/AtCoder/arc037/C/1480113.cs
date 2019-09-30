using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }

    Scanner cin;

    Dictionary<long, Pos> dic;

    class Pos
    {
        public int U, R, D, L;
        public Pos(int U, int R, int D, int L)
        {
            this.U = U;
            this.R = R;
            this.D = D;
            this.L = L;
        }
    }
    
    long hash(long a, long b)
    {
        return a * 17361318631L + b * 1238916381L;
    }

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        long K = cin.nextLong();
        int[] A = new int[N];
        int[] B = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextInt();
        }
        for (int i = 0; i < N; i++)
        {
            B[i] = cin.nextInt();
        }
        Array.Sort(A);
        Array.Sort(B);

        long mi = 0;
        long ma = (long)2e18;
        while(ma - mi > 1)
        {
            long mid = (mi + ma) / 2;

            long ans = 0;
            int pos = N - 1;
            for (int i = 0; i < N; i++)
            {
                while (pos >= 0 && (long)A[i] * B[pos] > mid) pos--;
                ans += pos + 1;
            }

            if (ans >= K) ma = mid;
            else mi = mid;
        }
        Console.WriteLine(ma);
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