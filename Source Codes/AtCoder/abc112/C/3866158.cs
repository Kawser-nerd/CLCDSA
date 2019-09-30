using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program {
    static void Main() {
        Scanner cin = new Scanner();
        int N = cin.Int();
        var x = new int[N];
        var y = new int[N];
        var h = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = cin.Int();
            y[i] = cin.Int();
            h[i] = cin.Int();
        }

        int H, tmpH;
        bool flag;
        for(int Cx = 0; Cx <= 100; Cx++) {
            for(int Cy = 0; Cy <= 100; Cy++) {
                H = -1;
                flag = true;
                if (flag) {
                    for (int i = 0; i < N; i++) {
                        if (h[i] != 0) {
                            tmpH = h[i] + Math.Abs(x[i] - Cx) + Math.Abs(y[i] - Cy);
                            if (H == -1) H = tmpH;
                            if (tmpH != H) flag = false;
                        }
                    }
                }
                if (flag) {
                    for (int i = 0; i < N; i++) {
                        tmpH = H - Math.Abs(x[i] - Cx) - Math.Abs(y[i] - Cy);
                        if (tmpH < 0) tmpH = 0;
                        if (tmpH != h[i]) flag = false;
                    }
                }
                if (flag) {
                    Console.WriteLine(Cx + " " + Cy + " " + H);
                    return;
                }
            }
        }
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