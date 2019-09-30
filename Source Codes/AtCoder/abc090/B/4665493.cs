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

        var s = sc.intarr;
        int a = s[0];
        int b = s[1];
        long ans = 0;

        for(int i = a; i <= b; ++i)
        {
            string c = i.ToString();
            if (c[0] == c[4] && c[1] == c[3]) ans++;
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