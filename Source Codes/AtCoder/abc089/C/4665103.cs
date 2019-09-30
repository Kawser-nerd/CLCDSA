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

        var k = sc.intarr;
        int n = k[0];

        int m = 0, a = 0, r = 0, c = 0, h = 0;
        int[] k1 = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2 };
        int[] k2 = { 1, 1, 1, 2, 2, 3, 2, 2, 3, 3 };
        int[] k3 = { 2, 3, 4, 3, 4, 4, 3, 4, 4, 4 };

        for(int i = 0; i < n; ++i)
        {
            string s = sc.str;
            if (s[0] == 'M') m++;
            if (s[0] == 'A') a++;
            if (s[0] == 'R') r++;
            if (s[0] == 'C') c++;
            if (s[0] == 'H') h++;

        }
        long ans = 0;
        long[] d = { m, a, r, c, h };
        for(int i = 0; i < 10; ++i)
        {
            ans += d[k1[i]] * d[k2[i]] * d[k3[i]];
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