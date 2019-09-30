using System;
using System.ComponentModel;
using System.Xml.XPath;

namespace ARC098D
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            long[] a = Array.ConvertAll(Console.ReadLine().Split(' '), input => long.Parse(input));

            int r = 0;
            long sum = a[0];
            long xorsum = a[0];
            long ans = 0;
            for (int l = 0; l < n; l++)
            {
                if (r < l)
                {
                    r = l;
                    sum = a[l];
                    xorsum = a[l];
                }
                while (true)
                {
                    if (r + 1 < n)
                    {
                        long s = sum + a[r + 1];
                        long x = xorsum ^ a[r + 1];
//                        Console.Write("sx ");
//                        Console.Write(s);
//                        Console.Write(' ');
//                        Console.WriteLine(x);
                        if (s == x)
                        {
                            sum = s;
                            xorsum = x;
                            r++;
                            continue;
                        }
                        sum -= a[l];
                        xorsum ^= a[l];
                    }

//                    Console.Write("lra");
//                    Console.Write(l);
//                    Console.Write(' ');
//                    Console.Write(r);
//                    Console.Write(' ');
                    ans += r - l + 1;
//                    Console.WriteLine(ans);
                    break;
                }
            }

            Console.WriteLine(ans);
        }
    }
}