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
        string S = cin.next();
        dic = new Dictionary<long, Pos>();
        dic[hash(0, 0)] = new Pos(-1, 1, 1, -1);

        int y = 0;
        int x = 0;

        for (int i = 0; i < N; i++)
        {
            push(y, x);
            char c = S[i];
            if (c == 'U') y = dic[hash(y, x)].U;
            if (c == 'R') x = dic[hash(y, x)].R;
            if (c == 'D') y = dic[hash(y, x)].D;
            if (c == 'L') x = dic[hash(y, x)].L;
        }
        Console.WriteLine(x + " "  + (-y));
    }

    void push(int y, int x)
    {
        Pos p = dic[hash(y, x)];
        long uhash = hash(p.U, x);
        long rhash = hash(y, p.R);
        long dhash = hash(p.D, x);
        long lhash = hash(y, p.L);

        if (dic.ContainsKey(uhash)) dic[uhash].D = p.D;
        else dic[uhash] = new Pos(p.U - 1, x + 1, p.D, x - 1);

        if (dic.ContainsKey(dhash)) dic[dhash].U = p.U;
        else dic[dhash] = new Pos(p.U, x + 1, p.D + 1, x - 1);

        if (dic.ContainsKey(rhash)) dic[rhash].L = p.L;
        else dic[rhash] = new Pos(y - 1, p.R + 1, y + 1, p.L);

        if (dic.ContainsKey(lhash)) dic[lhash].R = p.R;
        else dic[lhash] = new Pos(y - 1, p.R, y + 1, p.L - 1);

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