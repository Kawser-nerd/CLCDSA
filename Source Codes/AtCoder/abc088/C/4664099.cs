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


            int[] c1 = sc.intarr;
            int[] c2 = sc.intarr;
            int[] c3 = sc.intarr;

            bool han = false;

            
            for(int i = 0; i <= 100; ++i)
            {
                for(int j = 0; j <= 100; ++j)
                {
                    for(int k = 0; k <= 100; ++k)
                    {
                        if(c1[0]-i==c1[1]-j&& c1[1]-j == c1[2]-k&& c2[0] - i == c2[1] - j && c2[1] - j == c2[2] - k && c3[0] - i == c3[1] - j && c3[1] - j == c3[2] - k)
                        {
                        han = true;
                        }
                    }
                }
            }

        if (han) wr.wri("Yes");
        else wr.wri("No");
        }
}


    class Scan
    {
    public string str => Console.ReadLine();

    public string[] strarr => str.Split(' ');

    public long[] longarr => strarr.Select(long.Parse).ToArray();
    public int [] intarr => strarr.Select(int.Parse).ToArray();



}

class write
{
    public void wri<Type>(Type x)
    {
        Console.WriteLine(x);
    }
}