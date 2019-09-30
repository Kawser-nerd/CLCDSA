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
    string chs = "ABXY";

    public void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        string s = cin.next();

        int ans = 10000;
        foreach(var LR in shortcut())
        {
            var L = LR.Item1;
            var R = LR.Item2;

            int pos = 0;
            int min = 0;
            while (pos < N)
            {
                if (pos < N - 1 && (s.Substring(pos, 2) == L || s.Substring(pos, 2) == R))
                {
                    min++;
                    pos += 2;
                }
                else
                {
                    min++;
                    pos++;
                }
            }

            ans = Math.Min(ans, min);
        }


        Console.WriteLine(ans);
        Console.Read();
    }

    IEnumerable<Tuple<string,string>> shortcut()
    {
        for (int i1 = 0; i1 < 4; i1++)
            for (int i2 = 0; i2 < 4; i2++)
                for (int i3 = 0; i3 < 4; i3++)
                    for (int i4 = 0; i4 < 4; i4++)
                    {
                        string L = chs[i1].ToString() + chs[i2].ToString();
                        string R = chs[i3].ToString() + chs[i4].ToString();

                        if (L != R) yield return new Tuple<string, string>(L, R);
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