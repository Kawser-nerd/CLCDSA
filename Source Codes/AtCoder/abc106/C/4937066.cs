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

        string S=sc.str;
        long N=sc.longarr[0];
        int i = 0;
        while (i+1<=S.Length&&S[i] == '1')
        {
            i++;
        }

        if (N < i+1)
        {
            wr.wri(1);
        }
        else wr.wri(S[i]);
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