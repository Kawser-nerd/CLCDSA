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
        var s = sc.chararr;
        bool han = false;
        
        foreach(var x in s)
        {
            if (x == 'Y')
            {
                han = true;
            }
        }

        if (han) wr.wri("Four");
        else wr.wri("Three");
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