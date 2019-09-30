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


    void init()
    {
        
    }

    int H, W;
    string[] board;
    Dictionary<char, int> dic;
    int[] dx = { 0, 1, 0, -1 };
    int[] dy = { -1, 0, 1, 0 };

    void calc()
    {
        H = cin.nextInt();
        W = cin.nextInt();
        board = new string[H];
        dic = new Dictionary<char, int>();

        dic['.'] = -1;
        dic['^'] = 0;
        dic['>'] = 1;
        dic['v'] = 2;
        dic['<'] = 3;

        for (int i = 0; i < H; i++)
        {
            board[i] = cin.next();
        }

        int ans = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                int k = dic[board[i][j]];
                if (k == -1) continue;
                int y = i;
                int x = j;
                if (!check(y, x, k))
                {
                    ans++;
                    int ans2 = 0;
                    for (int k2 = 0; k2 < 4; k2++)
                    {
                        if (check(y, x, k2)) ans2++;
                    }
                    if (ans2 == 0)
                    {
                        Console.WriteLine("IMPOSSIBLE");
                        return;
                    }
                }
            }
        }
        Console.WriteLine(ans);
    }

    bool check(int y, int x, int k)
    {
        do
        {
            y += dy[k];
            x += dx[k];
        } while (ok(y, x) && board[y][x] == '.');
        if (ok(y, x)) return true;
        else return false;
    }

    bool ok(int y, int x)
    {
        return y >= 0 && x >= 0 && y < H && x < W;
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
