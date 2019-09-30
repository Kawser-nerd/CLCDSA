using System;
using System.Collections.Generic;
using System.Linq;

using System.Threading;
using System.Threading.Tasks;


class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;

    public void run2()
    {
        XRand r = new XRand();

        cin = new Scanner();
        int T = cin.nextInt();
        init();

        for (int i = 1; i <= T; i++)
        {
            Console.Write("Case #{0}: ", i);
            calc();
        }
    }

    XRand rnd;
    void init()
    {
        rnd = new XRand();
    }

    int[] P, S;
    List<int>[] p, s, id;
    int[] num;
    int N;
    bool[,] used;
    List<int>[] targetlist;
    int Y;

    void calc()
    {
        Y = cin.nextInt();
        N = cin.nextInt();
        P = new int[N];
        S = new int[N];
        used = new bool[2, N];

        p = new List<int>[2];
        s = new List<int>[2];
        id = new List<int>[2];
        p[0] = new List<int>();
        p[1] = new List<int>();
        s[0] = new List<int>();
        s[1] = new List<int>();
        id[0] = new List<int>();
        id[1] = new List<int>();

        targetlist = new List<int>[2];
        targetlist[0] = new List<int>();
        targetlist[1] = new List<int>();


        double ret = double.MaxValue;

        num = new int[2];

        for (int i = 0; i < N; i++)
        {
            P[i] = cin.nextInt();
        }
        for (int i = 0; i < N; i++)
        {
            S[i] = cin.nextInt();
        }

        for (int i = 0; i < N; i++)
        {
            if (P[i] > 0)
            {
                p[0].Add(P[i]);
                s[0].Add(S[i]);
                id[0].Add(i);
            }
            else
            {
                p[1].Add(P[i]);
                s[1].Add(-S[i]);
                id[1].Add(i);
            }
        }

        num[0] = p[0].Count;
        num[1] = p[1].Count;



        for (int i = 0; i < 1000; i++)
        {
            double temp = greedy();
            if (temp < ret)
            {
                if (temp < ret - 1e9)
                {
                    i = 0;
                }
                ret = temp;
            }
        }

        Console.Error.WriteLine(targetlist[0].Count + " " + targetlist[1].Count);
        Console.WriteLine("{0:0.000000000000000}", ret);
    }

    double greedy()
    {
        int go = 1;
        if (rnd.nextInt(2) == 0) go = 0;

        double pos = 0;
        double ret = 0;
        int pass = 0;
        int lastneedid = -1;
        bool[][] check = new bool[2][];
        check[0] = new bool[num[0]];
        check[1] = new bool[num[1]];

        while (pass < 2)
        {
            double need = 0;
            int needid = -1;
            int targetnum = -1;
            if (targetlist[go].Count != 0)
            {
                targetnum = targetlist[go][rnd.nextInt(targetlist[go].Count)];
                if (check[go][targetnum]) targetnum = -1;
            }

            if (targetnum == -1)
            {
                for (int i = 0; i < num[go]; i++)
                {
                    if (check[go][i]) continue;
                    double tempdist = Math.Abs(p[go][i] + s[go][i] * ret - pos);
                    double temps = Y - Math.Abs(s[go][i]);
                    double temptime = tempdist / temps;
                    if (temptime > need)
                    {
                        need = temptime;
                        needid = i;
                    }
                    check[go][i] = true;
                }
            }
            else
            {
                if (check[go][targetnum]) continue;
                double tempdist2 = Math.Abs(p[go][targetnum] + s[go][targetnum] * ret - pos);
                double temps2 = Y - Math.Abs(s[go][targetnum]);
                need = tempdist2 / temps2;
                check[go][targetnum] = true;
                needid = targetnum;

                for (int i = 0; i < num[go]; i++)
                {
                    if (check[go][i]) continue;
                    double tempdist = Math.Abs(p[go][i] + s[go][i] * ret - pos);
                    double temps = Y - Math.Abs(s[go][i]);
                    double temptime = tempdist / temps;
                    if (temptime <= need + 1e-9)
                    {
                        check[go][i] = true;
                    }
                }
            }

            if (need == 0)
            {
                pass++;
            }
            else
            {
                pass = 0;
                lastneedid = needid;
                ret += need;
                if (go == 0) pos += need * Y;
                else pos -= need * Y;
            }

            go ^= 1;
        }
        go ^= 1;
        if(!used[go, lastneedid]){
            targetlist[go].Add(lastneedid);
            used[go, lastneedid] = true;
        }
        return ret;
    }

    //配列のランダム並び替え
    void randomshuffle<T>(T[] a)
    {
        int len = a.Length;
        for (int i = 0; i < len - 1; i++)
        {
            swap(ref a[i], ref a[i + rnd.nextInt(len - i)]);
        }
    }

    //swap
    void swap<T>(ref T a, ref T b)
    {
        T c = a;
        a = b;
        b = c;
    } 

}

class XRand
{
    uint x, y, z, w;


    public XRand()
    {
        init();
    }

    public XRand(uint s)
    {
        init();
        init_xor128(s);
    }

    void init()
    {
        x = 314159265; y = 358979323; z = 846264338; w = 327950288;

    }

    public void init_xor128(uint s)
    {
        z ^= s;
        z ^= z >> 21; z ^= z << 35; z ^= z >> 4;
        z *= 736338717;
    }

    uint next()
    {
        uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
    }

    public long nextLong(long m)
    {
        return (long)((((ulong)next() << 32) + next()) % (ulong)m);
    }

    public int nextInt(int m)
    {
        return (int)(next() % m);
    }

    public int nextIntP(int a)
    {
        return (int)Math.Pow(a, nextDouble());
    }

    public int nextInt(int min, int max)
    {
        return min + nextInt(max - min + 1);
    }


    public double nextDouble()
    {
        return (double)next() / uint.MaxValue;
    }

    public double nextDoubleP(double a)
    {
        return Math.Pow(a, nextDouble());
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
