using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class MakeARectangle
{
    static void Main(string[] args)
    {
        //var sw = new System.Diagnostics.Stopwatch();
        //sw.Start();

        Console.ReadLine(); // ???????? LINQ?????
        var stick = Console.ReadLine().Split(' ').Select(x => uint.Parse(x)).ToList();

        ulong largest = 0, larger = 0;
        //var unique = new List<ulong>();

        stick.Sort();
        int xx = stick.Count();
        while (1 < xx--)
        {
            if (stick[xx] == stick[xx - 1])
            {
                if (largest > 0)
                {
                    larger = stick[xx];
                    break;
                }
                else
                {
                    largest = stick[xx];
                }
                xx--;
            }
        }

        //foreach (var x in stick)
        //{

        //    if (larger < x)
        //    {

        //        if (unique.Remove(x))
        //        { // 2???????

        //            larger = x;
        //            if (largest < larger)
        //            {

        //                larger ^= largest;
        //                largest ^= larger;
        //                larger ^= largest;
        //            }

        //        }
        //        else
        //        {
        //            unique.Add(x);
        //        }
        //    }

        //}

        Console.WriteLine($"{ umulh(larger, largest).ToString("#") }{larger * largest}");
        //sw.Stop();
        //Console.WriteLine($"?{sw.ElapsedMilliseconds}???");
    }

    // ulong?????64bit???
    // ?? (http://d.hatena.ne.jp/n7shi/20100630/1277983197)
    static public ulong umulh(ulong x, ulong y)
    {
        ulong xh = x >> 32, xl = x & 0xffffffff;
        ulong yh = y >> 32, yl = y & 0xffffffff;
        ulong a = xh * yl, ah = a >> 32, al = a & 0xffffffff;
        ulong b = xl * yh, bh = b >> 32, bl = b & 0xffffffff;
        return ((((xl * yl) >> 32) + al + bl) >> 32) + ah + bh + xh * yh;
    }
}