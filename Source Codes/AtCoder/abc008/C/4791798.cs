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




    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int N = sc.intarr[0];
        int[] C = new int[N];
        double ans = 0.0;
        for (int i = 0; i < N; ++i)
        {
            C[i] = sc.intarr[0];

        }

        for (int i = 0; i < N; ++i)
        {
            int su = 0;
            for (int j = 0; j < N; ++j)
            {
                if (i != j && C[i] % C[j] == 0) su++;

            }
            if (su % 2 == 1) ans += 0.5;
            else ans += (double)(su + 2) / (2 * su + 2);

        }
        wr.wri(ans);
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