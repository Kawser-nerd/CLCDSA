using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Numerics;

class Iroha
{
    public Iroha() { }
    public static int Main()
    {
        new Iroha().calc();
        return 0;
    }

    Scanner cin;
    BigInteger f;

    void calc()
    {
        cin = new Scanner();
        BigInteger BI = 0;
        string S = cin.next();
        bool notnine = false;
        foreach (var item in S)
        {
            if (item != '9') notnine = true;
        }

        foreach (var c in S)
        {
            BI *= 10;
            BI += (int)(c - '0');
        }
        f = 1;
        for (int i = 0; i < 30; i++)
        {
            f *= 10;
        }

        BigInteger BIP = BI + 1;

        BigInteger BI2 = BI * BI;
        BigInteger BIP2 = BIP * BIP;

        BigInteger ans = -1;

        BigInteger BBB = BI;
        while (BBB % 10 == 0) BBB /= 10;
        ans = BBB * BBB;
        if (!notnine)
        {
            if (S == "9") Console.WriteLine("81");
            else if (S.Length % 2 == 0) Console.WriteLine(S);
            else Console.WriteLine(S.Substring(0, S.Length - 1) + "81");
            return;
        }

        Target = 1;
        for (int i = 1; i < S.Length; i++)
        {
            Target *= 10;
        }

        string S1 = BI2.ToString();
        string S2 = BIP2.ToString();
        while (S1.Length != S2.Length)
        {
            S1 = "0" + S1;
        }
        BigInteger BB = 0;

        for (int i = 0; i < S1.Length; i++)
        {
            BB *= 10;
            BB += (int)(S1[i] - '0');
            if (S1[i] != S2[i])
            {
                //BB++;
                //Console.WriteLine(BB);
                BigInteger temp = BB + 1;
                while (temp % 100 == 0)
                {
                    temp /= 100;
                }
                if ((temp < ans || ans == -1) && check(temp, BI, S.Length))
                {
                    ans = temp;
                }
            }
        }
        Console.WriteLine(ans);

    }

    BigInteger Target;

    bool check(BigInteger A, BigInteger B, int k)
    {
        if (B == 0) return false;
        while (B * f < Target)
        {
            B *= f;
        }
        while (B < Target)
        {
            B *= 10;
            //A *= 100;
        }
        while (B * B > A * f)
        {
            A *= f;
        }
        while (B * B > A) A *= 100;
        return B * B <= A && (B + 1) * (B + 1) > A;

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
        return next();
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