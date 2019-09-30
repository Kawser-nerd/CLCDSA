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

    static int digitsum(int x)
    {
        string s = x.ToString();
        int ret = 0;
        for(int i = 0; i < s.Length; ++i)
        {
            ret += s[i] - '0';
        }
        return ret;
    }


    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int n = sc.intarr[0];
        if (n % digitsum(n) == 0)
        {
            wr.wri("Yes");
        }
        else wr.wri("No");
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