using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace EqualSums
{
    class Program
    {
        static int Main(string[] args)
        {
            try
            {
                using (var r = new StreamReader(args[0]))
                {
                    int t = int.Parse(r.ReadLine());
                    for (int i = 1; i <= t; i++)
                    {
                        var p = new Problem(r);
                        string result = p.Solve();
                        Console.WriteLine("Case #{0}:\n{1}", i, result);
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception");
                Console.WriteLine(ex);
                return -1;
            }
            return 0;
        }
    }

    class Problem
    {

        struct Set
        {
            int _n;
            byte[] _s;
            long _sum;
            int _max;


            public Set(int n)
            {
                _n = n;
                int l = (n + 7) >> 3;
                _s = new byte[l];
                int i;
                for (i = 0; i < l; i++)
                    _s[i] = (byte)0;
                _sum = 0;
                _max = -1;
            }

            public Set(int n, long[] values)
                : this(n)
            {
                for (int i = 0; i < values.Length; i++)
                    Add(i, values[i]);
            }

            public Set(Set that)
            {
                _n = that._n;
                int l = (_n + 7) >> 3;
                _s = new byte[l];
                for (int i = 0; i < l; i++)
                    _s[i] = that._s[i];
                _sum = that._sum;
                _max = that._max;
            }

            public long Sum { get { return _sum; } }

            public int Max { get { return _max; } }

            public bool Has(int i)
            {
                int m = 1 << (i & 7);
                return (_s[i >> 3] & m) == m;
            }

            public void Add(int i, long val)
            {
                byte m = (byte)(1 << (i & 7));
                _s[i >> 3] |= m;
                _sum += val;
                if (i > _max)
                    _max = i;
            }            

            public string ToString(long[] values)
            {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < values.Length; i++)
                    if (Has(i))
                        sb.AppendFormat("{0} ", values[i]);
                if (sb.Length > 0)
                    sb.Length = sb.Length - 1;
                return sb.ToString();
            }
        }

        internal static long[] ReadIntArray(StreamReader r)
        {
            var line = r.ReadLine();
            if (line == null)
                return null;
            var sa = line.Split(' ');
            var ia = new long[sa.Length];
            for (int i = 0; i < sa.Length; i++)
                ia[i] = long.Parse(sa[i]);
            return ia;

        }        

        int _n;
        long[] _s;
        Dictionary<long, Set> _sums;

        public Problem(StreamReader r)
        {
            long[] pr = ReadIntArray(r);
            _n = (int)pr[0];
            _s = pr.Skip(1).Take(_n).OrderBy(m => m).ToArray();
            _sums = new Dictionary<long, Set>();
        }



        internal string Solve()
        {
            string result = "Impossible";

            int i;
            List<Set> osl = new List<Set>(_n);

            Set fs = new Set(_n, _s);

            long max = fs.Sum / 2;

            for (i = 0; i < _n; i++)
            {
                Set s = new Set(_n);
                s.Add(i, _s[i]);
                if (s.Sum <= max)
                {
                    osl.Add(s);
                    _sums[s.Sum] = s;
                }
            }

            for (int k = 2; k < _n; k++)
            {
                List<Set> nsl = new List<Set>(osl.Count);                
                foreach (Set os in osl)
                {
                    for (i = os.Max + 1; i < _n; i++)
                    {
                        if (!os.Has(i))
                        {
                            Set ns = new Set(os);
                            ns.Add(i, _s[i]);
                            if (_sums.ContainsKey(ns.Sum))
                            {
                                return string.Format("{0}\n{1}", _sums[ns.Sum].ToString(_s), ns.ToString(_s));
                            }
                            if (ns.Sum <= max)
                            {
                                nsl.Add(ns);
                                _sums[ns.Sum] = ns;
                            }
                        }
                    }
                }
                if (nsl.Count == 0)
                    return result;
                osl = nsl;
            }

            return result;
        }
    }
}
