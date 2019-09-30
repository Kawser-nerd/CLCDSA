using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



class Program
{
    const int MOD = 1000000007;
    const int INF = 1 << 30;
    static int[] num = { 1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049 };

    static void Main(string[] args)
    {
        Solve();
    }




    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int N = sc.intarr[0];

        int[] dp = new int[N + 1];


        dp[0] = 0;
        for(int i = 1; i <= N; ++i)
        {
            dp[i] = INF;
        }
        for(int i = 1; i <= N; ++i)
        {
            for(int j = 0; j < 12; ++j)
            {
                if (i - num[j] >= 0)
                {
                    dp[i] = Math.Min(dp[i], dp[i - num[j]] + 1);
                }
            }
        }

        wr.wri(dp[N]);

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