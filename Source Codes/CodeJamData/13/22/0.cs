using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Numerics;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    void init()
    {

    }

    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            int n = cin.nextInt();
            int x = Math.Abs(cin.nextInt());
            int y = cin.nextInt();
            if (x + y > 2000)
            {
                Console.WriteLine(0); continue;
            }
            if (x == 0)
            {
                int need = (y + 1) * (y + 2) / 2;
                if (n >= need) Console.WriteLine(1.0);
                else Console.WriteLine(0.0);
                continue;
            }
            int sum = x + y;
            int nn = (sum - 1) * sum / 2;
            n -= nn;
            if (n <= 0)
            {
                Console.WriteLine(0.0);
                continue;
            }
            if (n >= sum * 2)
            {
                Console.WriteLine(1.0);
                continue;
            }
            double[] dp = new double[sum + 2];
            dp[0] = 1;
            for (int i = 0; i < n; i++)
            {
                double[] nextdp = new double[sum + 2];
                for (int j = 0; j <= sum; j++)
                {
                    if (j == sum)
                    {
                        nextdp[j] += dp[j];
                    }
                    else if (i - j == sum)
                    {
                        nextdp[j + 1] += dp[j];
                    }
                    else
                    {
                        nextdp[j] += 0.5 * dp[j];
                        nextdp[j + 1] += 0.5 * dp[j];
                    }
                }
                dp = nextdp;
            }
            double p = 0;
            for (int i = y + 1; i <= sum + 1; i++)
            {
                p += dp[i];
            }
            Console.WriteLine("{0:0.0000000000000000}", p);



        }

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
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
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
}