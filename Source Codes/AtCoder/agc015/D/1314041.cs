//D
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

    void calc()
    {
        cin = new Scanner();
        long A, B;
        A = cin.nextLong();
        B = cin.nextLong();
        Console.WriteLine(solve(A, B));
    }

    //bool debug = true;

    Dictionary<long, long> dic = new Dictionary<long, long>();

    long solve(long A, long B)
    {
        int pos = 60;
        long ans = 0;

        while (pos >= 0)
        {
            if ((A >> pos) % 2 != (B >> pos) % 2) break;
            pos--;
        }
        if (pos < 0)
        {
            //if (debug) Console.WriteLine(A + " " + B + " " + 1);
            return 1;
        }
        if(pos == 0)
        {
            //if (debug) Console.WriteLine(A + " " + B + " " + 2);
            return 2;
        }

        A %= (1L << (pos));
        B %= (1L << (pos));

        int pos2 = 60;
        while (pos2 >= 0)
        {
            if ((B >> pos2) % 2 == 1) break;
            pos2--;
        }

        long low = A;
        long high = (1L << (pos2 + 1));

        ans += (1L << pos) - low;
        if (high > low) ans += (1L << pos);
        else ans += high + (1L << pos) - low;

        return ans;
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