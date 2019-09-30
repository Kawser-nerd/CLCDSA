using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class Program
{


    static void Main(string[] args)
    {
        Solve();
    }

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        int n =sc.intarr[0];
        var k = sc.intarr;
        int d = k[0];
        int x = k[1];

        int ans = x;
        for(int i = 0; i < n; ++i)
        {
            int a = sc.intarr[0];
            for(int j = 1; j <= d; j+=a)
            {
                ans++;
            }
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
        public char[] chararr => strarr.Select(char.Parse).ToArray();


}



class write
{
    public void wri<Type>(Type x)
    {
        Console.WriteLine(x);
    }
}