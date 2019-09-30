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

        string k1 = sc.str;
        string k2 = sc.str;
        string k3 = sc.str;
        wr.wri<string>(k1[0].ToString() + k2[1].ToString() + k3[2].ToString());
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