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
            StreamReader sr = new StreamReader("D:\\a.in");
            StreamWriter sw = new StreamWriter("D:\\a.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
                String w = sr.ReadLine().Split(' ')[1];
                int now = 0, ans = 0;
                for (int i = 0; i < w.Length; i++)
                {
                    for (int j = Convert.ToInt32(w[i]) - Convert.ToInt32('0'); j > 0; j--)
                    {
                        if (now < i)
                        {
                            ans += i - now;
                            now = i;
                        }
                        now++;
                    }
                }
                sw.WriteLine("Case #" + Convert.ToString(T) + ": " + Convert.ToString(ans));
            }
            sr.Close();
            sw.Close();
        }
    }
}