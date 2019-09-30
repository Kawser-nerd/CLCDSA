using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }


    class Shi : IComparable<Shi>
    {
        public int P;
        public int Y;
        public int ID;

        public Shi(int P, int Y, int ID)
        {
            this.P = P;
            this.Y = Y;
            this.ID = ID;
        }

        int IComparable<Shi>.CompareTo(Shi other)
        {
            if (P != other.P) return P.CompareTo(other.P);
            else return Y.CompareTo(other.Y);
        }
    }


    Scanner cin;

    void calc()
    {
        cin = new Scanner();
        string S = cin.next();
        int w = 0;
        long ans = 0;
        for (int i = S.Length - 1; i >= 0; i--)
        {
            if (S[i] == 'W') w++;
            else ans += w;
        }
        Console.WriteLine(ans);
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}