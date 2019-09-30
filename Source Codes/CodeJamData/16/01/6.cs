using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("F:\\a.in");
            StreamWriter sw = new StreamWriter("F:\\a.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				long w = Convert.ToInt64(sr.ReadLine());
				if (w == 0)
				{
					sw.WriteLine("Case #" + Convert.ToString(T) + ": INSOMNIA");
					continue;
				}
				int mask = 0;
				long ans = 0;
				while (true)
				{
					ans += w;
					for (long x = ans; x != 0; x /= 10)
						mask |= 1 << Convert.ToInt32(x % 10);
					if (mask == 1023) break;
				}
                sw.WriteLine("Case #" + Convert.ToString(T) + ": " + Convert.ToString(ans));
            }
            sr.Close();
            sw.Close();
        }
    }
}