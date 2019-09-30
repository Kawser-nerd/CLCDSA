using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        //ABC065
        Scanner cin = new Scanner();
        int N = cin.Int();
        var a = cin.ArrayInt(N);

        var color = new int[9]; //color[0]??color[7]?????????????colot[8]????3200?????
        foreach(var x in a)
        {
            if (1 <= x && x <= 399) color[0]++;
            else if (400 <= x && x <= 799) color[1]++;
            else if (800 <= x && x <= 1199) color[2]++;
            else if (1200 <= x && x <= 1599) color[3]++;
            else if (1600 <= x && x <= 1999) color[4]++;
            else if (2000 <= x && x <= 2399) color[5]++;
            else if (2400 <= x && x <= 2799) color[6]++;
            else if (2800 <= x && x <= 3199) color[7]++;
            else color[8]++;
        }

        int min_ans = 0;
        for(int i = 0; i <= 7; i++)
        {
            if (color[i] > 0) min_ans++;
        }

        if (min_ans == 0) Console.WriteLine(1 + " " + color[8]);
        else Console.WriteLine(min_ans + " "  + (min_ans + color[8]));
        Console.ReadLine();
    }
}

class Scanner //????
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

    public int Int()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Int() + add;
        }
        return Array;
    }

    public long Long()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Long() + add;
        }
        return Array;
    }

    public double Double()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = Double() + add;
        }
        return Array;
    }
}