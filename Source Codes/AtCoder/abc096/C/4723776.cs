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

        var t = sc.intarr;
        int h = t[0];
        int w = t[1];

        bool ans = true;

        char[,] s = new char[h+2, w+2];

        for(int i = 0; i < h+2; ++i)
        {
            string ss="";
            if(i!=h+1&&i!=0) ss = sc.str;
            for(int j = 0; j < w+2; ++j)
            {
                if (i == 0 || i == h+1  || j == 0 || j == w+1)
                {
                    s[i, j] = '.';
                }
                else
                s[i, j] = ss[j-1];
            }
        }

        for(int i = 1; i < h+1; ++i)
        {
            for(int j = 1; j < w+1; ++j)
            {
                if(s[i,j]=='#'&&s[i-1,j]=='.' && s[i + 1, j] == '.' && s[i , j-1] == '.' && s[i , j+1] == '.')
                {
                    ans = false;
                }
            }
        }

        if (ans) wr.wri("Yes");
        else wr.wri("No");
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