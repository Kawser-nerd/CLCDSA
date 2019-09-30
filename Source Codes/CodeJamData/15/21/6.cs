using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B
{
    class A
    {
        static void Main(string[] args)
        {
            using (var streamWriter = new StreamWriter(new FileStream("./output.txt", FileMode.Create, FileAccess.Write)))
            {
                using (var streamReader = new StreamReader(new FileStream("./input.txt", FileMode.Open, FileAccess.Read)))
                {
                    Console.SetIn(streamReader);
                    Console.SetOut(streamWriter);

                    var t = int.Parse(Console.In.ReadLine());
                    //var array = new int[10000001];
                    //for (var j = 1; j<=10000000; ++j)
                    //{
                    //    array[j] = j;
                    //}
                    //var was = new bool[10000001];
                    //var list = new List<int>();
                    //list.Add(1);
                    //was[1] = true;
                    //int x = 0;
                    //for (; x < list.Count && list[x] <= 10000000; ++x)
                    //{
                    //    var cur = list[x];
                    //    if (cur < 10000000 && !was[cur + 1])
                    //    {
                    //        array[cur + 1] = Math.Min(array[cur + 1], array[cur] + 1);
                    //        list.Add(cur + 1);
                    //        was[cur + 1] = true;
                    //    }
                    //    var temp = cur;
                    //    var reverse = 0;
                    //    while (temp > 0)
                    //    {
                    //        reverse *= 10;
                    //        reverse += temp % 10;
                    //        temp /= 10;
                    //    }
                    //    if (!was[reverse])
                    //    {
                    //        array[reverse] = Math.Min(array[reverse], array[cur] + 1);
                    //        list.Add(reverse);
                    //        was[reverse] = true;
                    //    }
                    //}
                    //for (var j = 1; j <= 10000000; ++j)
                    //{
                    //    if (array[j] < array[j - 1]) {
                    //        Console.WriteLine("Case #{0}: {1}", j, array[j]);
                    //    }
                    //}
                    for (int i = 1; i <= t; ++i)
                    {
                        var n = long.Parse(Console.In.ReadLine());
                        long answer = 0;
                        while (n > 1) {
                            var z = getLower(n);
                            answer += n - z;
                            n = reverse(z);
                            if (n > 1) {
                                ++answer;
                            }
                        }
                        Console.WriteLine("Case #{0}: {1}", i, answer + 1);
                    }
                }
            }  
        }

        static long reverse(long v)
        {
            var left = v;
            long rev = 0;
            while (left > 0)
            {
                var r = left % 10;
                rev = rev * 10 + r;
                left = left / 10;
            }
            return rev;
        }

        static long getLower(long v)
        {
            var ful =  getCount(v);
            var hafm =  ful / 2;
            var med = (ful + 1) / 2;
            var tv = v;
            long z = 1;
            long x = 1;
            while (med > 0)
            {
                x *= 10;
                --med;
            }
            while (hafm > 1)
            {
                z *= 10;
                --hafm;
            }
            tv /= x;
            var res = tv * x + 1;
            if (tv == z) {
                long t = 1;
                while (ful > 1)
                {
                    t *= 10;
                    --ful;
                }
                return getLower(t-1);
            }
            if (res > v)
            {
                return getLower(res-2);
            }
            return res;
        }

        static int getCount(long v)
        {
            var res = 0;
            while (v > 0)
            {
                v /= 10;
                ++res;
            }
            return res;
        }
    }
}
