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

        var lss=sc.intarr;
        int n = lss[0];

        var s = sc.str;

        int ans = 0;

        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            var a = new HashSet<int>();
            var b = new HashSet<int>();

            for (int j = 0; j < i; ++j)
            {
                a.Add(s[j]-'a');
            }

            for (int k = i; k < n; ++k)
            {
                b.Add(s[k]-'a');
            }
            for(int l = 0; l < 26; ++l)
            {

                    
                    if (a.Contains(l) && b.Contains(l))
                    {
                        sum++;
                    }
                
            }
            ans = Math.Max(sum, ans);
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