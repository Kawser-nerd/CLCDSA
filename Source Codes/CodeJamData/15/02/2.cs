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
            StreamReader sr = new StreamReader("D:\\b.in");
            StreamWriter sw = new StreamWriter("D:\\b.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
                int n = Convert.ToInt32(sr.ReadLine());
                String[] s = sr.ReadLine().Split(' ');
                int[] a = new int[n];
                int maximum = 0;
                for (int i = 0; i < n; i++)
                {
                    a[i] = Convert.ToInt32(s[i]);
                    if (a[i] > maximum) maximum = a[i];
                }
                int res = maximum;
                for (int w = 1; w < maximum; w++)
                {
                    int tot = w;
                    for (int i = 0; i < n; i++)
                        tot += (a[i]-1)/w;
                    if (tot < res) res = tot;
                }
                sw.WriteLine("Case #" + Convert.ToString(T) + ": " + Convert.ToString(res));
            }
            sr.Close();
            sw.Close();
        }
    }
}