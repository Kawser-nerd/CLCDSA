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

    //static long GCD(long x,long y)
    //{
    //    if (y == 0) return x;
    //    return GCD(y, x % y);
    //}

    //static long LCM(long x,long y)
    //{
    //    return x * y / GCD(x, y);
    //}

    //static int keta(int x)
    //{
    //    string s = x.ToString();
    //    return s[s.Length - 1]-'0';
    //}

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int N = sc.intarr[0];
        for(int i = 0; i <= 25; ++i)
        {
            for(int j = 0; j < 20; ++j)
            {
                if (i * 4 + j * 7 == N)
                {
                    wr.wri("Yes");
                    return ;
                    
                }
            }
        }
        wr.wri("No");

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