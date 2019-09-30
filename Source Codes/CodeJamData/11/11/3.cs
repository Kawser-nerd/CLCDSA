using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1a
{
    public class FreeCell
    {
        long n, pd, pg;

        public FreeCell(StreamReader r)
        {
            string[] x = r.ReadLine().Split(' ');
            n = long.Parse(x[0]);
            pd = long.Parse(x[1]);
            pg = long.Parse(x[2]);
        }


        long min(long p)
        {
            for (long i = 1; i < 100; i++)
            {
                if (i * p % 100 == 0) return i; 
            }
            return 100;
        }

        public string solve()
        {
            if (min(pd) > n || pd > 0 && pg == 0 || pd < 100 && pg == 100) return "Broken";
            return "Possible";
        }
    }
}
