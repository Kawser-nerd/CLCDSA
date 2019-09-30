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
            StreamReader sr = new StreamReader("F:\\a-large.in");
            StreamWriter sw = new StreamWriter("F:\\a-large.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				String s = sr.ReadLine().TrimEnd(), res = "";
				foreach (char x in s)
				{
					if ((x + res).CompareTo(res + x) > 0)
						res = x + res;
					else
						res = res + x;
				}
				sw.WriteLine("Case #" + Convert.ToString(T) + ": " + res);
            }
            sr.Close();
            sw.Close();
        }
    }
}