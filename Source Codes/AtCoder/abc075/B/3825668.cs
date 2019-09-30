using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        Scanner cin = new Scanner();

        int h = cin.Int();
        int w = cin.Int();
        string[] s = new string[h + 2];

        for(int i = 1; i <= w + 2; i++)
        {
            s[0] += ".";
            s[h + 1] += ".";
        }
        for (int i = 1; i <= h; i++)
        {
            s[i] = "." + Console.ReadLine() + ".";
        }

        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                if(s[i][j] == '.')
                {
                    int cnt = 0;
                    for(int k = i - 1; k <= i + 1; k++)
                    {
                        for(int l = j - 1; l <= j + 1; l++)
                        {
                            if (s[k][l] == '#') cnt++;
                        }
                    }
                    s[i] = s[i].Substring(0, j) + cnt.ToString() + s[i].Substring(j + 1);
                }
            }
        }

        for(int i = 1; i <= h; i++)
        {
            s[i] = s[i].Substring(1, w);
            Console.WriteLine(s[i]);
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