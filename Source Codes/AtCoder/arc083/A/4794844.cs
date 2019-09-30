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

        int[] X = sc.intarr;
        int ans1 = -1;
        int ans2 = 1;
        for(int i = 0; i <=100; ++i)
        {
            for(int j = 0; j <= 100; ++j)
            {
                for(int k = 0; k <= 100; ++k)
                {
                    for(int l = 0; l <= 100; ++l)
                    {
                        int x = 100 * X[0] * i + 100 * X[1] * j ;
                        int y = X[2] * k + X[3] * l;
                        if (x == 0||x+y>X[5]||x*X[4]<y*100)
                        {
                            continue;
                        }
                        else if (ans1*(x+y)<=ans2*y)
                        {
                            ans1 = y;
                            ans2 = x+y;
                        }

                    }
                }
            }
        }
        wr.wri(ans2 + " " + ans1);


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