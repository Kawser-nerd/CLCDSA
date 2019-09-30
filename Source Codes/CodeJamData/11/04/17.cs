using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Goro_Sort {
        public void gen(StreamWriter sw, StreamReader sr) {
            int n = Convert.ToInt32(sr.ReadLine());
            string[] s = sr.ReadLine().Split(new char[] { ' ' });
            int m = 0;
            for (int i = 0; i < n; i++)
                if (Convert.ToInt32(s[i]) != i + 1)
                    m++;
            sw.WriteLine("{0:0.000000}", (double)m);
        }
    }
}
