using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2010
{
    class R1C_A
    {
        public static void Main(String[] args)
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\A.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\A.out"))
                {
                    int cs = int.Parse(sr.ReadLine());
                    for (int ci = 0; ci < cs; ci++)
                    {
                        int n = int.Parse(sr.ReadLine());
                        int[] a = new int[n];
                        int[] b = new int[n];
                        for (int i = 0; i < n; i++)
                        {
                            string[] strs = sr.ReadLine().Split(' ');
                            a[i] = int.Parse(strs[0]);
                            b[i] = int.Parse(strs[1]);
                        }
                        int v = 0;
                        for (int i = 0; i < n; i++)
                        {
                            for (int j = i + 1; j < n; j++)
                            {
                                if (hh(a[i], b[i], a[j], b[j]))
                                {
                                    v++;
                                }
                            }
                        }                        
                        Console.WriteLine("Case #" + (ci + 1) + ": " + v);
                        sw.WriteLine("Case #" + (ci + 1) + ": " + v);
                    }
                }
            }
        }
        static bool hh(int a1, int b1, int a2, int b2)
        {
            if (a1 > a2)
                return hh(a2, b2, a1, b1);
            return b1 > b2;
        }
    }
}
