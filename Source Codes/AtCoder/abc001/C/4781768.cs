using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


class Program
{
    static string[] hoi = { "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };

    static void Main(string[] args)
    {
        Solve();
    }

    static void Solve()
    {
        Scan sc = new Scan();
        write wr = new write();

        var ss = sc.intarr;
        int deg = ss[0];
        double dis = ss[1];

        string ans = hoi[((int)(deg * 10 + 1125) / 2250) % 16];
        int ans2 = 0;
        dis = Math.Round(dis / 60.0,1, MidpointRounding.AwayFromZero);

        if (dis <= 0.2) { ans = "C"; ans2 = 0; }
        else if (dis <= 1.5) ans2 = 1;
        else if (dis <= 3.3) ans2 = 2;
        else if (dis <= 5.4) ans2 = 3;
        else if (dis <= 7.9) ans2 = 4;
        else if (dis <= 10.7) ans2 = 5;
        else if (dis <= 13.8) ans2 = 6;
        else if (dis <= 17.1) ans2 = 7;
        else if (dis <= 20.7) ans2 = 8;
        else if (dis <= 24.4) ans2 = 9;
        else if (dis <= 28.4) ans2 = 10;
        else if (dis <= 32.6) ans2 = 11;
        else if (dis >= 32.7) ans2 = 12;
        wr.wri(ans + " " + ans2);
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