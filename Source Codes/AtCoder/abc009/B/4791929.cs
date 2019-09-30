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
        int[]A = new int[N];
        var list = new SortedSet<int>();
        for(int i = 0; i < N; ++i)
        {
            A[i] = sc.intarr[0];
            list.Add(A[i]);
        }
        list.Remove(list.Max);
        wr.wri(list.Max);


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