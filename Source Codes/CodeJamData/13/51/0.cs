using System;
using System.Collections.Generic;
using System.Linq;
//using System.Threading.Tasks;
//using System.Numerics;

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

    long mod = 1000002013;
    void calc()
    {
        Scanner cin = new Scanner();
        int testCase = cin.nextInt();
        init();

        for (int test = 1; test <= testCase; test++)
        {
            Console.Write("Case #{0}: ", test);
            long b = cin.nextLong();
            int n = cin.nextInt();
            int MAX = 37;
            
            long[] num = new long[MAX];
            for (int i = 0; i < n; i++)
            {
                num[i] = cin.nextLong();
            }
            Array.Sort(num);

            long first = num[0];
            double ret = 0;
            long temp = 0;
            long pretemp = 0;

            int movedist = 20;
            for (int i = 1; i < MAX; i++)
            {
                pretemp = temp;
                temp += num[i - 1];
                if (num[i - 1] == num[i]) continue;
                for (int j = 1; j <= i; j++)
                {
                    long tempmax = (b + temp) / i - (i + 1 - j);
                    for (long max = tempmax - movedist; max <= tempmax + movedist; max++)
                    {
                        if (max <= 0) continue;
                        if (num[j - 1] > max) continue;

                        long okcoin = 0;
                        long ngcoin = 0;
                        long othercoin = 0;

                        for (int k = 0; k < j; k++)
                        {
                            okcoin += max - num[k];
                            othercoin += num[k];
                        }
                        for (int k = j; k < MAX; k++)
                        {
                            ngcoin += Math.Max(0, (max + 1) - num[k]);
                        }
                        if (okcoin + ngcoin > b) continue;

                        //Console.WriteLine("now: " + i + " " + j + " " + max);
                        //Console.WriteLine(okcoin + " " + ngcoin + " " + othercoin);
                        double tempret = ((okcoin + othercoin) * 36.0 / j * okcoin / (okcoin + othercoin)) - okcoin - ngcoin;
                        //Console.WriteLine(tempret);
                        ret = Math.Max(tempret, ret);
                    }

                    tempmax = (b + pretemp) / i - (i + 1 - j);
                    for (long max = tempmax - movedist; max <= tempmax + movedist; max++)
                    {
                        if (max <= 0) continue;
                        if (num[j - 1] > max) continue;

                        long okcoin = 0;
                        long ngcoin = 0;
                        long othercoin = 0;

                        for (int k = 0; k < j; k++)
                        {
                            okcoin += max - num[k];
                            othercoin += num[k];
                        }
                        for (int k = j; k < MAX; k++)
                        {
                            ngcoin += Math.Max(0, (max + 1) - num[k]);
                        }
                        if (okcoin + ngcoin > b) continue;

                        //Console.WriteLine("now: " + i + " " + j + " " + max);
                        //Console.WriteLine(okcoin + " " + ngcoin + " " + othercoin);
                        double tempret = ((okcoin + othercoin) * 36.0 / j * okcoin / (okcoin + othercoin)) - okcoin - ngcoin;
                        //Console.WriteLine(tempret);
                        ret = Math.Max(tempret, ret);
                    }

                    tempmax = num[i] - 1;
                    for (long max = tempmax - movedist; max <= tempmax + movedist; max++)
                    {
                        if (max <= 0) continue;
                        if (num[j - 1] > max) continue;

                        long okcoin = 0;
                        long ngcoin = 0;
                        long othercoin = 0;

                        for (int k = 0; k < j; k++)
                        {
                            okcoin += max - num[k];
                            othercoin += num[k];
                        }
                        for (int k = j; k < MAX; k++)
                        {
                            ngcoin += Math.Max(0, (max + 1) - num[k]);
                        }
                        if (okcoin + ngcoin > b) continue;

                        //Console.WriteLine("now: " + i + " " + j + " " + max);
                        //Console.WriteLine(okcoin + " " + ngcoin + " " + othercoin);
                        double tempret = ((okcoin + othercoin) * 36.0 / j * okcoin / (okcoin + othercoin)) - okcoin - ngcoin;
                        //Console.WriteLine(tempret);
                        ret = Math.Max(tempret, ret);
                    }
                }


            }

            Console.WriteLine("{0:0.00000000000000}", ret);
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