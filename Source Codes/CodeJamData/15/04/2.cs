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
            StreamReader sr = new StreamReader("D:\\d-large.in");
            StreamWriter sw = new StreamWriter("D:\\d-large.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
                String[] inp = sr.ReadLine().Split(' ');
                int x = Convert.ToInt32(inp[0]);
                int r = Convert.ToInt32(inp[1]);
                int c = Convert.ToInt32(inp[2]);
                bool flag = true;
                if (r * c % x != 0)
                {
                    flag = false;
                }
                else
                {
                    if (x <= 2) flag = true;
                    if (x == 3)
                    {
                        flag = (r != 1 && c != 1);
                    }
                    if (x == 4)
                    {
                        flag = (r >= 3 && c >= 3);
                    }
                    if (x == 5)
                    {
                        if (r > c)
                        {
                            int t = r;
                            r = c;
                            c = t;
                        }
                        if (r <= 2) flag = false;
                        if (r == 3 && c == 5) flag = false;
                        else
                            if (r == 3) flag = true;
                        if (r >= 4) flag = true;
                    }
                    if (x == 6)
                    {
                        if (r > c)
                        {
                            int t = r;
                            r = c;
                            c = t;
                        }
                        if (r <= 3) flag = false;
                        if (r >= 5) flag = true;
                        if (r == 4) flag = true;
                    }
                    if (x >= 7) flag = false;
                }
                sw.WriteLine("Case #" + Convert.ToString(T) + ": " + (!flag ? "RICHARD" : "GABRIEL"));
            }
            sr.Close();
            sw.Close();
        }
    }
}