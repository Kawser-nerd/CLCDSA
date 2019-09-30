using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        

        static void Go()
        {
            string s = Console.ReadLine();
            int n;
            Int32.TryParse(s, out n);
            for(int _i = 1; _i <= n; ++_i)
            {
                int r;
                //StringBuilder result = new StringBuilder();

                string l1, l2, l3;
                l1 = Console.ReadLine();
                l2 = Console.ReadLine();
                l3 = Console.ReadLine();
                string[] t1 = l1.Split(' ');
                string[] t2 = l2.Split(' ');
                string[] t3 = l3.Split(' ');

                int _n, _l;
                Int32.TryParse(t1[0], out _n);
                Int32.TryParse(t1[1], out _l);

                int flips = Flip(_n, _l, 0, t2, t3);

                if(flips >= 0)
                    Console.WriteLine("Case #{0}: {1}", _i, flips);
                else
                    Console.WriteLine("Case #{0}: NOT POSSIBLE", _i);
            }

        }

        private static int Flip(int _n, int _l, int pos, string[] t2, string[] t3)
        {
            int _12 = 0, _02 = 0, _13 = 0, _03 = 0;
            for (int i = 0; i < _n; ++i)
            {
                if (t2[i][pos] == '0')
                    _02++;
                else
                    _12++;

                if (t3[i][pos] == '0')
                    _03++;
                else
                    _13++;
            }

            if (!(_02 == _03 && _12 == _13)
             && !(_12 == _03 && _02 == _13))
                return -1;

            int f1 = -1, f2 = -1;

            if (_02 == _03 && _12 == _13)
            {
                string[] u2 = t2.Clone() as string[];
                Array.Sort(u2);
                string[] v2 = t3.Clone() as string[];
                Array.Sort(v2);

                bool match = true;

                for(int k=0; k<_n; ++k)
                {
                    if(u2[k].Substring(0,pos+1) != v2[k].Substring(0,pos+1) )
                        match = false;
                }

                if( match )
                {
                    if( _l == pos + 1 )
                        f1 = 0;
                    else
                        f1 = Flip(_n, _l, pos+1, t2, t3);
                }
            }

            if (_12 == _03 && _02 == _13)
            {
                string[] u2 = t2.Clone() as string[];
                string[] v2 = t3.Clone() as string[];

                //flip
                for (int m = 0; m < _n; ++m)
                {
                    var t = new StringBuilder(v2[m]);
                    t[pos] = (t[pos]=='0'?'1':'0');
                    v2[m] = t.ToString();
                }

                Array.Sort(u2);
                Array.Sort(v2);

                bool match = true;

                for (int k = 0; k < _n; ++k)
                {
                    if (u2[k].Substring(0, pos + 1) != v2[k].Substring(0, pos + 1))
                        match = false;
                }

                if (match)
                {
                    if (_l == pos + 1)
                        f2 = 1;
                    else
                    {
                        int ff = Flip(_n, _l, pos + 1, u2, v2);
                        if (ff != -1)
                            f2 = 1 + ff;
                    }
                }
            }

            if (f1 != -1 && f2 != -1)
                return (f1 < f2 ? f1 : f2);
            if (f1 == -1) return f2;
            return f1;
        }

        static void Main(string[] args)
        {
            try
            {
                Go();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.StackTrace);
            }
        }
    }
}
