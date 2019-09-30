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

        var x = sc.intarr[0];

        int ma = 1;
        for(int i = 1; i <= 35; ++i)
        {
            for(int j = 2; j <= 10; ++j)
            {
                
                if ((int)Math.Pow(i, j) <= x&& (int)Math.Pow(i, j)>=1)
                {

                    int l = (int)Math.Pow(i, j);
                    //wr.wri(l);
                    ma = Math.Max(ma, l);
                }
            }
        }

        wr.wri(ma);

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