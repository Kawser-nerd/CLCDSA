using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Test
{
    class Program
    {
        static int merge2(int x, int y)
        {
            if (x == 1) return y;
            if (y == 1) return x;
            if (x == y) return -1;
            if ((x - 1) % 3 + 2 == y) return 9 - x - y;
            return -(9 - x - y);
        }
        static int merge(int x, int y)
        {
            bool neg = false;
            if (x < 0)
            {
                neg = !neg;
                x = -x;
            }
            if (y < 0)
            {
                neg = !neg;
                y = -y;
            }
            int res = merge2(x, y);
            if (neg) return -res;
            return res;
        }
        static int pw(int x, long y)
        {
            if (y == 0) return 1;
            if (y % 2 == 1) return merge(pw(x, y - 1), x);
            int q = pw(x, y / 2);
            return merge(q, q);
        }
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("D:\\C-large.in");
            StreamWriter sw = new StreamWriter("D:\\c-large.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
                String[] inp = sr.ReadLine().Split(' ');
                int l = Convert.ToInt32(inp[0]);
                long x = Convert.ToInt64(inp[1]);
                String s = sr.ReadLine();
                int[] ch = new int[l];
                for (int i = 0; i < l; i++)
                    if (s[i] == 'i') ch[i] = 2;
                    else
                        if (s[i] == 'j') ch[i] = 3;
                        else
                            if (s[i] == 'k') ch[i] = 4;
                bool flag = true;
                int mul = 1;
                for (int i = 0; i < l; i++)
                    mul = merge(mul, ch[i]);
                if (pw(mul, x) != -1)
                    flag = false;
                if (flag)
                {
                    mul = 1;
                    long pos = -1;
                    for (int i = 0; i < l * Math.Min(4, x); i++)
                    {
                        mul = merge(mul, ch[i % l]);
                        if (mul == 2)
                        {
                            pos = i + 1;
                            break;
                        }
                    }
                    if (pos == -1)
                        flag = false;
                    else
                    {
                        long pos2 = -1;
                        mul = 1;
                        for (int i = 0; i < l * Math.Min(4, x); i++)
                        {
                            mul = merge(ch[l - 1 - i % l], mul);
                            if (mul == 4)
                            {
                                pos2 = l * x - i;
                                break;
                            }
                        }
                        if (pos2 == -1) flag = false;
                        else
                            if (pos >= pos2) flag = false;
                    }
                }
                sw.WriteLine("Case #" + Convert.ToString(T) + ": " + (flag?"YES":"NO"));
            }
            sr.Close();
            sw.Close();
        }
    }
}