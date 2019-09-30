using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Candy_Splitting {
        public void gen(StreamWriter sw, StreamReader sr) {
            int n = Convert.ToInt32(sr.ReadLine());
            string[] candy = sr.ReadLine().Split(new char[] { ' ' });
            int sum = 0, min = int.MaxValue, xor = 0;
            for (int i = 0; i < n; i++) {
                int c = Convert.ToInt32(candy[i]);
                xor = xor ^ c;
                sum = sum + c;
                min = Math.Min(min, c);
            }
            if (xor != 0)
                sw.WriteLine("NO");
            else
                sw.WriteLine(sum - min);
        }
    }
}
