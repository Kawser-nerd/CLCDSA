using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class C2016_R1A
    {
        static bool fill(int p, bool[] x)
        {
            while (p > 0)
            {
                x[p % 10] = true;
                p /= 10;
            }
            for (int i = 0; i < 10; ++i)
                if (!x[i])
                    return false;
            return true;
        }
        static void flip(byte[] b, int start, int end)
        {
            while (start < end)
            {
                if (b[start] == '+' && b[end] == '+')
                {
                    b[start] = b[end] = (byte)'-';
                }
                else if (b[start] == '-' && b[end] == '+')
                {
                }
                else if (b[start] == '+' && b[end] == '-')
                {
                }
                else if (b[start] == '-' && b[end] == '-')
                {
                    b[start] = b[end] = (byte)'+';
                }
                ++start;
                --end;
            }
            if (start == end)
            {
                if (b[start] == '+')
                    b[start] = (byte)'-';
                else
                    b[start] = (byte)'+';
            }
        }

        static long IntPow(long x, int pow)
        {
            long ret = 1;
            while (pow != 0)
            {
                if ((pow & 1) == 1)
                    ret *= x;
                x *= x;
                pow >>= 1;
            }
            return ret;
        }

        static void Go()
        {
            string s = Console.ReadLine();
            int n;
            Int32.TryParse(s, out n);
            for (int _i = 1; _i <= n; ++_i)
            {
                int r;
                //StringBuilder result = new StringBuilder();
                int k;
                s = Console.ReadLine();
                //Int32.TryParse(s, out k);

                int[] x = new int[26];
                for(int i=0; i<26; ++i)
                {
                    x[i] = 0;
                }
                foreach(var cc in s)
                {
                    ++x[cc - 'A'];
                }

                List<char> c = new List<char>();
                //ZO, ONE, TWO, TH, FOUR, FIV, SIX, SEVE, EIGHT, NINE
                //for(int i=0; i<10; ++i)
                {
                    while (x['Z' - 'A'] > 0) // 0
                    {
                        c.Add('0');
                        --x['Z' - 'A'];
                        --x['E' - 'A'];
                        --x['R' - 'A'];
                        --x['O' - 'A'];
                    }
                    while (x['W' - 'A'] > 0) // 2
                    {
                        c.Add('2');
                        --x['T' - 'A'];
                        --x['W' - 'A'];
                        --x['O' - 'A'];
                    }
                    while (x['X' - 'A'] > 0) // 6
                    {
                        c.Add('6');
                        --x['S' - 'A'];
                        --x['I' - 'A'];
                        --x['X' - 'A'];
                    }
                    while (x['G' - 'A'] > 0) // 8
                    {
                        c.Add('8');
                        --x['E' - 'A'];
                        --x['I' - 'A'];
                        --x['G' - 'A'];
                        --x['H' - 'A'];
                        --x['T' - 'A'];
                    }
                    while (x['S' - 'A'] > 0) // 7
                    {
                        c.Add('7');
                        --x['S' - 'A'];
                        --x['E' - 'A'];
                        --x['V' - 'A'];
                        --x['E' - 'A'];
                        --x['N' - 'A'];
                    }
                    while (x['V' - 'A'] > 0) // 5
                    {
                        c.Add('5');
                        --x['F' - 'A'];
                        --x['I' - 'A'];
                        --x['V' - 'A'];
                        --x['E' - 'A'];
                    }
                    // 0 2 6 8 7 5 -> 1 3 9 4
                    while (x['H' - 'A'] > 0) // 3
                    {
                        c.Add('3');
                        --x['T' - 'A'];
                        --x['H' - 'A'];
                        --x['R' - 'A'];
                        --x['E' - 'A'];
                        --x['E' - 'A'];
                    }
                    while (x['R' - 'A'] > 0) // 4
                    {
                        c.Add('4');
                        --x['F' - 'A'];
                        --x['O' - 'A'];
                        --x['U' - 'A'];
                        --x['R' - 'A'];
                    }
                    while (x['O' - 'A'] > 0) // 1
                    {
                        c.Add('1');
                        --x['O' - 'A'];
                        --x['N' - 'A'];
                        --x['E' - 'A'];
                    }
                    while (x['I' - 'A'] > 0) // 9
                    {
                        c.Add('9');
                        --x['N' - 'A'];
                        --x['I' - 'A'];
                        --x['N' - 'A'];
                        --x['E' - 'A'];
                    }
                }

                c.Sort();

                Console.Write("Case #" + _i + ": ");
                foreach (var _c in c)
                {
                    Console.Write(_c);
                }
                Console.WriteLine();

            }

        }

        static bool can_divide(uint p, int b, int d)
        {
            int rem = 0;
            int l = 1;
            while (p > 0)
            {
                if (p % 2 == 1)
                    rem = (rem + l) % d;
                l = (l * b) % d;
                p = p / 2;
            }
            return (rem % d == 0);
        }

        static bool test_prime(uint p, int[] div)
        {

            int b;
            for (b = 2; b <= 10; ++b) // base b
            {
                int d;
                for (d = 2; d <= 10000; ++d)
                {
                    if (d > 2 && d % 2 == 0)
                        continue;
                    if (d > 3 && d % 3 == 0)
                        continue;
                    if (d > 5 && d % 5 == 0)
                        continue;
                    if (d > 7 && d % 7 == 0)
                        continue;
                    uint q = p;
                    if (can_divide(q, b, d))
                    {
                        div[b] = d;
                        break;
                    }

                }
                if (d > 10000)
                    return false;
            }


            return true;
        }

        static void verify(uint p, int[] div)
        {
            for (int i = 2; i <= 10; ++i)
            {
                Int64 num = 0;
                Int64 pow = 1;
                Int64 q = p;
                while (q > 0)
                {
                    if (q % 2 == 1)
                    {
                        num = (num + pow);
                    }
                    pow = (pow * i) % div[i];
                    q /= 2;
                }
                //Console.WriteLine("base "+ i + " : " + num);
                if (num % div[i] != 0)
                {
                    throw new Exception();
                    //int k = 1;
                }
            }
        }

        static void T()
        {
            Console.WriteLine("Case #1:");
            uint p = 0x80000001; // 32769

            int[] div = new int[11];
            int count = 0;
            do
            {
                if (test_prime(p, div))
                {
                    verify(p, div);
                    byte[] b = new byte[32];
                    uint q = p;
                    for (int i = 31; i >= 0; --i)
                    {
                        b[i] = (byte)((q % 2) + '0');
                        q /= 2;
                    }
                    Console.Write(Encoding.UTF8.GetString(b));
                    for (int i = 2; i <= 10; ++i)
                    {
                        Console.Write(" " + div[i]);
                    }
                    Console.WriteLine();
                    //int i = 1;
                    ++count;
                }

                p += 2;

            } while (count < 500);
        }

        static void Main(string[] args)
        {
            try
            {
                Go();
                //T();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.StackTrace);
            }
        }
    }
}
