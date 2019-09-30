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


        var c = sc.intarr;
        int n = c[0];
        int ans = 0;


        Dictionary<string, int> a= new Dictionary<string, int>();

        for(int i = 0; i < n ; ++i)
        {
            
            string s = sc.str;
            if (a.ContainsKey(s))
            {
                a[s]++;

            }
            else a[s] = 1;
        }
         c = sc.intarr;
        int m = c[0];
        for (int i = 0; i < m; ++i)
        {
            string s = sc.str;
            if (a.ContainsKey(s))
            {
                a[s]--;

            }
        }

        foreach(var x in a)
        {
            ans = Math.Max(ans, x.Value);
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