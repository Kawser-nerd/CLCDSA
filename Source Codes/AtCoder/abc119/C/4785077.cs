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




    static int N;
    static int A;
    static int B;
    static int C;
    static int[] l;




    static int DFS(int depth ,int a,int b,int c)
    {
        if (depth == N)
        {
            if (a == 0 || b == 0 || c == 0) return INF;
            return Math.Abs(A - a) + Math.Abs(B - b) + Math.Abs(C - c)-30;
        }
        int ret=INF;
        ret = Math.Min(ret, DFS(depth + 1, a + l[depth], b, c) + 10);
        ret = Math.Min(ret, DFS(depth + 1, a, b + l[depth], c) + 10);
        ret = Math.Min(ret, DFS(depth + 1, a, b, c + l[depth]) + 10);
        ret = Math.Min(ret, DFS(depth + 1, a, b, c ));


        return ret;
    }



    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        var ss = sc.intarr;
         N = ss[0];
         A = ss[1];
         B = ss[2];
         C = ss[3];
         l = new int[N];
        for(int i = 0; i <N; ++i) l[i] = sc.intarr[0];



        wr.wri(DFS(0, 0, 0, 0));

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