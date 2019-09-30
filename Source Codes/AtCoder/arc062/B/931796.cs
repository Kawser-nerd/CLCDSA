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
        string s = cin.next();
        int N = s.Length;

        int totalscore = 0;
        for(int i = 0;i<N;i++)
        {
            char h = i % 2 == 0 ? 'g' : 'p';
            totalscore += score(h, s[i]);
        }

        Console.WriteLine(totalscore);
    }

    private int score(char h1,char h2)
    {
        if (h1 == h2) return 0;
        if (h1 == 'g' && h2 == 'p') return -1;
        if (h1 == 'p' && h2 == 'g') return 1;
        return 0;
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