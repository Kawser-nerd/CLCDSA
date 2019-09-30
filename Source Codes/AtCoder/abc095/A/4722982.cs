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

        var s = sc.str;
        int ans = 700;
        if (s[0] == 'o') ans += 100;
        if (s[1] == 'o') ans += 100;
        if (s[2] == 'o') ans += 100;

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