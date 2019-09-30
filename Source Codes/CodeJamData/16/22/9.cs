using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class C1B
    {

        static void fill(string p, string q, int pos, ref string minp, ref string minq)
        {
            if(pos >= p.Length)
            {
                if(minp.Length==0)
                {
                    minp = p; minq = q;
                }
                else
                {
                    Int64 _mp = Int64.Parse(minp);
                    Int64 _mq = Int64.Parse(minq);
                    Int64 _p = Int64.Parse(p);
                    Int64 _q = Int64.Parse(q);
                    if( Math.Abs(_mp - _mq) > Math.Abs(_p - _q))
                    {
                        minp = p; minq = q;
                    }
                    else if(Math.Abs(_mp - _mq) == Math.Abs(_p - _q))
                    {
                        if (_mp > _p)
                        {
                            minp = p; minq = q;
                        }
                        else if (_mp == _p && _mq > _q)
                        {
                            minp = p; minq = q;
                        }
                    }
                }

                return;
            }

            Int64 curp = (pos==0?0:Int64.Parse(p.Substring(0, pos)));
            Int64 curq = (pos==0?0:Int64.Parse(q.Substring(0, pos)));

            if (p[pos]=='?' && q[pos]=='?')
            {
                if(pos==0)
                {
                    string s = '0' + p.Substring(1);
                    string t = '0' + q.Substring(1);
                    fill(s, t, pos + 1, ref minp, ref minq);

                    s = '1' + p.Substring(1);
                    t = '0' + q.Substring(1);
                    fill(s, t, pos + 1, ref minp, ref minq);
                    s = '0' + p.Substring(1);
                    t = '1' + q.Substring(1);
                    fill(s, t, pos + 1, ref minp, ref minq);
                }
                else
                {
                    if (curp == curq)
                    {
                        string s = p.Substring(0, pos) + '0' + p.Substring(pos + 1);
                        string t = q.Substring(0, pos) + '0' + q.Substring(pos + 1);
                        fill(s, t, pos + 1, ref minp, ref minq);
                        s = p.Substring(0, pos) + '0' + p.Substring(pos + 1);
                        t = q.Substring(0, pos) + '1' + q.Substring(pos + 1);
                        fill(s, t, pos + 1, ref minp, ref minq);
                        s = p.Substring(0, pos) + '1' + p.Substring(pos + 1);
                        t = q.Substring(0, pos) + '0' + q.Substring(pos + 1);
                        fill(s, t, pos + 1, ref minp, ref minq);
                    }
                    else if (curp < curq)
                    {
                        string s = p.Substring(0, pos) + '9' + p.Substring(pos + 1);
                        string t = q.Substring(0, pos) + '0' + q.Substring(pos + 1);
                        fill(s, t, pos + 1, ref minp, ref minq);
                    }
                    else
                    {
                        string s = p.Substring(0, pos) + '0' + p.Substring(pos + 1);
                        string t = q.Substring(0, pos) + '9' + q.Substring(pos + 1);
                        fill(s, t, pos + 1, ref minp, ref minq);
                    }

                }

            }
            else if (p[pos] == '?')
            {
                if( curp < curq )
                {
                    string s = p.Substring(0, pos) + '9' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                }
                else if(curq < curp)
                {
                    string s = p.Substring(0, pos) + '0' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                }
                else if (q[pos] == '0')
                {
                    string s = p.Substring(0, pos) + '0' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                    s = p.Substring(0, pos) + '1' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                    s = p.Substring(0, pos) + '9' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                }
                else if(q[pos]=='9')
                {
                    string s = p.Substring(0, pos) + '8' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                    s = p.Substring(0, pos) + '9' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                    s = p.Substring(0, pos) + '0' + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                }
                else
                {
                    string s = p.Substring(0, pos) + (char)(q[pos]-1) + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                    s = p.Substring(0, pos) + (char)(q[pos]) + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                    s = p.Substring(0, pos) + (char)(q[pos] + 1) + p.Substring(pos + 1);
                    fill(s, q, pos + 1, ref minp, ref minq);
                }
            }
            else if (q[pos] == '?')
            {
                if (curp < curq)
                {
                    string t = q.Substring(0, pos) + '0' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                }
                else if (curq < curp)
                {
                    string t = q.Substring(0, pos) + '9' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                }
                else if (p[pos] == '0')
                {
                    string t = q.Substring(0, pos) + '0' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                    t = q.Substring(0, pos) + '1' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                    t = q.Substring(0, pos) + '9' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                }
                else if (p[pos] == '9')
                {
                    string t = q.Substring(0, pos) + '0' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                    t = q.Substring(0, pos) + '8' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                    t = q.Substring(0, pos) + '9' + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                }
                else
                {
                    string t = q.Substring(0, pos) + (char)(p[pos]-1) + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                    t = q.Substring(0, pos) + (char)(p[pos]) + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                    t = q.Substring(0, pos) + (char)(p[pos]+1) + q.Substring(pos + 1);
                    fill(p, t, pos + 1, ref minp, ref minq);
                }
            }
            else
            {
                fill(p, q, pos + 1, ref minp, ref minq);
            }

            //if (pi < p.Length)
            //{
            //    while (pi < p.Length && p[pi] != '?')
            //        ++pi;
            //    if (pi >= p.Length)
            //    {
            //        fill(p, q, pi, qi, ref minp, ref minq);
            //    }
            //    else
            //    {
            //        for (int i = 0; i < 10; ++i)
            //        {
            //            string s = p.Substring(0, pi) + i.ToString() + p.Substring(pi + 1);
            //            fill(s, q, pi + 1, qi, ref minp, ref minq);
            //        }
            //    }
            //}
            //else if (qi < q.Length)
            //{
            //    while (qi < q.Length && q[qi] != '?')
            //        ++qi;

            //    if (qi == q.Length)
            //    {
            //        fill(p, q, pi, qi, ref minp, ref minq);
            //    }
            //    else
            //    {
            //        for (int i = 0; i < 10; ++i)
            //        {
            //            string s = q.Substring(0, qi) + i.ToString() + q.Substring(qi + 1);
            //            fill(p, s, pi, qi + 1, ref minp, ref minq);
            //        }
            //    }
            //}
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

                string p = s.Substring(0, s.IndexOf(' '));
                string q = s.Substring(s.LastIndexOf(' ') + 1);

                string minp = "", minq = "";
                fill(p, q, 0, ref minp, ref minq);

                Console.Write("Case #" + _i + ": ");
                Console.WriteLine(minp + " " + minq);
                //foreach (var _c in c)
                //{
                //    Console.Write(_c);
                //}
                //Console.WriteLine();

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
