using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static Scanner cin = new Scanner();
    static void Main(string[] args) {
        int Deg = cin.Int();
        double Dis = cin.Double() / 60.0;

        string deg = "";
        int dis = 0;

        if (112.5 <= Deg && Deg < 337.5) deg = "NNE";
        else if (337.5 <= Deg && Deg < 562.5) deg = "NE";
        else if (562.5 < Deg && Deg < 787.5) deg = "ENE";
        else if (787.5 <= Deg && Deg < 1012.5) deg = "E";
        else if (1012.5 <= Deg && Deg < 1237.5) deg = "ESE";
        else if (1237.5 <= Deg && Deg < 1462.5) deg = "SE";
        else if (1462.5 <= Deg && Deg < 1687.5) deg = "SSE";
        else if (1687.5 <= Deg && Deg < 1912.5) deg = "S";
        else if (1912.5 <= Deg && Deg < 2137.5) deg = "SSW";
        else if (2137.5 <= Deg && Deg < 2362.5) deg = "SW";
        else if (2362.5 <= Deg && Deg < 2587.5) deg = "WSW";
        else if (2587.5 <= Deg && Deg < 2812.5) deg = "W";
        else if (2812.5 <= Deg && Deg < 3037.5) deg = "WNW";
        else if (3037.5 <= Deg && Deg < 3262.5) deg = "NW";
        else if (3262.5 <= Deg && Deg < 3487.5) deg = "NNW";
        else deg = "N";

        if (0 <= Dis && Dis < 0.25) {
            deg = "C";
            dis = 0;
        }
        else if (0.25 <= Dis && Dis < 1.55) dis = 1;
        else if (1.55 <= Dis && Dis < 3.35) dis = 2;
        else if (3.35 <= Dis && Dis < 5.45) dis = 3;
        else if (5.45 <= Dis && Dis < 7.95) dis = 4;
        else if (7.95 <= Dis && Dis < 10.75) dis = 5;
        else if (10.75 <= Dis && Dis < 13.85) dis = 6;
        else if (13.85 <= Dis && Dis < 17.15) dis = 7;
        else if (17.15 <= Dis && Dis < 20.75) dis = 8;
        else if (20.75 <= Dis && Dis < 24.45) dis = 9;
        else if (24.45 <= Dis && Dis < 28.45) dis = 10;
        else if (28.45 <= Dis && Dis < 32.65) dis = 11;
        else if (32.65 <= Dis) dis = 12;

        Console.WriteLine(deg + " " + dis.ToString());
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