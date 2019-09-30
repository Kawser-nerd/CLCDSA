using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;

class Myon
{
    static Scanner cin;
    public Myon() { }
    public static int Main()
    {
        //Console.SetOut(new Printer(Console.OpenStandardOutput()));
        cin = new Scanner();
        new Myon().calc();
        return 0;
    }


    public void calc()
    {
        string S = cin.next();
        bool A = (S[0] == S[S.Length - 1]);
        bool B = (S.Length % 2 == 1);
        if (A ^ B) Console.WriteLine("First");
        else Console.WriteLine("Second");
    }
}

class Printer : StreamWriter
{
    public override IFormatProvider FormatProvider { get { return CultureInfo.InvariantCulture; } }
    public Printer(Stream stream) : base(stream, new UTF8Encoding(false, true)) { }
    public Printer(Stream stream, Encoding encoding) : base(stream, encoding) { }
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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