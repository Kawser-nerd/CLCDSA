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

        string s = sc.str;
        string t = sc.str;

        for(int i = 0; i < s.Length; ++i)
        {
            string u = s.Substring(0, i);
            string v = s.Substring(i);
            if (t == v + u)
            {
                wr.wri("Yes");
                return ;
            }
        }
        wr.wri("No");
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