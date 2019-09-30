using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split();
            var h = Int32.Parse(s[0]);
            var w = Int32.Parse(s[1]);
            var a = Int32.Parse(s[2]);
            var b = Int32.Parse(s[3]);
            Console.WriteLine(Solve(h, w, a, b));
        }

        const Int64 mod = 1000000007;
        static Int64 Solve(int h, int w, int a, int b)
        {
            Precal_FactAndInv(mod);

            Int64 ret = 0;
            for (int i = 0; i < h - a; i++)
            {
                var c = Nck(b + i - 1, i, mod);
                c *= Nck(w - b - 1 + h - 1 - i, h - 1 - i, mod);
                ret += c;
                ret %= mod;
            }
            return ret;
        }

        static Int64[] fact = new Int64[200005];
        static Int64[] inv = new Int64[200005];

        static void Precal_FactAndInv(Int64 mod)
        {
            fact[0] = 1;
            inv[0] = ModInv(1, mod);

            for (Int64 i = 1; i < 200005; i++)
            {
                fact[i] = (fact[i - 1] * i) % mod;
                inv[i] = ModInv(fact[i], mod);
            }
        }

        static public Int64 ExtGcd(Int64 a, Int64 b, ref Int64 x, ref Int64 y)
        {
            Int64 d = a;
            if (b != 0)
            {
                d = ExtGcd(b, a % b, ref y, ref x);
                y -= (a / b) * x;
            }
            else
            {
                x = 1;
                y = 0;
            }
            return d;
        }

        static Int64 ModInv(Int64 a, Int64 m)
        {
            Int64 x = 0, y = 0;
            ExtGcd(a, m, ref x, ref y);
            if (x < 0) x += m; //modInv is never negative
            return x;
        }

        static Int64 Nck(int n, int k, Int64 mod)
        {
            return fact[n] * inv[n - k] % mod * inv[k] % mod;
        }
    }
}