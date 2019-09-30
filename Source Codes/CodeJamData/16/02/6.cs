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
            StreamReader sr = new StreamReader("F:\\b.in");
            StreamWriter sw = new StreamWriter("F:\\b.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				String w = sr.ReadLine();
				char prev = '.';
				int res = 0;
				foreach (char x in w)
				{
					if (x != prev)
					{
						prev = x;
						res++;
					}
				}
				if (prev == '+') res--;
                sw.WriteLine("Case #" + Convert.ToString(T) + ": " + Convert.ToString(res));
            }
            sr.Close();
            sw.Close();
        }
    }
}