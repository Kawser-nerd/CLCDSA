using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



class Program
{
    const int MOD = 1000000007;
    const int INF = 1 << 30;

    static void Main(string[] args)
    {
        Solve();
    }
    static long GCD(long x,long y)
    {
        if (y == 0) return x;
        return GCD(y, x % y);
    }

    static long LCM(long x,long y)
    {
        return x * y / GCD(x, y);
    }


    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        bool ac = true;
        string S = sc.str;
        if (S[0] != 'A') ac = false;
        bool isC = false;
        int Ci = -1;
        for (int i = 2; i < S.Length - 1; ++i)
        {
            if (!isC && S[i] == 'C')
            {
                isC = true;
                Ci = i;
            }
            else if (isC && S[i] == 'C')
            {
                ac = false;
            }

        }
        if (!isC) ac = false;
        for (int i = 0; i < S.Length; ++i)
        {
            if (i != 0 && i != Ci)
            {
                if (S[i] < 'a')
                {
                    ac = false;
                }
            }
        }
        if (ac) wr.wri("AC");
        else wr.wri("WA");
    }
}
    




class Scan
{
        public string str => Console.ReadLine();

        public string[] strarr => str.Split(' ');

        public long[] longarr => strarr.Select(long.Parse).ToArray();
        public int[] intarr => strarr.Select(int.Parse).ToArray();
    public char[] chararr => str.ToArray();


}



class write
{
    public void wri<Type>(Type x)
    {
        Console.WriteLine(x);
    }
}