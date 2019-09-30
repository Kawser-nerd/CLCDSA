using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class C1C
    {
        class Name
        {
            public string first { get; set;}
            public string second { get; set;}
        }

        static void CheckFake(List<Name> n, int index, HashSet<int> u, ref HashSet<int> h, ref int f)
        {
            if(index >= n.Count)
            {
                if (h.Count > f)
                    f = h.Count;
                return;
            }

            if (n.Count - index + h.Count < f)
                return;

            if( u.Contains(index) )
                CheckFake(n, index + 1, u, ref h, ref f);

            // check if this is unique
            bool foundfirst = false;
            bool foundsecond = false;

            for(int k=0; k< n.Count; ++k)
            {
                if (k == index)
                    continue;
                if (h.Contains(k))
                    continue;
                if (n[k].first == n[index].first)
                    foundfirst = true;
                if (n[k].second == n[index].second)
                    foundsecond = true;
            }

            if( foundfirst && foundsecond )
            {
                h.Add(index);
                if (h.Count > f)
                    f = h.Count;
                CheckFake(n, index + 1, u, ref h, ref f);
                h.Remove(index);
            }
            CheckFake(n, index + 1, u, ref h, ref f);
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
                Int32.TryParse(s, out k);

                List<Name> l = new List<Name>();
                for(int i=0; i< k; ++i)
                {
                    s = Console.ReadLine();
                    string p = s.Substring(0, s.IndexOf(' '));
                    string q = s.Substring(s.LastIndexOf(' ') + 1);
                    Name nn = new Name();
                    nn.first = p;
                    nn.second = q;
                    l.Add(nn);
                }

                HashSet<int> uni = new HashSet<int>();
                for (int i = 0; i < k; ++i)
                {
                    bool same1 = false, same2 = false;
                    for (int j = 0; j < k; ++j)
                    {
                        if (i != j)
                        {
                            if (l[i].first == l[j].first)
                                same1 = true;
                            if (l[i].second == l[j].second)
                                same2 = true;
                        }
                    }
                    if (!same1 || !same2)
                        uni.Add(i);
                }

                int maxfake = 0;
                HashSet<int> hs = new HashSet<int>();

                CheckFake(l, 0, uni, ref hs, ref maxfake);

                //string p = s.Substring(0, s.IndexOf(' '));
                //string q = s.Substring(s.LastIndexOf(' ') + 1);

                //string minp = "", minq = "";
                //fill(p, q, 0, ref minp, ref minq);

                Console.Write("Case #" + _i + ": ");
                Console.WriteLine(maxfake);
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
